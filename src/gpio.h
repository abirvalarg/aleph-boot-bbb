#pragma once
#include "types.h"

#define NUM_GPIO 2

extern volatile u32 *GPIO_CTLS[NUM_GPIO];

typedef enum GpioPinMode
{
    GPIO_OUTPUT = 0,
    GPIO_INPUT = 1
} GpioPinMode;

void gpio_pin_mode(int ctl, int pin, GpioPinMode mode);
void gpio_pin_write(int ctl, int pin, int state);
