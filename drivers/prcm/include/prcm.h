#pragma once

typedef enum PrcmPerModule
{
    PRCM_PER_MODULE_GPIO1 = 0xac
} PrcmPerModule;

void prcm_enable_per(PrcmPerModule module);
