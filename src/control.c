#include "control.h"
#include "types.h"

#define CONTROL ((volatile u32*)0x44E10000)

#define VTP_CTRL (0xe0c / 4)
#define DDR_CKE_CTRL (0x131c / 4)
#define DDR_CMD1_IOCTRL (0x1408 / 4)
#define DDR_CMD2_IOCTRL (0x140c / 4)
#define DDR_DATA1_IOCTRL (0x1444 / 4)

void vtp_enable()
{
    CONTROL[VTP_CTRL] |= 1 << 6;
    CONTROL[VTP_CTRL] &= ~1;
    CONTROL[VTP_CTRL] |= 1;
    while((CONTROL[VTP_CTRL] & 1 << 5) == 0);
}

void enable_ddr_cke()
{
    CONTROL[DDR_CKE_CTRL] = 1;
}

void config_ddr_io_ctrl()
{
    CONTROL[DDR_CMD1_IOCTRL] = 0x18b;
    CONTROL[DDR_CMD2_IOCTRL] = 0x18b;
    CONTROL[1410 / 4] = 0x18b;
    CONTROL[DDR_DATA1_IOCTRL] = 0x18b;
    CONTROL[0x1448 / 4] = 0x18b;
}
