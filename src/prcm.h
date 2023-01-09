#pragma once
#include "types.h"

typedef enum PrcmPerModule
{
    PRCM_PER_MODULE_EMIF = 0x28 / 4,
    PRCM_PER_MODULE_GPIO1 = 0xac / 4
} PrcmPerModule;

typedef enum PrcmIdlest
{
    PRCM_IDLEST_FUNC = 0,
    PRCM_IDLEST_TRANS = 1,
    PRCM_IDLEST_IDLE = 2,
    PRCM_IDLEST_DISABLE = 3
} PrcmIdlest;

void prcm_per_enable(PrcmPerModule module);
PrcmIdlest prcm_per_idlest(PrcmPerModule module);
void config_ddr_pll(u32 div, u32 mul, u32 m2);
