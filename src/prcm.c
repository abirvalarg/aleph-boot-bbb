#include "prcm.h"
#include "types.h"

static volatile u32 *const CM_PER = (volatile u32*)0x44E00000;

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
