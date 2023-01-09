#include "emif.h"
#include "prcm.h"
#include "control.h"
#include "ddr.h"

#define EMIF ((volatile u32*)0x4C000000)

#define SDRAM_CONFIG (0x8 / 4)
#define SDRAM_REF_CTRL (0x10 / 4)
#define SDRAM_TIM_1 (0x18 / 4)
#define SDRAM_TIM_2 (0x20 / 4)
#define SDRAM_TIM_3 (0x28 / 4)
#define ZQ_CONFIG (0xc8 / 4)
#define DDR_PHY_CTRL_1 (0xe4 / 4)
#define DDR_PHY_CTRL_2 (0xec / 4)

void emif_ddr3_config()
{
    prcm_per_enable(PRCM_PER_MODULE_EMIF);

    vtp_enable();

    phy_config_cmd();
    phy_config_data();

    config_ddr_io_ctrl();

    enable_ddr_cke();

    EMIF[DDR_PHY_CTRL_1] = 0x100007;
    EMIF[DDR_PHY_CTRL_2] = 0;

    EMIF[SDRAM_TIM_1] = 0x0aaad4db;

    EMIF[SDRAM_TIM_2] = 0x266b7fda;

    EMIF[SDRAM_TIM_3] = 0x501f867f;

    EMIF[SDRAM_REF_CTRL] = 0x2800;
    EMIF[ZQ_CONFIG] = 0x50074be4;
    EMIF[SDRAM_CONFIG] = 0x61c05332;

    EMIF[SDRAM_REF_CTRL] = 0xc30;
}
