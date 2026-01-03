/*
 * stm32l152xx.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32_HAL_H_
#define STM32_HAL_H_

#include <stdint.h>
#include "generic_macros.h"

// ----------------------------------------------------------------------------------------------------//
// Base addresses of different memory sections - found from memory map in STM32L15xRC datasheet
// ----------------------------------------------------------------------------------------------------//
#define FLASH 					0x08000000U
#define SRAM					0x20000000U
#define EEPROM					0x08080000U
#define ROM						0x1FF00000U
#define CORTEXM3				0xE0000000U

// --------------------------------------------------------------------------------------------------------//
// Base addresses of different buses - found from memory map/reg boundary addresses in RM
// --------------------------------------------------------------------------------------------------------//
#define APB1					0x40000000U
#define APB2					0x40010000U
#define AHB						0x40020000U

// ----------------------------------------------------------------------------------------------------//
// RCC peripheral address on AHB & reg struct - found from memory map/reg boundary addresses in RM
// ----------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t ICSCR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t AHBLPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t APB1LPENR;
	__vo uint32_t CSR;

}STM32_RCCRegDef_st;

#define RCC						(AHB + 0x3800U)
#define pRCC					((STM32_RCCRegDef_st *)RCC)

typedef struct
{
	uint8_t RTCPRE : 2;
	uint8_t CSSON : 1;
	uint8_t PLLRDY : 1;
	uint8_t PLLON : 1;
	uint8_t HSEBYP : 1;
	uint8_t HSERDY : 1;
	uint8_t HSEON : 1;
	uint8_t MSIRDY : 1;
	uint8_t MSION : 1;
	uint8_t HSIRDY : 1;
	uint8_t HSION : 1;

}STM32_RCC_CR;

typedef struct
{
	uint8_t MCOPRE : 3;
	uint8_t MCOSEL : 3;
	uint8_t PLLDIV : 2;
	uint8_t PLLMUL : 4;
	uint8_t PLLSRC : 1;
	uint8_t PPRE2 : 3;
	uint8_t PPRE1 : 3;
	uint8_t HPRE : 4;
	uint8_t SWS : 2;
	uint8_t SW : 2;

}STM32_RCC_CFGR;

uint32_t STM32_Pack_RCC_CR(STM32_RCC_CR *RCC_CR);
void STM32_UnPack_RCC_CR(STM32_RCC_CR *RCC_CR, uint32_t packed);

uint32_t STM32_Pack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR);
void STM32_UnPack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR, uint32_t packed);

// --------------------------------------------------------------------------------------------------------//
// SYSCFG register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
}STM32_SYSCFGRegDef_st;

#define SYSCFG					(APB2 + 0x0000)
#define pSYSCFG					((STM32_SYSCFGRegDef_st *)SYSCFG)

#define SYSCFG_CLK_EN()			(pRCC->APB2ENR |= 1)					// Clock En/Dis
#define SYSCFG_CLK_DIS()		(pRCC->APB2ENR &= ~1)


// --------------------------------------------------------------------------------------------------------//
// SYSCFG register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{

}STM32_RCC_ICSCR;

typedef struct
{

}STM32_RCC_CIR;

typedef struct
{

}STM32_RCC_AHBRSTR;

typedef struct
{

}STM32_RCC_APB2RSTR;

typedef struct
{

}STM32_RCC_APB1RSTR;

typedef struct
{

}STM32_RCC_AHBENR;

typedef struct
{

}STM32_RCC_APB2ENR;

typedef struct
{

}STM32_RCC_APB1ENR;

typedef struct
{

}STM32_RCC_AHBLPENR;

typedef struct
{

}STM32_RCC_APB2LPENR;

typedef struct
{

}STM32_RCC_APB1LPENR;

typedef struct
{

}STM32_RCC_CSR;

#endif /* STM32L152XX_H_ */
