#include "gpio.h"

volatile u32 *GPIO_CTLS[NUM_GPIO] = {
    (volatile u32*)0x44E07000,
    (volatile u32*)0x4804C000
};

static const u32 GPIO_OE = 0x134 / 4;
static const u32 GPIO_DATAOUT = 0x13c / 4;

void gpio_pin_mode(int ctl, int pin, GpioPinMode mode)
{
    volatile u32 *reg = GPIO_CTLS[ctl];
    u32 val = reg[GPIO_OE] & ~(1 << pin);
    reg[GPIO_OE] = val | mode << pin;
}

void gpio_pin_write(int ctl, int pin, int state)
{
    volatile u32 *reg = GPIO_CTLS[ctl];
    u32 val = reg[GPIO_DATAOUT] & ~(1 << pin);
    reg[GPIO_DATAOUT] = val | (!!state) << pin;
}
