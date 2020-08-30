/*
 * Frontier Designs Tranzport driver
 *
 * Copyright (C) 2007 Michael Taht (m@taht.net)
 *
 * Based on the usbled driver and ldusb drivers by
 *
 * Copyright (C) 2004 Greg Kroah-Hartman (greg@kroah.com)
 * Copyright (C) 2005 Michael Hund <mhund@ld-didactic.de>
 *
 * The ldusb driver was, in turn, derived from Lego USB Tower driver
 * Copyright (C) 2003 David Glance <advidgsf@sourceforge.net>
 *		 2001-2004 Juergen Stuber <starblue@users.sourceforge.net>
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as
 *	published by the Free Software Foundation, version 2.
 *
 */

/*
 * This driver uses a ring buffer for time critical reading of
 * interrupt in reports and provides read and write methods for
 * raw interrupt reports.
 */

/* Note: this currently uses a dumb ringbuffer for reads and writes.
 * A more optimal driver would cache and kill off outstanding urbs that are
 * now invalid, and ignore ones that already were in the queue but valid
 * as we only have 17 commands for the tranzport. In particular this is
 * key for getting lights to flash in time as otherwise many commands
 * can be buffered up before the light change makes it to the interface.
 */

#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/mutex.h>

#include <linux/uaccess.h>
#include <linux/input.h>
#include <linux/usb.h>
#include <linux/poll.h>

/* Define these values to match your devices */
#define VENDOR_ID   0x165b
#define PRODUCT_ID  0x8101

#ifdef CONFIG_USB_DYNAMIC_MINORS
#define USB_TRANZPORT_MINOR_BASE	0
#else  /* FIXME 177- is the another driver's minor - apply for a minor soon */
#define USB_TRANZPORT_MINOR_BASE	177
#endif

/* table of devices that work with this driver */
static const struct usb_device_id usb_tranzport_table[] = {
	{USB_DEVICE(VENDOR_ID, PRODUCT_ID)},
	{}			/* Terminating entry */
};

MODULE_DEVICE_TABLE(usb, usb_tranzport_table);
MODULE_VERSION("0.35");
MODULE_AUTHOR("Mike Taht <m@taht.net>");
MODULE_DESCRIPTION("Tranzport USB Driver");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("Frontier Designs Tranzport Control Surface");

#define SUPPRESS_EXTRA_OFFLINE_EVENTS 1
#define COMPRESS_WHEEL_EVENTS 1
#define BUFFERED_READS 1
#define RING_BUFFER_SIZE 1000
#define WRITE_BUFFER_SIZE 34
#define TRANZPORT_USB_TIMEOUT 10
#define TRANZPORT_DEBUG 0

static int debug = TRANZPORT_DEBUG;

