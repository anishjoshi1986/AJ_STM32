/*
 * spi_drv.c
 *
 *  Created on: Dec 17, 2025
 *      Author: anish
 */

#include "../../HAL/Hdr/spi_hal.h"

uint16_t SPI_Read(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg)
{
	STM32_SPI_Write(pSPI_Handle, device_reg);

	return(STM32_SPI_Read(pSPI_Handle));

}

uint8_t SPI_Write(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg, uint16_t value)
{
	STM32_SPI_Write(pSPI_Handle, device_reg);
	STM32_SPI_Write(pSPI_Handle, value);

	STM32_SPI_Write(pSPI_Handle, device_reg);
	return(value == STM32_SPI_Read(pSPI_Handle));
}

uint16_t SPI_ReadFIFO(STM32_SPIHandle_st* pSPI_Handle, uint16_t device_reg)
{
	return 0;
}
