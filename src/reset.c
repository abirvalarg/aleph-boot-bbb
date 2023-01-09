#include "prcm.h"
#include "gpio.h"

__attribute__((noreturn))
void reset()
{
    prcm_per_enable(PRCM_PER_MODULE_GPIO1);
    gpio_pin_mode(1, 21, GPIO_OUTPUT);
    gpio_pin_write(1, 21, 1);
    while(1);
}
