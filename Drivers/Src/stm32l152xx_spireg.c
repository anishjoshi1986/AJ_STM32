/*
 * stm32l152xx_spireg.c
 *
 *  Created on: Nov 17, 2025
 *      Author: anish
 */

#include <stm32l152xx.h>
#include <stm32l152xx_spireg.h>

// --------------------------------------------------------------------------------------------------------//
// SPI clock control
// --------------------------------------------------------------------------------------------------------//

void SPI_ClkCtrl_Casc(SPI_Handle_st* pSPI_Handle, uint8_t ClkCmd)
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

void SPI_Init_Casc(SPI_Handle_st* pSPI_Handle)
{
	SPI_CR1_REG SPI1_CR1;

	SPI1_CR1.MSTR = pSPI_Handle->SPI_Cfg.master;

	// Configure comms type
	if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_FDX)							// Full Duplex
	{
		SPI1_CR1.BIDIMODE = 0;
	}
	else if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_HDX)					// Half Duplex
	{
		SPI1_CR1.BIDIMODE = 1;
	}
	else if(pSPI_Handle->SPI_Cfg.bustype == SPI_BUSTYPE_SX)						// Simplex
	{
		SPI1_CR1.BIDIMODE = 0;
		if(pSPI_Handle->SPI_Cfg.rxonly)											// If device is to be used only in receive mode
		{
			SPI1_CR1.RXONLY = 1;
		}
	}

	SPI1_CR1.BR = pSPI_Handle->SPI_Cfg.speed;

	SPI1_CR1.DFF = pSPI_Handle->SPI_Cfg.dff;									// Data frame format

	SPI1_CR1.CPOL = pSPI_Handle->SPI_Cfg.cpol;

	SPI1_CR1.CPHA = pSPI_Handle->SPI_Cfg.cpha;

	pSPI_Handle->pSPIX->SPI_CR1 = SPI_Pack_CR1(&SPI1_CR1);

}

uint16_t SPI_Pack_CR1(SPI_CR1_REG* SPIX_CR1)
{
	uint16_t packed = 0;

	packed |= (SPIX_CR1->BIDIMODE & 0x1) << 15;
	packed |= (SPIX_CR1->BIDIOE & 0x1) << 14;
	packed |= (SPIX_CR1->CRCEN & 0x1) << 13;
	packed |= (SPIX_CR1->CRCNEXT & 0x1) << 12;
	packed |= (SPIX_CR1->DFF & 0x1) << 11;
	packed |= (SPIX_CR1->RXONLY & 0x1) << 10;
	packed |= (SPIX_CR1->SSM & 0x1) << 9;
	packed |= (SPIX_CR1->SSI & 0x1) << 8;
	packed |= (SPIX_CR1->LSBFIRST & 0x1) << 7;
	packed |= (SPIX_CR1->SPE & 0x1) << 6;
	packed |= (SPIX_CR1->BR & 0x7) << 3;
	packed |= (SPIX_CR1->MSTR & 0x1) << 2;
	packed |= (SPIX_CR1->CPOL & 0x1) << 1;
	packed |= (SPIX_CR1->CPHA & 0x1) << 0;

	return packed;
}

void SPI_Unpack_SR(SPI_SR_REG* SPIX_SR, uint16_t packed)
{
	SPIX_SR->FRE = (packed >> 8) & 0x1;
	SPIX_SR->BSY = (packed >> 7) & 0x1;
	SPIX_SR->OVR = (packed >> 6) & 0x1;
	SPIX_SR->MODF = (packed >> 5) & 0x1;
	SPIX_SR->CRCERR = (packed >> 4) & 0x1;
	SPIX_SR->UDR = (packed >> 3) & 0x1;
	SPIX_SR->CHSIDE = (packed >> 2) & 0x1;
	SPIX_SR->TXE = (packed >> 1) & 0x1;
	SPIX_SR->RXNE = (packed >> 0) & 0x1;
}

uint8_t SPI_TXBuffBsy(SPI_Handle_st* pSPI_Handle)
{
	uint16_t packed = pSPI_Handle->pSPIX->SPI_SR;
	SPI_SR_REG SPIX_SR;

	SPI_Unpack_SR(&SPIX_SR, packed);

	if(!(SPIX_SR.TXE) || SPIX_SR.BSY)
		return 1;
	else
		return 0;
}

SPI_Write2DataReg(SPI_Handle_st* pSPI_Handle, uint8_t data, uint8_t dff)
{
	if(dff)
	pSPI_Handle->pSPIX->SPI_DR = (uint16_t)data;
	else
	pSPI_Handle->pSPIX->SPI_DR = data;
}

uint8_t SPI_RXBuffMT(SPI_Handle_st* pSPI_Handle)
{
	uint16_t packed = pSPI_Handle->pSPIX->SPI_SR;
	SPI_SR_REG SPIX_SR;

	SPI_Unpack_SR(&SPIX_SR, packed);

	if(!SPIX_SR.RXNE)
		return 1;
	else
		return 0;
}

uint16_t SPI_ReadDataReg(SPI_Handle_st* pSPI_Handle)
{
	return (uint16_t)pSPI_Handle->pSPIX->SPI_DR;
}