/* Use our own dbg macro */
#define dbg_info(dev, format, arg...) do			\
	{ if (debug) dev_info(dev , format , ## arg); } while (0)

/* Module parameters */

module_param(debug, int, S_IRUGO | S_IWUSR);
MODULE_PARM_DESC(debug, "Debug enabled or not");

/* All interrupt in transfers are collected in a ring buffer to
 * avoid racing conditions and get better performance of the driver.
 */

static int ring_buffer_size = RING_BUFFER_SIZE;

module_param(ring_buffer_size, int, S_IRUGO);
MODULE_PARM_DESC(ring_buffer_size, "Read ring buffer size in reports");

/* The write_buffer can one day contain more than one interrupt out transfer.
 */
static int write_buffer_size = WRITE_BUFFER_SIZE;
module_param(write_buffer_size, int, S_IRUGO);
MODULE_PARM_DESC(write_buffer_size, "Write buffer size");

/*
 * Increase the interval for debugging purposes.
 * or set to 1 to use the standard interval from the endpoint descriptors.
 */

static int min_interrupt_in_interval = TRANZPORT_USB_TIMEOUT;
module_param(min_interrupt_in_interval, int, 0);
MODULE_PARM_DESC(min_interrupt_in_interval,
		"Minimum interrupt in interval in ms");

static int min_interrupt_out_interval = TRANZPORT_USB_TIMEOUT;
module_param(min_interrupt_out_interval, int, 0);
MODULE_PARM_DESC(min_interrupt_out_interval,
		"Minimum interrupt out interval in ms");

struct tranzport_cmd {
	unsigned char cmd[8];
};

/* Structure to hold all of our device specific stuff */

struct usb_tranzport {
	struct mutex mtx;	/* locks this structure */
	struct usb_interface *intf;	/* save off the usb interface pointer */
	int open_count;		/* number of times this port opened */
	struct tranzport_cmd (*ring_buffer)[RING_BUFFER_SIZE];
	unsigned int ring_head;
	unsigned int ring_tail;
	wait_queue_head_t read_wait;
	wait_queue_head_t write_wait;
	unsigned char *interrupt_in_buffer;
	struct usb_endpoint_descriptor *interrupt_in_endpoint;
	struct urb *interrupt_in_urb;
	int interrupt_in_interval;
	size_t interrupt_in_endpoint_size;
	int interrupt_in_running;
	int interrupt_in_done;
	char *interrupt_out_buffer;
	struct usb_endpoint_descriptor *interrupt_out_endpoint;
	struct urb *interrupt_out_urb;
	int interrupt_out_interval;
	size_t interrupt_out_endpoint_size;
	int interrupt_out_busy;

	/* Sysfs support */

	unsigned char enable;	/* 0 if disabled 1 if enabled */
	unsigned char offline;	/* if the device is out of range or asleep */
	unsigned char compress_wheel;	/* flag to compress wheel events */
};

/* prevent races between open() and disconnect() */
static DEFINE_MUTEX(disconnect_mutex);

static struct usb_driver usb_tranzport_driver;

/**
 *	usb_tranzport_abort_transfers
 *      aborts transfers and frees associated data structures
 */
static void usb_tranzport_abort_transfers(struct usb_tranzport *dev)
{
	/* shutdown transfer */
	if (dev->interrupt_in_running) {
		dev->interrupt_in_running = 0;
		if (dev->intf)
			usb_kill_urb(dev->interrupt_in_urb);
	}
	if (dev->interrupt_out_busy)
		if (dev->intf)
			usb_kill_urb(dev->interrupt_out_urb);
}

#define show_int(value)	\
	static ssize_t show_##value(struct device *dev,	\
			      struct device_attribute *attr, char *buf)	\
	{	\
		struct usb_interface *intf = to_usb_interface(dev);	\
		struct usb_tranzport *t = usb_get_intfdata(intf);	\
		return sprintf(buf, "%d\n", t->value);	\
	}	\
	static DEVICE_ATTR(value, S_IRUGO, show_##value, NULL);

#define show_set_int(value)	\
	static ssize_t show_##value(struct device *dev,	\
			      struct device_attribute *attr, char *buf)	\
	{	\
		struct usb_interface *intf = to_usb_interface(dev);	\
		struct usb_tranzport *t = usb_get_intfdata(intf);	\
		return sprintf(buf, "%d\n", t->value);	\
	}	\
	static ssize_t set_##value(struct device *dev,	\
			     struct device_attribute *attr,		\
			     const char *buf, size_t count)		\
	{	\
		struct usb_interface *intf = to_usb_interface(dev);	\
		struct usb_tranzport *t = usb_get_intfdata(intf);	\
		unsigned long temp;	\
		if (strict_strtoul(buf, 10, &temp))	\
			return -EINVAL;	\
		t->value = temp;	\
		return count;	\
	}	\
	static DEVICE_ATTR(value, S_IWUSR | S_IRUGO, show_##value, set_##value);

show_int(enable);
show_int(offline);
show_set_int(compress_wheel);

/**
 *	usb_tranzport_delete
 */
static void usb_tranzport_delete(struct usb_tranzport *dev)
{
	usb_tranzport_abort_transfers(dev);
	if (dev->intf != NULL) {
		device_remove_file(&dev->intf->dev, &dev_attr_enable);
		device_remove_file(&dev->intf->dev, &dev_attr_offline);
		device_remove_file(&dev->intf->dev, &dev_attr_compress_wheel);
	}

	/* free data structures */
	usb_free_urb(dev->interrupt_in_urb);
	usb_free_urb(dev->interrupt_out_urb);
	kfree(dev->ring_buffer);
	kfree(dev->interrupt_in_buffer);
	kfree(dev->interrupt_out_buffer);
	kfree(dev);
}

/**
 *	usb_tranzport_interrupt_in_callback
 */

static void usb_tranzport_interrupt_in_callback(struct urb *urb)
{
	struct usb_tranzport *dev = urb->context;
	unsigned int next_ring_head;
	int retval = -1;

	if (urb->status) {
		if (urb->status == -ENOENT ||
			urb->status == -ECONNRESET ||
			urb->status == -ESHUTDOWN) {
			goto exit;
		} else {
			dbg_info(&dev->intf->dev,
				 "%s: nonzero status received: %d\n",
				 __func__, urb->status);
			goto resubmit;	/* maybe we can recover */
		}
	}

	if (urb->actual_length != 8) {
		dev_warn(&dev->intf->dev,
			"Urb length was %d bytes!!"
			"Do something intelligent\n",
			 urb->actual_length);
	} else {
		dbg_info(&dev->intf->dev,
			 "%s: received: %02x%02x%02x%02x%02x%02x%02x%02x\n",
			 __func__, dev->interrupt_in_buffer[0],
			 dev->interrupt_in_buffer[1],
			 dev->interrupt_in_buffer[2],
			 dev->interrupt_in_buffer[3],
			 dev->interrupt_in_buffer[4],
			 dev->interrupt_in_buffer[5