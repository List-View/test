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
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0x3ec8886f, "param_ops_int" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0x4257f7e6, "dev_set_drvdata" },
	{ 0x3f59bc9f, "snd_pcm_lib_write" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x8949858b, "schedule_work" },
	{ 0x2bd06862, "filp_close" },
	{ 0xe14c755c, "usb_gadget_unregister_driver" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x72aa82c6, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb5c63e4c, "dev_err" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0xc212a112, "_raw_spin_unlock_irq" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x89ff43f6, "init_uts_ns" },
	{ 0xb7951ef2, "device_create_file" },
	{ 0xc045c476, "_dev_info" },
	{ 0x9f984513, "strrchr" },
	{ 0xbcf83ac5, "kmem_cache_alloc" },
	{ 0xd59daefe, "_raw_spin_lock_irq" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x8d66a3a, "warn_slowpath_fmt" },
	{ 0x6d29c41d, "usb_gadget_probe_driver" },
	{ 0x4cda566, "snd_interval_refine" },
	{ 0x37a0cba, "kfree" },
	{ 0x283dfe3, "_snd_pcm_hw_params_any" },
	{ 0x9d669763, "memcpy" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xf284ee9b, "snd_pcm_kernel_ioctl" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x8436f8e3, "param_ops_ushort" },
	{ 0x8245763f, "dev_get_drvdata" },
	{ 0xe12c7112, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

