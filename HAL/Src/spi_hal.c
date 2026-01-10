/*
 * spi_hal.c
 *
 *  Created on: Nov 17, 2025
 *      Author: anish
 */

#include "../Hdr/spi_hal.h"
#include <stdlib.h>

// --------------------------------------------------------------------------------------------------------//
// STM32 SPI pack/unpack registers
// --------------------------------------------------------------------------------------------------------//

U32 STM32_Pack_SPI_CR1(STM32_SPI_CR1_Cfg* SPIX_CR1_CFG)
{
	U32 packed = 0;

	packed |= (U32)(SPIX_CR1_CFG->BIDIMODE & 1U) << 15;
	packed |= (U32)(SPIX_CR1_CFG->BIDIOE & 1U) << 14;
	packed |= (U32)(SPIX_CR1_CFG->CRCEN & 1U) << 13;
	packed |= (U32)(SPIX_CR1_CFG->CRCNEXT & 1U) << 12;
	packed |= (U32)(SPIX_CR1_CFG->DFF & 1U) << 11;
	packed |= (U32)(SPIX_CR1_CFG->RXONLY & 1U) << 10;
	packed |= (U32)(SPIX_CR1_CFG->SSM & 1U) << 9;
	packed |= (U32)(SPIX_CR1_CFG->SSI & 1U) << 8;
	packed |= (U32)(SPIX_CR1_CFG->LSBFIRST & 1U) << 7;
	packed |= (U32)(SPIX_CR1_CFG->SPE & 1U) << 6;
	packed |= (U32)(SPIX_CR1_CFG->BR & 0x07U) << 3;
	packed |= (U32)(SPIX_CR1_CFG->MSTR & 1U) << 2;
	packed |= (U32)(SPIX_CR1_CFG->CPOL & 1U) << 1;
	packed |= (U32)(SPIX_CR1_CFG->CPHA & 1U) << 0;

	return packed;
}

void STM32_Unpack_SPI_SR(STM32_SPI_SR_Cfg* SPIX_SR_CFG, U32 packed)
{
	SPIX_SR_CFG->FRE = (packed >> 8) & 1U;
	SPIX_SR_CFG->BSY = (packed >> 7) & 1U;
	SPIX_SR_CFG->OVR = (packed >> 6) & 1U;
	SPIX_SR_CFG->MODF = (packed >> 5) & 1U;
	SPIX_SR_CFG->CRCERR = (packed >> 4) & 1U;
	SPIX_SR_CFG->UDR = (packed >> 3) & 1U;
	SPIX_SR_CFG->CHSIDE = (packed >> 2) & 1U;
	SPIX_SR_CFG->TXE = (packed >> 1) & 1U;
	SPIX_SR_CFG->RXNE = (packed >> 0) & 1U;
}

// --------------------------------------------------------------------------------------------------------//
// SPI config initialize
// --------------------------------------------------------------------------------------------------------//

void SPI_Init(SPIHandle_st* pSPI_Handle)
{
	SPI_Reset(pSPI_Handle);

	STM32_SPI_CR1_Cfg SPI_CR1_temp;

	// Configure comms type
	if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_FDX)							// Full Duplex
	{
		SPI_CR1_temp.BIDIMODE = 0;
		SPI_CR1_temp.RXONLY = 0;
	}
	else if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_HDX)					// Half Duplex
	{
		SPI_CR1_temp.BIDIMODE = 1;
		SPI_CR1_temp.RXONLY = 0;
	}
	else if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_SX)						// Simplex
	{
		SPI_CR1_temp.BIDIMODE = 0;
		if(pSPI_Handle->SPI_Cfg.rxonly)											// If device is to be used only in receive mode
		{
			SPI_CR1_temp.RXONLY = 1;
		}
	}

	SPI_CR1_temp.CRCEN = pSPI_Handle->SPI_Cfg.crcen;

	SPI_CR1_temp.CRCNEXT = 0;

	SPI_CR1_temp.DFF = pSPI_Handle->SPI_Cfg.dff;									// Data frame format

	SPI_CR1_temp.SSM = pSPI_Handle->SPI_Cfg.ssm;

	SPI_CR1_temp.SSI = 0;

	SPI_CR1_temp.LSBFIRST = 0;

	SPI_CR1_temp.SPE = 1;

	SPI_CR1_temp.BR = pSPI_Handle->SPI_Cfg.speed;

	SPI_CR1_temp.MSTR = pSPI_Handle->SPI_Cfg.master;

	SPI_CR1_temp.CPOL = pSPI_Handle->SPI_Cfg.cpol;

	SPI_CR1_temp.CPHA = pSPI_Handle->SPI_Cfg.cpha;

	pSPI_Handle->pSPIX->CR1 = STM32_Pack_SPI_CR1(&SPI_CR1_temp);

}

