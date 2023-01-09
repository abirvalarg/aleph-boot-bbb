#include "prcm.h"
#include "gpio.h"
#include "emif.h"

#define TEST_ADDR 0x80000000
#define TEST_VALUE 0xaa55aa55

static int test_memory();

__attribute__((noreturn))
void reset()
{
    prcm_per_enable(PRCM_PER_MODULE_GPIO1);
    gpio_pin_mode(1, 21, GPIO_OUTPUT);
    gpio_pin_mode(1, 22, GPIO_OUTPUT);
    gpio_pin_mode(1, 23, GPIO_OUTPUT);
    gpio_pin_mode(1, 24, GPIO_OUTPUT);
    gpio_pin_write(1, 21, 1);

    config_ddr_pll(23, 400, 1);

    emif_ddr3_config();

    gpio_pin_write(1, 22, 1);

    if(!test_memory())
    {
        gpio_pin_write(1, 24, 1);
        while(1);
    }

    gpio_pin_write(1, 23, 1);

    while(1);
}

static int test_memory()
{
    volatile u32 *test_cell = (volatile u32*)TEST_ADDR;
    test_cell[0] = TEST_VALUE;
    test_cell[1] = ~TEST_VALUE;
    for(int i = 0; i < 10000000; i++)
        asm("nop");
    return test_cell[0] == TEST_VALUE && test_cell[1] == ~TEST_VALUE;
}
