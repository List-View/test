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
	{ 0xff178f6, "__aeabi_idivmod" },
	{ 0x311b7963, "_raw_spin_unlock" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0x4257f7e6, "dev_set_drvdata" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0xcbaaea6c, "netif_carrier_on" },
	{ 0x72da8cdc, "skb_clone" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x11f7ed4c, "hex_to_bin" },
	{ 0x8949858b, "schedule_work" },
	{ 0x2a3aa678, "_test_and_clear_bit" },
	{ 0xd4238f1c, "netif_carrier_off" },
	{ 0xb78c61e8, "param_ops_bool" },
	{ 0xe14c755c, "usb_gadget_unregister_driver" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xf9f1ae49, "skb_realloc_headroom" },
	{ 0x7d11c268, "jiffies" },
	{ 0xa0c4d14c, "skb_trim" },
	{ 0xca3a8d76, "netif_rx" },
	{ 0x72aa82c6, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb5c63e4c, "dev_err" },
	{ 0x74c97f9c, "_raw_spin_unlock_irqrestore" },
	{ 0x27e1a049, "printk" },
	{ 0xb385d4cc, "ethtool_op_get_link" },
	{ 0x812ed6c8, "free_netdev" },
	{ 0xb295a386, "register_netdev" },
	{ 0xc212a112, "_raw_spin_unlock_irq" },
	{ 0x73e20c1c, "strlcpy" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0xd4847e16, "skb_push" },
	{ 0xa34f1ef5, "crc32_le" },
	{ 0x89ff43f6, "init_uts_ns" },
	{ 0x5f68ac8, "skb_pull" },
	{ 0xeab5d3a, "dev_kfree_skb_any" },
	{ 0xb7951ef2, "device_create_file" },
	{ 0x24e1307e, "flush_work_sync" },
	{ 0x295f6e04, "skb_queue_tail" },
	{ 0x15a38fd4, "skb_copy_expand" },
	{ 0xc045c476, "_dev_info" },
	{ 0x9f984513, "strrchr" },
	{ 0xbcf83ac5, "kmem_cache_alloc" },
	{ 0x31c2aa7f, "__alloc_skb" },
	{ 0xd59daefe, "_raw_spin_lock_irq" },
	{ 0x6631579c, "eth_type_trans" },
	{ 0xc2161e33, "_raw_spin_lock" },
	{ 0xbd7083bc, "_raw_spin_lock_irqsave" },
	{ 0x36e35242, "eth_validate_addr" },
	{ 0x8d66a3a, "warn_slowpath_fmt" },
	{ 0x6d29c41d, "usb_gadget_probe_driver" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x62a0d669, "skb_dequeue" },
	{ 0xbeac7f79, "dev_warn" },
	{ 0x253c0674, "unregister_netdev" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x2837d1ad, "__netif_schedule" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x8436f8e3, "param_ops_ushort" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x5a7293c0, "skb_put" },
	{ 0x79b4230f, "eth_mac_addr" },
	{ 0xc3fe87c8, "param_ops_uint" },
	{ 0x52797166, "skb_copy_bits" },
	{ 0x8245763f, "dev_get_drvdata" },
	{ 0xb51282cb, "dev_get_stats" },
	{ 0xc661511e, "alloc_etherdev_mqs" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

