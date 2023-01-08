#include <prcm.h>

__attribute__((noreturn))
void reset()
{
    if(prcm_per_idlest(PRCM_PER_MODULE_GPIO1) == PRCM_IDLEST_DISABLE)
        prcm_per_enable(PRCM_PER_MODULE_GPIO1);
    while(1);
}
