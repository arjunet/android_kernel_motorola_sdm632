/*
 * ginna: minimal stub for FT8006S_AA (test_func_ft8006sp).
 *
 * Motorola's focaltech_test_ft8006sp.c (the factory raw-data / short / open
 * self-test implementation for FT8006S_AA) was never carried into this tree.
 * focaltech_test.c unconditionally references &test_func_ft8006sp when built
 * with CONFIG_INPUT_FOCALTECH_0FLASH_MMI_IC_NAME_FT8006S_AA, so provide a
 * stub: it lets the driver link and probe, and only the sysfs-triggered
 * factory self-test is unavailable (returns -ENOSYS). Touch operation does
 * not use this path - fts_test_init() failure is non-fatal in focaltech_core.c.
 *
 * ctype {0x19} matches struct ft_chip_t.type for FT8006S_AA
 * (FTS_CHIP_TYPE_MAPPING in focaltech_common.h).
 */

#include <linux/errno.h>
#include "../focaltech_test.h"

static int start_test_ft8006sp(void)
{
	FTS_TEST_ERROR("FT8006S_AA factory self-test not implemented on ginna");
	return -ENOSYS;
}

struct test_funcs test_func_ft8006sp = {
	.ctype = {0x19},
	.hwtype = IC_HW_INCELL,
	.key_num_total = 0,
	.start_test = start_test_ft8006sp,
};
