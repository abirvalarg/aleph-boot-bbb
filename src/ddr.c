#include "ddr.h"
#include "types.h"

// static volatile u32 *const DDR_PHY = (volatile u32*)0x44E12000;
#define DDR_PHY ((volatile u32*)0x44E12000)

#define CMD0_REG_PHY_CTRL_SLAVE_RATIO_0 (0x1c / 4)
#define CMD0_REG_PHY_DLL_LOCK_DIFF_0 (0x28 / 4)
#define CMD0_REG_PHY_INVERT_CLKOUT_0 (0x2c / 4)
#define DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0 (0xc8 / 4)
#define DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0 (0xdc / 4)
#define DATA0_REG_PHY_WRLVL_INIT_RATIO_0 (0xf0 / 4)
#define DATA0_REG_PHY_GATELVL_INIT_RATIO_0 (0xfc / 4)
#define DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0 (0x108 / 4)
#define DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0 (0x120 / 4)
#define DATA0_REG_PHY_USE_RANK0_DELAYS (0x134 / 4)
#define DATA0_REG_PHY_DLL_LOCK_DIFF_0 (0x138 / 4)
#define DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_0 (0x16c / 4)
#define DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_0 (0x180 / 4)
#define DATA1_REG_PHY_WRLVL_INIT_RATIO_0 (0x194 / 4)
#define DATA1_REG_PHY_GATELVL_INIT_RATIO_0 (0x1a0 / 4)
#define DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_0 (0x1ac / 4)
#define DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_0 (0x1c4 / 4)
#define DATA1_REG_PHY_USE_RANK0_DELAYS (0x1d8 / 4)
#define DATA1_REG_PHY_DLL_LOCK_DIFF_0 (0x1dc / 4)

void phy_config_cmd()
{
    for(int i = 0; i < 3; i++)
    {
        DDR_PHY[CMD0_REG_PHY_CTRL_SLAVE_RATIO_0 + i * 0x34 / 4] = 0x80;
        DDR_PHY[CMD0_REG_PHY_DLL_LOCK_DIFF_0 + i * 0x34 / 4] = 1;
        DDR_PHY[CMD0_REG_PHY_INVERT_CLKOUT_0 + i * 0x34 / 4] = 0;
    }
}

void phy_config_data()
{
    DDR_PHY[DATA0_REG_PHY_RD_DQS_SLAVE_RATIO_0] = 0x38;
    DDR_PHY[DATA0_REG_PHY_WR_DQS_SLAVE_RATIO_0] = 0x44;
    DDR_PHY[DATA0_REG_PHY_WRLVL_INIT_RATIO_0] = 0;
    DDR_PHY[DATA0_REG_PHY_GATELVL_INIT_RATIO_0] = 0;
    DDR_PHY[DATA0_REG_PHY_FIFO_WE_SLAVE_RATIO_0] = 0X94;
    DDR_PHY[DATA0_REG_PHY_WR_DATA_SLAVE_RATIO_0] = 0x7d;
    DDR_PHY[DATA0_REG_PHY_USE_RANK0_DELAYS] = 0;
    DDR_PHY[DATA0_REG_PHY_DLL_LOCK_DIFF_0] = 0;

    DDR_PHY[DATA1_REG_PHY_RD_DQS_SLAVE_RATIO_0] = 0x38;
    DDR_PHY[DATA1_REG_PHY_WR_DQS_SLAVE_RATIO_0] = 0x44;
    DDR_PHY[DATA1_REG_PHY_WRLVL_INIT_RATIO_0] = 0;
    DDR_PHY[DATA1_REG_PHY_GATELVL_INIT_RATIO_0] = 0;
    DDR_PHY[DATA1_REG_PHY_FIFO_WE_SLAVE_RATIO_0] = 0X94;
    DDR_PHY[DATA1_REG_PHY_WR_DATA_SLAVE_RATIO_0] = 0x7d;
    DDR_PHY[DATA1_REG_PHY_USE_RANK0_DELAYS] = 0;
    DDR_PHY[DATA1_REG_PHY_DLL_LOCK_DIFF_0] = 0;
}