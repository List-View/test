cmd_sound/soc/imx/hdmi_pcm.o := /home/list_view/tmp/fsl-linaro-toolchain/bin/arm-fsl-linux-gnueabi-gcc -Wp,-MD,sound/soc/imx/.hdmi_pcm.o.d  -nostdinc -isystem /home/list_view/tmp/fsl-linaro-toolchain/bin/../lib/gcc/arm-fsl-linux-gnueabi/4.6.2/include -I/home/list_view/tmp/linux-imx/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-mx6/include -Iarch/arm/plat-mxc/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float       -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp   -c -o sound/soc/imx/hdmi_pcm.o sound/soc/imx/hdmi_pcm.S

source_sound/soc/imx/hdmi_pcm.o := sound/soc/imx/hdmi_pcm.S

deps_sound/soc/imx/hdmi_pcm.o := \
  /home/list_view/tmp/linux-imx/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \

sound/soc/imx/hdmi_pcm.o: $(deps_sound/soc/imx/hdmi_pcm.o)

$(deps_sound/soc/imx/hdmi_pcm.o):
