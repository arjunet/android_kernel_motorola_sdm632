# ginna: in-tree port of Motorola's out-of-tree focaltech_0flash_mmi (see
# Kconfig). Built =y (never a loadable module) to sidestep this kernel's
# CONFIG_MODULE_SIG_FORCE / CONFIG_MODVERSIONS entirely.
#
# CONFIG_INPUT_TOUCHSCREEN_MMI is intentionally left undefined: every
# touchscreen_mmi-framework call site in focaltech_core.c is already
# #ifdef-guarded, so skipping it drops that whole extra dependency for free.

ccflags-y += -I$(srctree)/$(src) -I$(srctree)/$(src)/focaltech_test
# ginna: TWRP loads focaltech-hlt-ft8006s_aa-*-ginna.bin -> this unit is
# FT8006S_AA (chip id 0x86 0x32), not FT8756. focaltech_test_ft8006sp.c is
# not in this tree, so the self-test module falls back to the ft8756 entry
# (see focaltech_test/focaltech_test.c) - factory test only, unused for touch.
ccflags-y += -DCONFIG_INPUT_FOCALTECH_0FLASH_MMI_IC_NAME_FT8006S_AA

obj-$(CONFIG_TOUCHSCREEN_FOCALTECH_0FLASH_MMI) += focaltech_0flash_mmi.o

focaltech_0flash_mmi-objs += focaltech_core.o
focaltech_0flash_mmi-objs += focaltech_esdcheck.o
focaltech_0flash_mmi-objs += focaltech_ex_fun.o
focaltech_0flash_mmi-objs += focaltech_ex_mode.o
focaltech_0flash_mmi-objs += focaltech_flash.o
focaltech_0flash_mmi-objs += focaltech_gesture.o
focaltech_0flash_mmi-objs += focaltech_point_report_check.o
focaltech_0flash_mmi-objs += focaltech_test/focaltech_test.o
focaltech_0flash_mmi-objs += focaltech_test/focaltech_test_ini.o
focaltech_0flash_mmi-objs += focaltech_test/supported_ic/focaltech_test_ft8756.o
focaltech_0flash_mmi-objs += focaltech_flash_ft8006s.o
focaltech_0flash_mmi-objs += focaltech_spi_v1_1_1.o
