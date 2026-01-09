/*
 * gyro1_drv.c
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#include "../Hdr/gyro1_drv.h"

U8 Gyro1_Pack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1)
{
	U8 packed = 0;

	packed |= (CTRL_REG1->DR & 0x03U) << 6;
	packed |= (CTRL_REG1->BW & 0x03U) << 4;
	packed |= (CTRL_REG1->PD & 1U) << 3;
	packed |= (CTRL_REG1->Zen & 1U) << 2;
	packed |= (CTRL_REG1->Yen & 1U) << 1;
	packed |= (CTRL_REG1->Xen & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1, U8 packed)
{
	CTRL_REG1->DR = (packed >> 6) & 0x03U;
	CTRL_REG1->BW = (packed >> 4) & 0x03U;
	CTRL_REG1->PD = (packed >> 3) & 1U;
	CTRL_REG1->Zen = (packed >> 2) & 1U;
	CTRL_REG1->Yen = (packed >> 1) & 1U;
	CTRL_REG1->Xen = (packed >> 0) & 1U;

}

U8 Gyro1_Pack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2)
{
	U8 packed = 0;

	packed |= (CTRL_REG2->HPM & 0x03U) << 4;
	packed |= (CTRL_REG2->HPCF & 0x0FU) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2, U8 packed)
{
	CTRL_REG2->HPM = (packed >> 4) & 0x03U;
	CTRL_REG2->HPCF = (packed >> 0) & 0x0FU;

}

U8 Gyro1_Pack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3)
{
	U8 packed = 0;

	packed |= (CTRL_REG3->I1_Int1 & 1U) << 7;
	packed |= (CTRL_REG3->I1_Boot & 1U) << 6;
	packed |= (CTRL_REG3->H_Lactive & 1U) << 5;
	packed |= (CTRL_REG3->PP_OD & 1U) << 4;
	packed |= (CTRL_REG3->I2_DRDY & 1U) << 3;
	packed |= (CTRL_REG3->I2_WTM & 1U) << 2;
	packed |= (CTRL_REG3->I2_ORun & 1U) << 1;
	packed |= (CTRL_REG3->I2_Empty & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3, U8 packed)
{
	CTRL_REG3->I1_Int1 = (packed >> 7) & 1U;
	CTRL_REG3->I1_Boot = (packed >> 6) & 1U;
	CTRL_REG3->H_Lactive = (packed >> 5) & 1U;
	CTRL_REG3->PP_OD = (packed >> 4) & 1U;
	CTRL_REG3->I2_DRDY = (packed >> 3) & 1U;
	CTRL_REG3->I2_WTM = (packed >> 2) & 1U;
	CTRL_REG3->I2_ORun = (packed >> 1) & 1U;
	CTRL_REG3->I2_Empty = (packed >> 0) & 1U;

}

U8 Gyro1_Pack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4)
{
	U8 packed = 0;

	packed |= (CTRL_REG4->BLE & 1U) << 6;
	packed |= (CTRL_REG4->FS & 0x03U) << 4;
	packed |= (CTRL_REG4->ST & 0x03U) << 1;
	packed |= (CTRL_REG4->SIM & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4, U8 packed)
{
	CTRL_REG4->BLE = (packed >> 6) & 1U;
	CTRL_REG4->FS = (packed >> 4) & 0x03U;
	CTRL_REG4->ST = (packed >> 1) & 0x03U;
	CTRL_REG4->SIM = (packed >> 0) & 1U;

}

U8 Gyro1_Pack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5)
{
	U8 packed = 0;

	packed |= (CTRL_REG5->BOOT & 1U) << 7;
	packed |= (CTRL_REG5->FIFO_EN & 1U) << 6;
	packed |= (CTRL_REG5->HPen & 1U) << 4;
	packed |= (CTRL_REG5->INT_Sel & 0x03U) << 2;
	packed |= (CTRL_REG5->Out_Sel & 0x03U) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5, U8 packed)
{
	CTRL_REG5->BOOT = (packed >> 7) & 1U;
	CTRL_REG5->FIFO_EN = (packed >> 6) & 1U;
	CTRL_REG5->HPen = (packed >> 4) & 1U;
	CTRL_REG5->INT_Sel = (packed >> 2) & 0x03U;
	CTRL_REG5->Out_Sel = (packed >> 0) & 0x03U;

}

U8 Gyro1_Pack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG)
{
	U8 packed = 0;

	packed |= (STATUS_REG->ZYXOR & 1U) << 7;
	packed |= (STATUS_REG->ZOR & 1U) << 6;
	packed |= (STATUS_REG->YOR & 1U) << 5;
	packed |= (STATUS_REG->XOR & 1U) << 4;
	packed |= (STATUS_REG->ZYXDA & 1U) << 3;
	packed |= (STATUS_REG->ZDA & 1U) << 2;
	packed |= (STATUS_REG->YDA & 1U) << 1;
	packed |= (STATUS_REG->XDA & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG, U8 packed)
{
	STATUS_REG->ZYXOR = (packed >> 7) & 1U;
	STATUS_REG->ZOR = (packed >> 6) & 1U;
	STATUS_REG->YOR = (packed >> 5) & 1U;
	STATUS_REG->XOR = (packed >> 4) & 1U;
	STATUS_REG->ZYXDA = (packed >> 3) & 1U;
	STATUS_REG->ZDA = (packed >> 2) & 1U;
	STATUS_REG->YDA = (packed >> 1) & 1U;
	STATUS_REG->XDA = (packed >> 0) & 1U;

}

U8 Gyro1_Pack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG)
{
	U8 packed = 0;

	packed |= (FIFO_CTRL_REG->FM & 0x07) << 5;
	packed |= (FIFO_CTRL_REG->WTM & 0x1F) << 0;

	return packed;
}

void Gyro1_Unpack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG, U8 packed)
{
	FIFO_CTRL_REG->FM = (packed >> 5) & 0x07;
	FIFO_CTRL_REG->WTM = (packed >> 0) & 0x1F;

}

U8 Gyro1_Pack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG)
{
	U8 packed = 0;

	packed |= (FIFO_SRC_REG->WTM & 1U) << 7;
	packed |= (FIFO_SRC_REG->OVRN & 1U) << 6;
	packed |= (FIFO_SRC_REG->EMPTY & 1U) << 5;
	packed |= (FIFO_SRC_REG->FSS & 0x1F) << 0;

	return packed;
}

void Gyro1_Unpack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG, U8 packed)
{
	FIFO_SRC_REG->WTM = (packed >> 7) & 1U;
	FIFO_SRC_REG->OVRN = (packed >> 6) & 1U;
	FIFO_SRC_REG->EMPTY = (packed >> 5) & 1U;
	FIFO_SRC_REG->FSS = (packed >> 0) & 0x1F;

}

U8 Gyro1_Pack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG)
{
	U8 packed = 0;

	packed |= (INT1_CFG->AND_OR & 1U) << 7;
	packed |= (INT1_CFG->LIR & 1U) << 6;
	packed |= (INT1_CFG->ZHIE & 1U) << 5;
	packed |= (INT1_CFG->ZLIE & 1U) << 4;
	packed |= (INT1_CFG->YHIE & 1U) << 3;
	packed |= (INT1_CFG->YLIE & 1U) << 2;
	packed |= (INT1_CFG->XHIE & 1U) << 1;
	packed |= (INT1_CFG->XLIE & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG, U8 packed)
{
	INT1_CFG->AND_OR = (packed >> 7) & 1U;
	INT1_CFG->LIR = (packed >> 6) & 1U;
	INT1_CFG->ZHIE = (packed >> 5) & 1U;
	INT1_CFG->ZLIE = (packed >> 4) & 1U;
	INT1_CFG->YHIE = (packed >> 3) & 1U;
	INT1_CFG->YLIE = (packed >> 2) & 1U;
	INT1_CFG->XHIE = (packed >> 1) & 1U;
	INT1_CFG->XLIE = (packed >> 0) & 1U;

}

U8 Gyro1_Pack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC)
{
	U8 packed = 0;

	packed |= (INT1_SRC->IA & 1U) << 6;
	packed |= (INT1_SRC->ZH & 1U) << 5;
	packed |= (INT1_SRC->ZL & 1U) << 4;
	packed |= (INT1_SRC->YH & 1U) << 3;
	packed |= (INT1_SRC->YL & 1U) << 2;
	packed |= (INT1_SRC->XH & 1U) << 1;
	packed |= (INT1_SRC->XL & 1U) << 0;

	return packed;
}

void Gyro1_Unpack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC, U8 packed)
{
	INT1_SRC->IA = (packed >> 6) & 1U;
	INT1_SRC->ZH = (packed >> 5) & 1U;
	INT1_SRC->ZL = (packed >> 4) & 1U;
	INT1_SRC->YH = (packed >> 3) & 1U;
	INT1_SRC->YL = (packed >> 2) & 1U;
	INT1_SRC->XH = (packed >> 1) & 1U;
	INT1_SRC->XL = (packed >> 0) & 1U;

}

uint16_t Gyro1_Read(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg)
{
	SPI_Write(pGyro1_Handle->pSPI_Handle, device_reg);

	return(SPI_Read(pGyro1_Handle->pSPI_Handle));

}

U8 Gyro1_Write(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg, uint16_t value)
{
	SPI_Write(pGyro1_Handle->pSPI_Handle, device_reg);
	SPI_Write(pGyro1_Handle->pSPI_Handle, value);

	SPI_Write(pGyro1_Handle->pSPI_Handle, device_reg);
	return(value == SPI_Read(pGyro1_Handle->pSPI_Handle));
}

U8 Gyro1_ReadFIFO(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg, int16_t *buf)
{
    U8 samples = (U8)Gyro1_Read(pGyro1_Handle, device_reg) & 0x1F; // 0b 0001 1111 Lower 5 bits = sample count

    for (U8 i = 0; i < samples; i++)
    {
        U8 raw[6];
        Gyro1_BurstRead(pGyro1_Handle, OUT_X_L_ADDR | 0xC0, raw, 6);
        // Read 6 bytes (X_L, X_H, Y_L, Y_H, Z_L, Z_H) with auto-increment (bits 5, 6 = 1) --> 0xC0 = 0b1100 0000
        // Refer to section 3.2.4 from gyro datasheet

        buf[i * 3 + 0] = (int16_t)((raw[1] << 8) | raw[0]); // X axis reading
        buf[i * 3 + 1] = (int16_t)((raw[3] << 8) | raw[2]); // Y axis reading
        buf[i * 3 + 2] = (int16_t)((raw[5] << 8) | raw[4]); // Z axis reading
        // Shifting *_H byte by 8 bits to the left converts it from an 8 to 16 bit int
        // For e.g. if X_H = 11111111, then it becomes 11111111 00000000 with an 8 bit shift to the left
        // Then the operation of X_H | X_L places the contents of the X_L into the lower 8 bits and creates a 16 bit X reading
    }
	return 0;
}

void Gyro1_BurstRead(Gyro1Handle_st* pGyro1_Handle, U8 device_reg, U8 *data, U8 len)
{
	SPI_Write(pGyro1_Handle->pSPI_Handle, device_reg);

    for (U8 i = 0; i < len; i++)
    {
        data[i] = (U8)SPI_Read(pGyro1_Handle->pSPI_Handle);
    }

}

U8 Gyro1_ErrCheck(Gyro1Handle_st* pGyro1_Handle, U8 device_reg)
{
	Gyro1_Read(pGyro1_Handle, device_reg);

	return 0;
}
