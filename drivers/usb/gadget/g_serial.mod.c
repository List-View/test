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
	{ 0x5dd82feb, "device_remove_file" },
	{ 0xb48a77ef, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0x4257f7e6, "dev_set_drvdata" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xbbd17b1a, "alloc_tty_driver" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x82cc7e43, "tty_register_driver" },
	{ 0xb78c61e8, "param_ops_bool" },
	{ 0xb7ddbd6, "mutex_unlock" },
	{ 0xfa59fa25, "put_tty_driver" },
	{ 0xe14c755c, "usb_gadget_unregister_driver" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x35c1bcf0, "tty_set_operations" },
	{ 0x41e92619, "__init_waitqueue_head" },
	{ 0x72aa82c6, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb5c63e4c, "dev_err" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0xeac5046c, "__mutex_init" },
	{ 0x27e1a049, "printk" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0xc212a112, "_raw_spin_unlock_irq" },
	{ 0xb59ffb54, "tty_insert_flip_string_fixed_flag" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x7f14cbec, "mutex_lock" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0x89ff43f6, "init_uts_ns" },
	{ 0xce8b4e69, "tty_register_device" },
	{ 0x82072614, "tasklet_kill" },
	{ 0xb7951ef2, "device_create_file" },
	{ 0x8e1f1bf, "tty_unregister_device" },
	{ 0xc045c476, "_dev_info" },
	{ 0x9f984513, "strrchr" },
	{ 0xbcf83ac5, "kmem_cache_alloc" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd59daefe, "_raw_spin_lock_irq" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x967e3ab6, "tty_unregister_driver" },
	{ 0x20939864, "tty_hangup" },
	{ 0x72542c85, "__wake_up" },
	{ 0x8d66a3a, "warn_slowpath_fmt" },
	{ 0x6d29c41d, "usb_gadget_probe_driver" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x32f80ea9, "prepare_to_wait" },
	{ 0xf83178bd, "finish_wait" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0x8c59527b, "tty_flip_buffer_push" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x701d0ebd, "snprintf" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x8436f8e3, "param_ops_ushort" },
	{ 0x5742a97, "tty_wakeup" },
	{ 0xc3fe87c8, "param_ops_uint" },
	{ 0x8245763f, "dev_get_drvdata" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

