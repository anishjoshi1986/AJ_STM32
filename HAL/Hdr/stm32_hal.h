/*
 * stm32l152xx.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32_HAL_H_
#define STM32_HAL_H_

#include <stdint.h>

#define __vo					volatile

// --------------------------------------------------------------------------------------------------------//
// Generic macros
// --------------------------------------------------------------------------------------------------------//

#define TRUE		1
#define FALSE		0
#define SET			TRUE
#define RESET		FALSE
#define ENABLE		TRUE
#define DISABLE		FALSE

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
// Base addresses of different buses - found from memory map/reg boundary addresses in RM
// ----------------------------------------------------------------------------------------------------//
#define PERIOD_100MS			0.1F
#define PERIOD_10MS				0.01F
#define PERIOD_1MS				0.001F

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

}RCC_RegDef_st;

#define RCC						(AHB + 0x3800U)
#define pRCC					((RCC_RegDef_st *)RCC)

#define SYSCFG_CLK_EN()			(pRCC->APB2ENR |= 1)					// Clock En/Dis
#define SYSCFG_CLK_DIS()		(pRCC->APB2ENR &= ~1)

#define HSI_4_SYSCLK()			(pRCC->CFGR |= 1)						// Select HSI clock to drive SYSCLK

// --------------------------------------------------------------------------------------------------------//
// SYSCFG register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
}SYSCFG_RegDef_st;

#define SYSCFG					(APB2 + 0x0000)
#define pSYSCFG					((SYSCFG_RegDef_st *)SYSCFG)

#endif /* STM32L152XX_H_ */
