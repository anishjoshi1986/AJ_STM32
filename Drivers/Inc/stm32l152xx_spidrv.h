/*
 * stm32l152xx_spidrv.h
 *
 *  Created on: Oct 21, 2025
 *      Author: anish
 */

#ifndef INC_STM32L152XX_SPIDRV_H_
#define INC_STM32L152XX_SPIDRV_H_

#include "stm32l152xx_spireg.h"

// --------------------------------------------------------------------------------------------------------//
// APIs for managing SPI
// --------------------------------------------------------------------------------------------------------//

void SPI_ClkCtrl(SPI_Handle_st *pSPI_Handle, uint8_t ClkCmd);									// Clock enable

void SPI_Reset(SPI_Handle_st *pSPI_Handle);														// Peripheral reset

uint16_t SPI_ReadSingle(SPI_Handle_st *pSPI_Handle);

uint8_t SPI_WriteSingle(SPI_Handle_st *pSPI_Handle, uint8_t data, uint8_t dff);
void SPI_WriteFaultCheck(uint8_t status);

void SPI_Init(SPI_Handle_st *pSPI_Handle);													// Initialize based on user input

uint16_t SPI_XferByte(SPI_Handle_st *pSPI_Handle, uint8_t data, uint8_t dff);

#endif /* INC_STM32L152XX_SPIDRV_H_ */
