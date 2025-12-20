/*
 * gyro_hal.h
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#ifndef GYROI3G4250D_HAL_H_
#define GYROI3G4250D_HAL_H_

#define WHO_AM_I_ADDR			0x000FU
#define CTRL_REG1_ADDR			0x0020U
#define CTRL_REG2_ADDR			0x0021U
#define CTRL_REG3_ADDR			0x0022U
#define CTRL_REG4_ADDR			0x0023U
#define CTRL_REG5_ADDR			0x0024U
#define STATUS_REG_ADDR 		0x0027U
#define FIFO_CTRL_REG_ADDR 		0x002EU
#define FIFO_SRC_REG_ADDR		0x002FU
#define INT1_CFG_ADDR			0x0030U
#define INT1_SRC_ADDR			0x0031U


int8_t INT1_DURATION;

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

typedef struct
{
	uint8_t FM[3];
	uint8_t WTM[4];

}FIFO_CTRL_REG;

typedef struct
{
	uint8_t WTM;
	uint8_t OVRN;
	uint8_t EMPTY;
	uint8_t FSS[5];
}FIFO_SRC_REG;

typedef struct
{
	uint8_t AND_OR;
	uint8_t LIR;
	uint8_t ZHIE;
	uint8_t ZLIE;
	uint8_t YHIE;
	uint8_t YLIE;
	uint8_t XHIE;
	uint8_t XLIE;

}INT1_CFG;

typedef struct
{
	uint8_t reserved;
	uint8_t IA;
	uint8_t ZH;
	uint8_t ZL;
	uint8_t YH;
	uint8_t YL;
	uint8_t XH;
	uint8_t XL;

}INT1_SRC;

#endif /* HAL_HDR_GYRO_HAL_H_ */
