/*
 * stm32l152xx_spireg.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32L152XX_SPIREG_H_
#define STM32L152XX_SPIREG_H_

#include <stdint.h>
#include "stm32l152xx.h"

// SPI config macros
#define SPI_BUSTYPE_FDX		0
#define SPI_BUSTYPE_HDX		1
#define SPI_BUSTYPE_SX		2
#define SPI_RXONLY			1

// --------------------------------------------------------------------------------------------------------//
// SPI peripheral address on APB2 & reg struct - found from memory map/reg boundary addresses in RM
// --------------------------------------------------------------------------------------------------------//

// SPI register structs

typedef struct
{
	uint8_t BIDIMODE : 1;
	uint8_t BIDIOE : 1;
	uint8_t CRCEN : 1;
	uint8_t CRCNEXT : 1;
	uint8_t DFF : 1;
	uint8_t RXONLY : 1;
	uint8_t SSM : 1;
	uint8_t SSI : 1;
	uint8_t LSBFIRST : 1;
	uint8_t SPE : 1;
	uint8_t BR : 3;
	uint8_t MSTR : 1;
	uint8_t CPOL : 1;
	uint8_t CPHA : 1;

}SPI_CR1_REG;

typedef struct
{
	uint8_t TXEIE : 1;
	uint8_t RXNEIE : 1;
	uint8_t ERRIE : 1;
	uint8_t FRF : 1;
	uint8_t RESERVED : 1;
	uint8_t SSOE : 1;
	uint8_t TXDMAEN : 1;
	uint8_t RXDMAEN : 1;

}SPI_CR2_REG;

typedef struct
{
	uint8_t FRE : 1;
	uint8_t BSY : 1;
	uint8_t OVR : 1;
	uint8_t MODF : 1;
	uint8_t CRCERR : 1;
	uint8_t UDR : 1;
	uint8_t CHSIDE : 1;
	uint8_t TXE : 1;
	uint8_t RXNE : 1;

}SPI_SR_REG;

typedef struct
{
	__vo uint32_t SPI_CR1;
	__vo uint32_t SPI_CR2;
	__vo uint32_t SPI_SR;
	__vo uint32_t SPI_DR;
	__vo uint32_t SPI_CRCPR;
	__vo uint32_t SPI_RXCRCR;
	__vo uint32_t SPI_TXCRCR;
	__vo uint32_t SPI_I2SCFGR;
	__vo uint32_t SPI_I2SPR;

}SPI_RegDef_st;

// --------------------------------------------------------------------------------------------------------//
// API structs for managing SPI
// --------------------------------------------------------------------------------------------------------//

typedef struct
{
	uint8_t master;							// Master, slave
	uint8_t bustype; 						// Duplex, simplex, half duplex
	uint8_t rxonly;							// Receive data only
	uint8_t speed;							// SPI clock speed
	uint8_t dff;							// Data frame format - send 8/16 bits
	uint8_t cpha;
	uint8_t cpol;
	uint8_t ssm;							// Slave select management - sw/hw slave select

}SPI_Cfg_st;

typedef struct
{
	SPI_RegDef_st *pSPIX;				// Pointer to the base address of the gpio reg
	SPI_Cfg_st SPI_Cfg;					// Pointer to pin config struct

}SPI_Handle_st;

// SPI base addresses and pointers
#define SPI1					(APB2 + 0x3000U)
#define SPI2					(APB1 + 0x3800U)
#define SPI3					(APB1 + 0x3C00U)

#define pSPI1					(SPI_RegDef_st *)SPI1
#define pSPI2					(SPI_RegDef_st *)SPI2
#define pSPI3					(SPI_RegDef_st *)SPI3

// Macros to enable/disable SPI clocks
#define SPI1_CLK_EN()			(pRCC->APB2ENR |= 1 << 12)		// Peripheral clock enable for SPI peripherals
#define SPI2_CLK_EN()			(pRCC->APB1ENR |= 1 << 14)
#define SPI3_CLK_EN()			(pRCC->APB1ENR |= 1 << 15)

#define SPI1_CLK_DIS()			(pRCC->APB2ENR &= ~(1 << 12))	// Peripheral clock disable for SPI peripherals
#define SPI2_CLK_DIS()			(pRCC->APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DIS()			(pRCC->APB1ENR &= ~(1 << 15))

uint16_t SPI_Pack_CR1(SPI_CR1_REG *SPIX_CR1);

void SPI_ClkCtrl_Casc(SPI_Handle_st* pSPI_Handle, uint8_t ClkCmd);

void SPI_Init_Casc(SPI_Handle_st* pSPI_Handle);

void SPI_Unpack_SR(SPI_SR_REG* SPIX_SR, uint16_t packed);

uint8_t SPI_TXBuffBsy(SPI_Handle_st* pSPI_Handle);

void SPI_Write2DataReg(SPI_Handle_st* pSPI_Handle, uint8_t data, uint8_t dff);

uint8_t SPI_RXBuffMT(SPI_Handle_st* pSPI_Handle);

uint16_t SPI_ReadDataReg(SPI_Handle_st* pSPI_Handle);

#endif
