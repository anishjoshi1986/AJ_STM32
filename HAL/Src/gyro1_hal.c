/*
 * gyroI3G4250_hal.c
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#include "../Hdr/gyro1_hal.h"

uint8_t Gyro1_Pack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1)
{
	uint8_t packed = 0;

	packed |= (CTRL_REG1->DR & 0x03) << 6;
	packed |= (CTRL_REG1->BW & 0x03) << 4;
	packed |= (CTRL_REG1->PD & 0x01) << 3;
	packed |= (CTRL_REG1->Zen & 0x01) << 2;
	packed |= (CTRL_REG1->Yen & 0x01) << 1;
	packed |= (CTRL_REG1->Xen & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1, uint8_t packed)
{
	CTRL_REG1->DR = (packed >> 6) & 0x03;
	CTRL_REG1->BW = (packed >> 4) & 0x03;
	CTRL_REG1->PD = (packed >> 3) & 0x01;
	CTRL_REG1->Zen = (packed >> 2) & 0x01;
	CTRL_REG1->Yen = (packed >> 1) & 0x01;
	CTRL_REG1->Xen = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2)
{
	uint8_t packed = 0;

	packed |= (CTRL_REG2->HPM & 0x03) << 4;
	packed |= (CTRL_REG2->HPCF & 0x0F) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2, uint8_t packed)
{
	CTRL_REG2->HPM = (packed >> 4) & 0x03;
	CTRL_REG2->HPCF = (packed >> 0) & 0x0F;

}

uint8_t Gyro1_Pack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3)
{
	uint8_t packed = 0;

	packed |= (CTRL_REG3->I1_Int1 & 0x01) << 7;
	packed |= (CTRL_REG3->I1_Boot & 0x01) << 6;
	packed |= (CTRL_REG3->H_Lactive & 0x01) << 5;
	packed |= (CTRL_REG3->PP_OD & 0x01) << 4;
	packed |= (CTRL_REG3->I2_DRDY & 0x01) << 3;
	packed |= (CTRL_REG3->I2_WTM & 0x01) << 2;
	packed |= (CTRL_REG3->I2_ORun & 0x01) << 1;
	packed |= (CTRL_REG3->I2_Empty & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3, uint8_t packed)
{
	CTRL_REG3->I1_Int1 = (packed >> 7) & 0x01;
	CTRL_REG3->I1_Boot = (packed >> 6) & 0x01;
	CTRL_REG3->H_Lactive = (packed >> 5) & 0x01;
	CTRL_REG3->PP_OD = (packed >> 4) & 0x01;
	CTRL_REG3->I2_DRDY = (packed >> 3) & 0x01;
	CTRL_REG3->I2_WTM = (packed >> 2) & 0x01;
	CTRL_REG3->I2_ORun = (packed >> 1) & 0x01;
	CTRL_REG3->I2_Empty = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4)
{
	uint8_t packed = 0;

	packed |= (CTRL_REG4->BLE & 0x01) << 6;
	packed |= (CTRL_REG4->FS1 & 0x01) << 5;
	packed |= (CTRL_REG4->FS0 & 0x01) << 4;
	packed |= (CTRL_REG4->ST1 & 0x01) << 2;
	packed |= (CTRL_REG4->ST0 & 0x01) << 1;
	packed |= (CTRL_REG4->SIM & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4, uint8_t packed)
{
	CTRL_REG4->BLE = (packed >> 6) & 0x01;
	CTRL_REG4->FS1 = (packed >> 5) & 0x01;
	CTRL_REG4->FS0 = (packed >> 4) & 0x01;
	CTRL_REG4->ST1 = (packed >> 2) & 0x01;
	CTRL_REG4->ST0 = (packed >> 1) & 0x01;
	CTRL_REG4->SIM = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5)
{
	uint8_t packed = 0;

	packed |= (CTRL_REG5->BOOT & 0x01) << 7;
	packed |= (CTRL_REG5->FIFO_EN & 0x01) << 6;
	packed |= (CTRL_REG5->HPen & 0x01) << 4;
	packed |= (CTRL_REG5->INT_Sel1 & 0x01) << 3;
	packed |= (CTRL_REG5->INT_Sel0 & 0x01) << 2;
	packed |= (CTRL_REG5->Out_Sel1 & 0x01) << 1;
	packed |= (CTRL_REG5->Out_Sel0 & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5, uint8_t packed)
{
	CTRL_REG5->BOOT = (packed >> 7) & 0x01;
	CTRL_REG5->FIFO_EN = (packed >> 6) & 0x01;
	CTRL_REG5->HPen = (packed >> 4) & 0x01;
	CTRL_REG5->INT_Sel1 = (packed >> 3) & 0x01;
	CTRL_REG5->INT_Sel0 = (packed >> 2) & 0x01;
	CTRL_REG5->Out_Sel1 = (packed >> 1) & 0x01;
	CTRL_REG5->Out_Sel0 = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG)
{
	uint8_t packed = 0;

	packed |= (STATUS_REG->ZYXOR & 0x01) << 7;
	packed |= (STATUS_REG->ZOR & 0x01) << 6;
	packed |= (STATUS_REG->YOR & 0x01) << 5;
	packed |= (STATUS_REG->XOR & 0x01) << 4;
	packed |= (STATUS_REG->ZYXDA & 0x01) << 3;
	packed |= (STATUS_REG->ZDA & 0x01) << 2;
	packed |= (STATUS_REG->YDA & 0x01) << 1;
	packed |= (STATUS_REG->XDA & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG, uint8_t packed)
{
	STATUS_REG->ZYXOR = (packed >> 7) & 0x01;
	STATUS_REG->ZOR = (packed >> 6) & 0x01;
	STATUS_REG->YOR = (packed >> 5) & 0x01;
	STATUS_REG->XOR = (packed >> 4) & 0x01;
	STATUS_REG->ZYXDA = (packed >> 3) & 0x01;
	STATUS_REG->ZDA = (packed >> 2) & 0x01;
	STATUS_REG->YDA = (packed >> 1) & 0x01;
	STATUS_REG->XDA = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG)
{
	uint8_t packed = 0;

	packed |= (FIFO_CTRL_REG->FM & 0x07) << 5;
	packed |= (FIFO_CTRL_REG->WTM & 0x1F) << 0;

	return packed;
}

void Gyro1_Unpack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG, uint8_t packed)
{
	FIFO_CTRL_REG->FM = (packed >> 5) & 0x07;
	FIFO_CTRL_REG->WTM = (packed >> 0) & 0x1F;

}

uint8_t Gyro1_Pack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG)
{
	uint8_t packed = 0;

	packed |= (FIFO_SRC_REG->WTM & 0x01) << 7;
	packed |= (FIFO_SRC_REG->OVRN & 0x01) << 6;
	packed |= (FIFO_SRC_REG->EMPTY & 0x01) << 5;
	packed |= (FIFO_SRC_REG->FSS & 0x1F) << 0;

	return packed;
}

void Gyro1_Unpack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG, uint8_t packed)
{
	FIFO_SRC_REG->WTM = (packed >> 7) & 0x01;
	FIFO_SRC_REG->OVRN = (packed >> 6) & 0x01;
	FIFO_SRC_REG->EMPTY = (packed >> 5) & 0x01;
	FIFO_SRC_REG->FSS = (packed >> 0) & 0x1F;

}

uint8_t Gyro1_Pack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG)
{
	uint8_t packed = 0;

	packed |= (INT1_CFG->AND_OR & 0x01) << 7;
	packed |= (INT1_CFG->LIR & 0x01) << 6;
	packed |= (INT1_CFG->ZHIE & 0x01) << 5;
	packed |= (INT1_CFG->ZLIE & 0x01) << 4;
	packed |= (INT1_CFG->YHIE & 0x01) << 3;
	packed |= (INT1_CFG->YLIE & 0x01) << 2;
	packed |= (INT1_CFG->XHIE & 0x01) << 1;
	packed |= (INT1_CFG->XLIE & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG, uint8_t packed)
{
	INT1_CFG->AND_OR = (packed >> 7) & 0x01;
	INT1_CFG->LIR = (packed >> 6) & 0x01;
	INT1_CFG->ZHIE = (packed >> 5) & 0x01;
	INT1_CFG->ZLIE = (packed >> 4) & 0x01;
	INT1_CFG->YHIE = (packed >> 3) & 0x01;
	INT1_CFG->YLIE = (packed >> 2) & 0x01;
	INT1_CFG->XHIE = (packed >> 1) & 0x01;
	INT1_CFG->XLIE = (packed >> 0) & 0x01;

}

uint8_t Gyro1_Pack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC)
{
	uint8_t packed = 0;

	packed |= (INT1_SRC->IA & 0x01) << 6;
	packed |= (INT1_SRC->ZH & 0x01) << 5;
	packed |= (INT1_SRC->ZL & 0x01) << 4;
	packed |= (INT1_SRC->YH & 0x01) << 3;
	packed |= (INT1_SRC->YL & 0x01) << 2;
	packed |= (INT1_SRC->XH & 0x01) << 1;
	packed |= (INT1_SRC->XL & 0x01) << 0;

	return packed;
}

void Gyro1_Unpack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC, uint8_t packed)
{
	INT1_SRC->IA = (packed >> 6) & 0x01;
	INT1_SRC->ZH = (packed >> 5) & 0x01;
	INT1_SRC->ZL = (packed >> 4) & 0x01;
	INT1_SRC->YH = (packed >> 3) & 0x01;
	INT1_SRC->YL = (packed >> 2) & 0x01;
	INT1_SRC->XH = (packed >> 1) & 0x01;
	INT1_SRC->XL = (packed >> 0) & 0x01;

}
