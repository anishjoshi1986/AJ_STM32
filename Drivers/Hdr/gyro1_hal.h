/*
 * gyro1_hal.h
 *
 *  Created on: Dec 20, 2025
 *      Author: anish
 */

#ifndef GYRO1_HAL_H_
#define GYRO1_HAL_H_

#include "../../HAL/Hdr/spi_hal.h"
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

#define OUT_X_L							0x0000U

#define GYRO1_WHO_AM_I_EXP				0x00D3U

int8_t GYRO1_INT1_DURATION;

typedef struct
{
	uint8_t DR : 2;
	uint8_t BW : 2;
	uint8_t PD : 1;
	uint8_t Zen : 1;
	uint8_t Yen : 1;
	uint8_t Xen : 1;

}GYRO1_CTRL_REG1;

typedef struct
{
	uint8_t reserved : 2;
	uint8_t HPM : 2;
	uint8_t HPCF : 4;

}GYRO1_CTRL_REG2;

typedef struct
{
	uint8_t I1_Int1 : 1;
	uint8_t I1_Boot : 1;
	uint8_t H_Lactive : 1;
	uint8_t PP_OD : 1;
	uint8_t I2_DRDY : 1;
	uint8_t I2_WTM : 1;
	uint8_t I2_ORun : 1;
	uint8_t I2_Empty : 1;

}GYRO1_CTRL_REG3;

typedef struct
{
	uint8_t reserved1 : 1;
	uint8_t BLE : 1;
	uint8_t FS1 : 1;
	uint8_t FS0 : 1;
	uint8_t reserved2 : 1;
	uint8_t ST1 : 1;
	uint8_t ST0 : 1;
	uint8_t SIM : 1;

}GYRO1_CTRL_REG4;

typedef struct
{
	uint8_t BOOT : 1;
	uint8_t FIFO_EN : 1;
	uint8_t reserved1 : 1;
	uint8_t HPen : 1;
	uint8_t INT_Sel1 : 1;
	uint8_t INT_Sel0 : 1;
	uint8_t Out_Sel1 : 1;
	uint8_t Out_Sel0 : 1;

}GYRO1_CTRL_REG5;

typedef struct
{
	uint8_t ZYXOR : 1;
	uint8_t ZOR : 1;
	uint8_t YOR : 1;
	uint8_t XOR : 1;
	uint8_t ZYXDA : 1;
	uint8_t ZDA : 1;
	uint8_t YDA : 1;
	uint8_t XDA : 1;

}GYRO1_STATUS_REG;

typedef struct
{
	uint8_t FM : 3;
	uint8_t WTM : 5;

}GYRO1_FIFO_CTRL_REG;

typedef struct
{
	uint8_t WTM : 1;
	uint8_t OVRN : 1;
	uint8_t EMPTY : 1;
	uint8_t FSS : 5;
}GYRO1_FIFO_SRC_REG;

typedef struct
{
	uint8_t AND_OR : 1;
	uint8_t LIR : 1;
	uint8_t ZHIE : 1;
	uint8_t ZLIE : 1;
	uint8_t YHIE : 1;
	uint8_t YLIE : 1;
	uint8_t XHIE : 1;
	uint8_t XLIE : 1;

}GYRO1_INT1_CFG;

typedef struct
{
	uint8_t reserved : 1;
	uint8_t IA : 1;
	uint8_t ZH : 1;
	uint8_t ZL : 1;
	uint8_t YH : 1;
	uint8_t YL : 1;
	uint8_t XH : 1;
	uint8_t XL : 1;

}GYRO1_INT1_SRC;


uint8_t Gyro1_Pack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1);
void Gyro1_Unpack_CTRL_REG1(GYRO1_CTRL_REG1 *CTRL_REG1, uint8_t packed);

uint8_t Gyro1_Pack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2);
void Gyro1_Unpack_CTRL_REG2(GYRO1_CTRL_REG2 *CTRL_REG2, uint8_t packed);

uint8_t Gyro1_Pack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3);
void Gyro1_Unpack_CTRL_REG3(GYRO1_CTRL_REG3 *CTRL_REG3, uint8_t packed);

uint8_t Gyro1_Pack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4);
void Gyro1_Unpack_CTRL_REG4(GYRO1_CTRL_REG4 *CTRL_REG4, uint8_t packed);

uint8_t Gyro1_Pack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5);
void Gyro1_Unpack_CTRL_REG5(GYRO1_CTRL_REG5 *CTRL_REG5, uint8_t packed);

uint8_t Gyro1_Pack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG);
void Gyro1_Unpack_STATUS_REG(GYRO1_STATUS_REG *STATUS_REG, uint8_t packed);

uint8_t Gyro1_Pack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG);
void Gyro1_Unpack_FIFO_CTRL_REG(GYRO1_FIFO_CTRL_REG *FIFO_CTRL_REG, uint8_t packed);

uint8_t Gyro1_Pack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG);
void Gyro1_Unpack_FIFO_SRC_REG(GYRO1_FIFO_SRC_REG *FIFO_SRC_REG, uint8_t packed);

uint8_t Gyro1_Pack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG);
void Gyro1_Unpack_INT1_CFG(GYRO1_INT1_CFG *INT1_CFG, uint8_t packed);

uint8_t Gyro1_Pack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC);
void Gyro1_Unpack_INT1_SRC(GYRO1_INT1_SRC *INT1_SRC, uint8_t packed);

uint16_t Gyro1_Read(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg);
uint8_t Gyro1_ReadFIFO(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg, int16_t *buf);
uint8_t Gyro1_Write(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg, uint16_t value);
void Gyro1_BurstRead(STM32_SPIHandle_st* pSPI_Handle, uint8_t device_reg, uint8_t *data, uint8_t len);

#endif /* HAL_HDR_GYRO_HAL_H_ */
