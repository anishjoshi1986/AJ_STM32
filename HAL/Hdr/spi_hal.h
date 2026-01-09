/*
 * spi_hal.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef SPI_HAL_H_
#define SPI_HAL_H_

#include "stm32_hal.h"

// --------------------------------------------------------------------------------------------------------//
// SPI register address and macros
// --------------------------------------------------------------------------------------------------------//

// Macros to enable/disable SPI clocks
#define SPI1_CLK_EN()			(pRCC->APB2ENR |= 1 << 12)		// Peripheral clock enable for SPI peripherals
#define SPI2_CLK_EN()			(pRCC->APB1ENR |= 1 << 14)
#define SPI3_CLK_EN()			(pRCC->APB1ENR |= 1 << 15)

#define SPI1_CLK_DIS()			(pRCC->APB2ENR &= ~(1 << 12))	// Peripheral clock disable for SPI peripherals
#define SPI2_CLK_DIS()			(pRCC->APB1ENR &= ~(1 << 14))
#define SPI3_CLK_DIS()			(pRCC->APB1ENR &= ~(1 << 15))

// SPI config macros
#define SPI_BUSTYPE_FDX		0U
#define SPI_BUSTYPE_HDX		1U
#define SPI_BUSTYPE_SX		2U
#define SPI_RXONLY			1U

#define SPI_TIMEOUT_THRES	(U8)254

// --------------------------------------------------------------------------------------------------------//
// SPI register structs
// --------------------------------------------------------------------------------------------------------//

typedef struct
{
	U8 BIDIMODE : 1;
	U8 BIDIOE : 1;
	U8 CRCEN : 1;
	U8 CRCNEXT : 1;
	U8 DFF : 1;
	U8 RXONLY : 1;
	U8 SSM : 1;
	U8 SSI : 1;
	U8 LSBFIRST : 1;
	U8 SPE : 1;
	U8 BR : 3;
	U8 MSTR : 1;
	U8 CPOL : 1;
	U8 CPHA : 1;

}STM32_SPI_CR1_Cfg;

typedef struct
{
	U8 TXEIE : 1;
	U8 RXNEIE : 1;
	U8 ERRIE : 1;
	U8 FRF : 1;
	U8 RESERVED : 1;
	U8 SSOE : 1;
	U8 TXDMAEN : 1;
	U8 RXDMAEN : 1;

}STM32_SPI_CR2_Cfg;

typedef struct
{
	U8 FRE : 1;
	U8 BSY : 1;
	U8 OVR : 1;
	U8 MODF : 1;
	U8 CRCERR : 1;
	U8 UDR : 1;
	U8 CHSIDE : 1;
	U8 TXE : 1;
	U8 RXNE : 1;

}STM32_SPI_SR_Cfg;

typedef struct
{
	__vo U32 CR1;
	__vo U32 CR2;
	__vo U32 SR;
	__vo U32 DR;
	__vo U32 CRCPR;
	__vo U32 RXCRCR;
	__vo U32 TXCRCR;
	__vo U32 I2SCFGR;
	__vo U32 I2SPR;

}STM32_SPIRegDef_st;

// --------------------------------------------------------------------------------------------------------//
// API structs for managing SPI
// --------------------------------------------------------------------------------------------------------//

typedef struct
{
	U8 master;							// Master, slave
	U8 bustype; 						// Duplex, simplex, half duplex
	U8 rxonly;							// Receive data only
	U8 speed;							// SPI clock speed
	U8 dff;							// Data frame format - send 8/16 bits
	U8 cpha;
	U8 cpol;
	U8 ssm;							// Slave select management - sw/hw slave select
	U8 crcen;							// CRC Enable

}SPICfg_st;

typedef struct
{
	STM32_SPIRegDef_st *pSPIX;				// Pointer to the base address of the gpio reg
	SPICfg_st SPI_Cfg;						// Pointer to pin config struct

}SPIHandle_st;

// SPI base addresses and pointers
#define SPI1					(APB2 + 0x3000U)
#define SPI2					(APB1 + 0x3800U)
#define SPI3					(APB1 + 0x3C00U)

#define pSPI1					(STM32_SPIRegDef_st *)SPI1
#define pSPI2					(STM32_SPIRegDef_st *)SPI2
#define pSPI3					(STM32_SPIRegDef_st *)SPI3

// --------------------------------------------------------------------------------------------------------//
// SPI register level functions
// --------------------------------------------------------------------------------------------------------//

U32 STM32_Pack_SPI_CR1(STM32_SPI_CR1_Cfg *SPIX_CR1_CFG);
void STM32_Unpack_SPI_SR(STM32_SPI_SR_Cfg *SPIX_SR_CFG, U32 packed);

void SPI_ClkCtrl(SPIHandle_st* pSPI_Handle, U8 ClkCmd);
void SPI_Init(SPIHandle_st* pSPI_Handle);
void SPI_Reset(SPIHandle_st* pSPI_Handle);

U8 SPI_Bsy(SPIHandle_st* pSPI_Handle);
U8 SPI_RXMT(SPIHandle_st* pSPI_Handle);
U8 SPI_ErrCheck(SPIHandle_st* pSPI_Handle);

U8 SPI_Write(SPIHandle_st* pSPI_Handle, U8 data);
uint16_t SPI_Read(SPIHandle_st* pSPI_Handle);

#endif
