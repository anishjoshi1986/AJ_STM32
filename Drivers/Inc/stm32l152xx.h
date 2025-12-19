/*
 * stm32l152xx.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32L152XX_H_
#define STM32L152XX_H_

#include <stdint.h>

#define __vo	volatile

// --------------------------------------------------------------------------------------------------------//
// Generic macros
// --------------------------------------------------------------------------------------------------------//

#define TRUE		1
#define FALSE		0
#define SET			TRUE
#define RESET		FALSE

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

}RCC_RegDef_st;

#define RCC						(AHB + 0x3800U)
#define pRCC					((RCC_RegDef_st *)RCC)

// --------------------------------------------------------------------------------------------------------//
// EXTI register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_st;

#define EXTI					(APB2 + 0x0400)
#define pEXTI					((EXTI_RegDef_st *)EXTI)

#define SYSCFG_CLK_EN()			(pRCC->APB2ENR |= 1)					// Clock En/Dis
#define SYSCFG_CLK_DIS()		(pRCC->APB2ENR &= ~1)

#define IRQ_NO_EXTI0			6										// Interrupt positions in NVIC
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40

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

// --------------------------------------------------------------------------------------------------------//
// Cortex M3 NVIC register definition
// --------------------------------------------------------------------------------------------------------//
#define NVIC_ISER0				(__vo uint32_t *)0xE000E100U
#define NVIC_ISER1				(__vo uint32_t *)0xE000E104U
#define NVIC_ISER2				(__vo uint32_t *)0xE000E108U

#define NVIC_ICER0				(__vo uint32_t *)0xE000E180U
#define NVIC_ICER1				(__vo uint32_t *)0xE000E184U
#define NVIC_ICER2				(__vo uint32_t *)0xE000E188U

#define NVIC_IPR0				(__vo uint32_t *)0xE000E400U

// --------------------------------------------------------------------------------------------------------//
// Set Cortex M3 interrupts
// --------------------------------------------------------------------------------------------------------//
void IRQConfig(uint8_t IRQn, uint8_t En);
void IRQPriorityConfig(uint8_t IRQn, uint8_t IRQPriority);


#endif /* STM32L152XX_H_ */
