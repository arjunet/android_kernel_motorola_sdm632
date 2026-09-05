# ginna: in-tree port of Motorola's out-of-tree chipone_tddi_mmi, revision
# v1.2.6 from branch MMI-QPG30.82-135 (commit "Gin: 3rd panel new TP ICNL9911C
# bringup") - the exact revision the working prebuilt vendor .ko was built from.
# The device's stock .ko is 32-bit ARM and can't load into this 64-bit kernel,
# so it's rebuilt from source here, =y (never a loadable module) to sidestep
# CONFIG_MODULE_SIG_FORCE / CONFIG_MODVERSIONS.
#
# v1.2.8 (Motorola's android-10-release-qzk) was tried first and failed at
# "Enter program mode failed -14"; v1.2.8 had turned off
# CFG_CTS_FW_UPDATE_FILE_LOAD / CFG_CTS_DRIVER_BUILTIN_FIRMWARE and rewrote the
# probe/hw-id path. v1.2.6 keeps the firmware-from-/vendor/firmware flow that
# matches the .bin files shipped on this device.

ccflags-y += -I$(srctree)/$(src)
# ginna DEBUG: dump every SPI transfer (tx bytes, rx bytes, speed/mode/cs,
# spi_sync ret) to the kernel log, and poison the rx buffer beforehand so we
# can tell whether the transfer actually wrote it. Remove this line once the
# ChipOne probe is understood.
ccflags-y += -DCTS_DEBUG_SPI_DUMP

obj-$(CONFIG_TOUCHSCREEN_CHIPONE_TDDI_MMI) += chipone_tddi_mmi.o

chipone_tddi_mmi-objs += cts_i2c_driver.o
chipone_tddi_mmi-objs += cts_core.o
chipone_tddi_mmi-objs += cts_platform.o
chipone_tddi_mmi-objs += cts_sfctrlv2.o
chipone_tddi_mmi-objs += cts_spi_flash.o
chipone_tddi_mmi-objs += cts_firmware.o
chipone_tddi_mmi-objs += cts_tool.o
chipone_tddi_mmi-objs += cts_sysfs.o
chipone_tddi_mmi-objs += cts_test.o