void SPI_Reset(SPIHandle_st* pSPI_Handle)
{
	STM32_SPI_CR1_Cfg SPI_CR1_temp;

	SPI_CR1_temp.MSTR = 0;
	SPI_CR1_temp.BIDIMODE = 0;
	SPI_CR1_temp.RXONLY = 0;
	SPI_CR1_temp.BR = 0;
	SPI_CR1_temp.DFF = 0;									// Data frame format
	SPI_CR1_temp.CPOL = 0;
	SPI_CR1_temp.CPHA = 0;
	SPI_CR1_temp.CRCEN = 0;

	pSPI_Handle->pSPIX->CR1 = STM32_Pack_SPI_CR1(&SPI_CR1_temp);

}

// --------------------------------------------------------------------------------------------------------//
// SPI register level operations - check for busy, check RX empty, check for errors
// --------------------------------------------------------------------------------------------------------//

U8 SPI_Bsy(SPIHandle_st* pSPI_Handle)
{
	U16 packed = pSPI_Handle->pSPIX->SR;
	STM32_SPI_SR_Cfg SPIX_SR;

	STM32_Unpack_SPI_SR(&SPIX_SR, packed);

	if(!(SPIX_SR.TXE) || SPIX_SR.BSY)
		return 1;
	else
		return 0;
}

U8 SPI_RXMT(SPIHandle_st* pSPI_Handle)
{
	U16 packed = pSPI_Handle->pSPIX->SR;
	STM32_SPI_SR_Cfg SPIX_SR;

	STM32_Unpack_SPI_SR(&SPIX_SR, packed);

	if(!SPIX_SR.RXNE)
		return 1;
	else
		return 0;
}

U8 SPI_ErrCheck(SPIHandle_st* pSPI_Handle)
{
	U16 packed = pSPI_Handle->pSPIX->SR;
	STM32_SPI_SR_Cfg SPIX_SR;

	STM32_Unpack_SPI_SR(&SPIX_SR, packed);

	if(SPIX_SR.OVR || SPIX_SR.MODF || SPIX_SR.CRCERR || SPIX_SR.UDR)
		return 1;
	else
		return 0;
}

// --------------------------------------------------------------------------------------------------------//
// SPI read write
// --------------------------------------------------------------------------------------------------------//

U8 SPI_Write(SPIHandle_st* pSPI_Handle, U8 data)
{
	U8 cnt_spibsy = 0;

	while(SPI_Bsy(pSPI_Handle))
	{
		cnt_spibsy++;
		if(cnt_spibsy > SPI_TIMEOUT_THRES)
			return 1;
	}

	if(pSPI_Handle->SPI_Cfg.dff)
		pSPI_Handle->pSPIX->DR = (U16)data;
	else
		pSPI_Handle->pSPIX->DR = data;

	while(SPI_Bsy(pSPI_Handle))
	{
		cnt_spibsy++;
		if(cnt_spibsy > SPI_TIMEOUT_THRES)
			return 1;
	}

	return 0;

}

U16 SPI_Read(SPIHandle_st* pSPI_Handle)
{
	U8 cnt_spibsy = 0;

	while(SPI_RXMT(pSPI_Handle))
	{
		cnt_spibsy++;
		if(cnt_spibsy > SPI_TIMEOUT_THRES)
		return 1;
	}

	return (U16)pSPI_Handle->pSPIX->DR;

}
