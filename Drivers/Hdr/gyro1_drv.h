/*
 * gyro1_drv.h
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#ifndef GYRO1_DRV_H_
#define GYRO1_DRV_H_

#include "../../HAL/Hdr/spi_hal.h"
#include "../../HAL/Hdr/gpio_hal.h"
#include <stdint.h>

#define GYRO1_WHO_AM_I_ADDR				0x000FU
#define GYRO1_CTRL_REG1_ADDR			0x0020U
#define GYRO1_CTRL_REG2_ADDR			0x0021U
#define GYRO1_CTRL_REG3_ADDR			0x0022U
#define GYRO1_CTRL_REG4_ADDR			0x0023U
#define GYRO1_CTRL_REG5_ADDR			0x0024U
#define GYRO1_STATUS_REG_ADDR 			0x0027U
#define GYRO1_FIFO_CTRL_REG_ADDR 		0x002EU
#define GYRO1_FIFO_SRC_REG_ADDR			0x002FU
#define GYRO1_INT1_CFG_ADDR				0x0030U
#define GYRO1_INT1_SRC_ADDR				0x0031U

#define OUT_X_L_ADDR					0x0028U
#define OUT_X_H_ADDR					0x0029U
#define OUT_Y_L_ADDR					0x002AU
#define OUT_Y_H_ADDR					0x002BU
#define OUT_Z_L_ADDR					0x002CU
#define OUT_Z_H_ADDR					0x002DU

#define GYRO1_WHO_AM_I_EXP				0x00D3U

typedef struct
{
	U8 DR : 2;
	U8 BW : 2;
	U8 PD : 1;
	U8 Zen : 1;
	U8 Yen : 1;
	U8 Xen : 1;

}GYRO1_CTRL_REG1;

typedef struct
{
	U8 reserved : 2;
	U8 HPM : 2;
	U8 HPCF : 4;

}GYRO1_CTRL_REG2;

typedef struct
{
	U8 I1_Int1 : 1;
	U8 I1_Boot : 1;
	U8 H_Lactive : 1;
	U8 PP_OD : 1;
	U8 I2_DRDY : 1;
	U8 I2_WTM : 1;
	U8 I2_ORun : 1;
	U8 I2_Empty : 1;

}GYRO1_CTRL_REG3;

typedef struct
{
	U8 reserved1 : 1;
	U8 BLE : 1;
	U8 FS : 2;
	U8 reserved2 : 1;
	U8 ST : 2;
	U8 SIM : 1;

}GYRO1_CTRL_REG4;

typedef struct
{
	U8 BOOT : 1;
	U8 FIFO_EN : 1;
	U8 reserved1 : 1;
	U8 HPen : 1;
	U8 INT_Sel : 2;
	U8 Out_Sel : 2;

}GYRO1_CTRL_REG5;

typedef struct
{
	U8 ZYXOR : 1;
	U8 ZOR : 1;
	U8 YOR : 1;
	U8 XOR : 1;
	U8 ZYXDA : 1;
	U8 ZDA : 1;
	U8 YDA : 1;
	U8 XDA : 1;

}GYRO1_STATUS_REG;

typedef struct
{
	U8 FM : 3;
	U8 WTM : 5;

}GYRO1_FIFO_CTRL_REG;

typedef struct
{
	U8 WTM : 1;
	U8 OVRN : 1;
	U8 EMPTY : 1;
	U8 FSS : 5;
}GYRO1_FIFO_SRC_REG;

typedef struct
{
	U8 AND_OR : 1;
	U8 LIR : 1;
	U8 ZHIE : 1;
	U8 ZLIE : 1;
	U8 YHIE : 1;
	U8 YLIE : 1;
	U8 XHIE : 1;
	U8 XLIE : 1;

}GYRO1_INT1_CFG;

typedef struct
{
	U8 reserved : 1;
	U8 IA : 1;
	U8 ZH : 1;
	U8 ZL : 1;
	U8 YH : 1;
	U8 YL : 1;
	U8 XH : 1;
	U8 XL : 1;

}GYRO1_INT1_SRC;

typedef struct
{
	SPIHandle_st* pSPI_Handle;
	GPIOHandle_st* pGPIO_Handle;

}Gyro1Handle_st;

U8 Gyro1_Pack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1);
void Gyro1_Unpack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1, U8 packed);

U8 Gyro1_Pack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2);
void Gyro1_Unpack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2, U8 packed);

U8 Gyro1_Pack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3);
void Gyro1_Unpack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3, U8 packed);

U8 Gyro1_Pack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4);
void Gyro1_Unpack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4, U8 packed);

U8 Gyro1_Pack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5);
void Gyro1_Unpack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5, U8 packed);

U8 Gyro1_Pack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG);
void Gyro1_Unpack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG, U8 packed);

U8 Gyro1_Pack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG);
void Gyro1_Unpack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG, U8 packed);

U8 Gyro1_Pack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG);
void Gyro1_Unpack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG, U8 packed);

U8 Gyro1_Pack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG);
void Gyro1_Unpack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG, U8 packed);

U8 Gyro1_Pack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC);
void Gyro1_Unpack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC, U8 packed);


uint16_t Gyro1_Read(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg);
void Gyro1_BurstRead(Gyro1Handle_st* pGyro1_Handle, U8 device_reg, U8 *data, U8 len);
U8 Gyro1_ReadFIFO(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg, int16_t *buf);
U8 Gyro1_Write(Gyro1Handle_st* pGyro1_Handle, uint16_t device_reg, uint16_t value);
U8 Gyro1_ErrCheck(Gyro1Handle_st* pGyro1_Handle, U8 device_reg);

#endif /* HAL_HDR_GYRO_HAL_H_ */
