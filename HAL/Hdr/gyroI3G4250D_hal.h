/*
 * gyro_hal.h
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#ifndef GYROI3G4250D_HAL_H_
#define GYROI3G4250D_HAL_H_

#define WHO_AM_I	0x0F

typedef struct
{
	uint8_t DR[2];
	uint8_t BW[2];
	uint8_t PD;
	uint8_t Zen;
	uint8_t Yen;
	uint8_t Xen;

}CTRL_REG1;

typedef struct
{
	uint8_t reserved[2];
	uint8_t HPM[2];
	uint8_t HPCF[4];

}CTRL_REG2;

typedef struct
{
	uint8_t I1_Int1;
	uint8_t I1_Boot;
	uint8_t H_Lactive;
	uint8_T PP_OD;
	uint8_t I2_DRDY;
	uint8_T I2_WTM;
	uint8_t I2_ORun;
	uint8_t I2_Empty;

}CTRL_REG3;

typedef struct
{
	uint8_t reserved1;
	uint8_t BLE;
	uint8_t FS1;
	uint8_t FS0;
	uint8_t reserved2;
	uint8_t ST1;
	uint8_t ST0;
	uint8_t SIM;

}CTRL_REG4;

typedef struct
{
	uint8_t BOOT;
	uint8_t FIFO_EN;
	uint8_t reserved1;
	uint8_t HPen;
	uint8_t INT_Sel1;
	uint8_t INT_Sel0;
	uint8_t Out_Sel1;
	uint8_t Out_Sel0;

}CTRL_REG5;

typedef struct
{
	uint8_t ZYXOR;
	uint8_t ZOR;
	uint8_t YOR;
	uint8_t XOR;
	uint8_t ZYXDA;
	uint8_t ZDA;
	uint8_t YDA;
	uint8_t XDA;

}STATUS_REG;

#endif /* HAL_HDR_GYRO_HAL_H_ */
