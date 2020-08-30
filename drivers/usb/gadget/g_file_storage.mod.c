#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xb76c596d, "module_layout" },
	{ 0x1fdd4011, "d_path" },
	{ 0x5dd82feb, "device_remove_file" },
	{ 0xb48a77ef, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xd5b037e1, "kref_put" },
	{ 0xd4fab16, "complete_and_exit" },
	{ 0x85b87d7c, "up_read" },
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0xa73c9b56, "dequeue_signal" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0x4257f7e6, "dev_set_drvdata" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x2a3aa678, "_test_and_clear_bit" },
	{ 0x2bd06862, "filp_close" },
	{ 0xb78c61e8, "param_ops_bool" },
	{ 0xbd4d4d, "vfs_fsync" },
	{ 0xe14c755c, "usb_gadget_unregister_driver" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xe33ad6ce, "kthread_create_on_node" },
	{ 0x1907c2a2, "down_read" },
	{ 0x41e92619, "__init_waitqueue_head" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x2fd61cd, "wait_for_completion" },
	{ 0x72aa82c6, "param_ops_charp" },
	{ 0xfe2856e, "vfs_read" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x27bacea5, "device_register" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb5c63e4c, "dev_err" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0xc212a112, "_raw_spin_unlock_irq" },
	{ 0x89ff43f6, "init_uts_ns" },
	{ 0x527ecf54, "up_write" },
	{ 0x33898f38, "down_write" },
	{ 0xdbed7c62, "fput" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0xb7951ef2, "device_create_file" },
	{ 0xc045c476, "_dev_info" },
	{ 0x9f984513, "strrchr" },
	{ 0xbcf83ac5, "kmem_cache_alloc" },
	{ 0x962aa0de, "put_device" },
	{ 0x1000e51, "schedule" },
	{ 0x35c2ba9e, "refrigerator" },
	{ 0xd59daefe, "_raw_spin_lock_irq" },
	{ 0xfde1ca8d, "wake_up_process" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x6d29c41d, "usb_gadget_probe_driver" },
	{ 0x83800bfa, "kref_init" },
	{ 0x37a0cba, "kfree" },
	{ 0xa46f2f1b, "kstrtouint" },
	{ 0x9d669763, "memcpy" },
	{ 0xf59f197, "param_array_ops" },
	{ 0xcba051ca, "send_sig_info" },
	{ 0x9775cdc, "kref_get" },
	{ 0x81dc6e9a, "invalidate_mapping_pages" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0x9771c9c2, "device_unregister" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x4f7f2d1b, "complete" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x99bb8806, "memmove" },
	{ 0x8c1e998, "dev_set_name" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0xc3fe87c8, "param_ops_uint" },
	{ 0x8245763f, "dev_get_drvdata" },
	{ 0x5c4d8bf, "__init_rwsem" },
	{ 0xf0e34e33, "vfs_write" },
	{ 0xe12c7112, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

