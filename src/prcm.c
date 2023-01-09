#include "prcm.h"
#include "types.h"

static volatile u32 *const CM_PER = (volatile u32*)0x44E00000;
static volatile u32 *const CM_WKUP = (volatile u32*)0x44E00400;

// CM_WKUP
static const u32 CM_IDLEST_DPLL_DDR = 0x34 / 4;
static const u32 CM_CLKSEL_DPLL_DDR = 0x40 / 4;
static const u32 CM_CLKMODE_DPLL_DDR = 0x94 / 4;
static const u32 CM_DIV_M2_DPLL_DDR = 0xa0 / 4;

void prcm_per_enable(PrcmPerModule module)
{
    u32 clkctrl = CM_PER[module];
    clkctrl &= 0b11;
    clkctrl |= 2;
    CM_PER[module] = clkctrl;
}

PrcmIdlest prcm_per_idlest(PrcmPerModule module)
{
    u32 clkctrl = CM_PER[module];
    return (clkctrl >> 16) & 0b11;
}

void config_ddr_pll(u32 div, u32 mul, u32 m2)
{
    volatile u32 *clkmode_reg = CM_WKUP + CM_CLKMODE_DPLL_DDR;
    u32 clkmode = *clkmode_reg & ~(7);
    *clkmode_reg = clkmode | 4;

    volatile u32 *idlest_reg = CM_WKUP + CM_IDLEST_DPLL_DDR;
    while((*idlest_reg & 1 << 8) == 0);

    volatile u32 *clksel_reg = CM_WKUP + CM_CLKSEL_DPLL_DDR;
    *clksel_reg = (mul & 0x7ff) << 8 | (div & 0x7f);

    volatile u32 *m2_reg = CM_WKUP + CM_DIV_M2_DPLL_DDR;
    *m2_reg = m2 & 0x1f;

    *clkmode_reg = clkmode | 7;
    while((*idlest_reg & 1) == 0);
}
