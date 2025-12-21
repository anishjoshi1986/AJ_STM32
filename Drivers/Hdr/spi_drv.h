/*
 * spidrv.h
 *
 *  Created on: Dec 17, 2025
 *      Author: anish
 */

#ifndef SPI_DRV_H_
#define SPI_DRV_H_

#include "../HAL/Hdr/spi_hal.h"

uint16_t SPI_Read(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg);
uint16_t SPI_ReadFIFO(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg);
uint8_t SPI_Write(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg, uint16_t value);
uint8_t SPI_ErrCheck(STM32_SPIHandle_st* pSPI_Handle);

#endif /* HDR_SPI_DRV_H_ */
