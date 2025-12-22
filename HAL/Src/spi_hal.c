/*
 * spi_hal.c
 *
 *  Created on: Nov 17, 2025
 *      Author: anish
 */

#include "../Hdr/spi_hal.h"

// --------------------------------------------------------------------------------------------------------//
// STM32 SPI pack/unpack registers
// --------------------------------------------------------------------------------------------------------//

uint16_t STM32_Pack_CR1(STM32_CR1_REG* SPIX_CR1)
{
	uint16_t packed = 0;

	packed |= (SPIX_CR1->BIDIMODE & 0x01) << 15;
	packed |= (SPIX_CR1->BIDIOE & 0x01) << 14;
	packed |= (SPIX_CR1->CRCEN & 0x01) << 13;
	packed |= (SPIX_CR1->CRCNEXT & 0x01) << 12;
	packed |= (SPIX_CR1->DFF & 0x01) << 11;
	packed |= (SPIX_CR1->RXONLY & 0x01) << 10;
	packed |= (SPIX_CR1->SSM & 0x01) << 9;
	packed |= (SPIX_CR1->SSI & 0x01) << 8;
	packed |= (SPIX_CR1->LSBFIRST & 0x01) << 7;
	packed |= (SPIX_CR1->SPE & 0x01) << 6;
	packed |= (SPIX_CR1->BR & 0x07) << 3;
	packed |= (SPIX_CR1->MSTR & 0x01) << 2;
	packed |= (SPIX_CR1->CPOL & 0x01) << 1;
	packed |= (SPIX_CR1->CPHA & 0x01) << 0;

	return packed;
}

void STM32_Unpack_SR(STM32_SR_REG* SPIX_SR, uint16_t packed)
{
	SPIX_SR->FRE = (packed >> 8) & 0x01;
	SPIX_SR->BSY = (packed >> 7) & 0x01;
	SPIX_SR->OVR = (packed >> 6) & 0x01;
	SPIX_SR->MODF = (packed >> 5) & 0x01;
	SPIX_SR->CRCERR = (packed >> 4) & 0x01;
	SPIX_SR->UDR = (packed >> 3) & 0x01;
	SPIX_SR->CHSIDE = (packed >> 2) & 0x01;
	SPIX_SR->TXE = (packed >> 1) & 0x01;
	SPIX_SR->RXNE = (packed >> 0) & 0x01;
}

// --------------------------------------------------------------------------------------------------------//
// SPI clock control
// --------------------------------------------------------------------------------------------------------//

void STM32_SPI_ClkCtrl(STM32_SPIHandle_st* pSPI_Handle, uint8_t ClkCmd)
{
	if(ClkCmd == SET)
	{
		if(pSPI_Handle->pSPIX == pSPI1)
		{
			SPI1_CLK_EN();
		}
		else if(pSPI_Handle->pSPIX == pSPI2)
		{
			SPI2_CLK_EN();
		}
		else if(pSPI_Handle->pSPIX == pSPI3)
		{
			SPI3_CLK_EN();
		}

	else
	{
		if(pSPI_Handle->pSPIX == pSPI1)
		{
			SPI1_CLK_DIS();
		}
		else if(pSPI_Handle->pSPIX == pSPI2)
		{
			SPI2_CLK_DIS();
		}
		else if(pSPI_Handle->pSPIX == pSPI3)
		{
			SPI3_CLK_DIS();
		}
	}
	}
}

// --------------------------------------------------------------------------------------------------------//
// SPI config initialize
// --------------------------------------------------------------------------------------------------------//

void STM32_SPI_Init(STM32_SPIHandle_st* pSPI_Handle)
{
	STM32_SPI_Reset(pSPI_Handle);

	STM32_CR1_REG SPI_CR1_temp;

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

	pSPI_Handle->pSPIX->SPI_CR1 = STM32_Pack_CR1(&SPI_CR1_temp);

}

void STM32_SPI_Reset(STM32_SPIHandle_st* pSPI_Handle)
{
	STM32_CR1_REG SPI_CR1_temp;

	SPI_CR1_temp.MSTR = 0;
	SPI_CR1_temp.BIDIMODE = 0;
	SPI_CR1_temp.RXONLY = 0;
	SPI_CR1_temp.BR = 0;
	SPI_CR1_temp.DFF = 0;									// Data frame format
	SPI_CR1_temp.CPOL = 0;
	SPI_CR1_temp.CPHA = 0;
	SPI_CR1_temp.CRCEN = 0;

	pSPI_Handle->pSPIX->SPI_CR1 = STM32_Pack_CR1(&SPI_CR1_temp);

}

// --------------------------------------------------------------------------------------------------------//
// SPI register level operations - check for busy, check RX empty, check for errors
// --------------------------------------------------------------------------------------------------------//

uint8_t STM32_SPI_Bsy(STM32_SPIHandle_st* pSPI_Handle)
{
	uint16_t packed = pSPI_Handle->pSPIX->SPI_SR;
	STM32_SR_REG SPIX_SR;

	STM32_Unpack_SR(&SPIX_SR, packed);

	if(!(SPIX_SR.TXE) || SPIX_SR.BSY)
		return 1;
	else
		return 0;
}

uint8_t STM32_SPI_RXMT(STM32_SPIHandle_st* pSPI_Handle)
{
	uint16_t packed = pSPI_Handle->pSPIX->SPI_SR;
	STM32_SR_REG SPIX_SR;

	STM32_Unpack_SR(&SPIX_SR, packed);

	if(!SPIX_SR.RXNE)
		return 1;
	else
		return 0;
}

uint8_t STM32_SPI_ErrCheck(STM32_SPIHandle_st* pSPI_Handle)
{
	uint16_t packed = pSPI_Handle->pSPIX->SPI_SR;
	STM32_SR_REG SPIX_SR;

	STM32_Unpack_SR(&SPIX_SR, packed);

	if(SPIX_SR.OVR || SPIX_SR.MODF || SPIX_SR.CRCERR || SPIX_SR.UDR)
		return 1;
	else
		return 0;
}

// --------------------------------------------------------------------------------------------------------//
// SPI read write
// --------------------------------------------------------------------------------------------------------//

uint8_t STM32_SPI_Write(STM32_SPIHandle_st* pSPI_Handle, uint8_t data)
{
	uint8_t cnt_spibsy = 0;
	uint8_t timeout_thres = 254;

	while(STM32_SPI_Bsy(pSPI_Handle))
	{
		cnt_spibsy++;
		if(cnt_spibsy > timeout_thres)
			return 1;
	}

	if(pSPI_Handle->SPI_Cfg.dff)
		pSPI_Handle->pSPIX->SPI_DR = (uint16_t)data;
	else
		pSPI_Handle->pSPIX->SPI_DR = data;

	return 0;

}

uint16_t STM32_SPI_Read(STM32_SPIHandle_st* pSPI_Handle)
{
	uint8_t cnt_spibsy = 0;
	uint8_t timeout_thres = 254;

	while(STM32_SPI_RXMT(pSPI_Handle))
	{
		cnt_spibsy++;
		if(cnt_spibsy > timeout_thres)
		return 1;
	}

	return (uint16_t)pSPI_Handle->pSPIX->SPI_DR;

}
