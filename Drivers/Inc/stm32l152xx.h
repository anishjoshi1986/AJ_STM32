/*
 * stm32l152xx.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32L152XX_H_
#define STM32L152XX_H_

#include <stdint.h>

#define __vo					volatile

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
// GPIO peripheral address on AHB & reg struct - found from memory map/reg boundary addresses in RM
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
	__vo uint32_t BRR;

}GPIO_RegDef_st;

#define GPIOA					(AHB + 0x0000U)
#define GPIOB					(AHB + 0x0400U)
#define GPIOC					(AHB + 0x0800U)
#define GPIOD					(AHB + 0x0C00U)
#define GPIOE					(AHB + 0x1000U)
#define GPIOH					(AHB + 0x1400U)
#define GPIOF					(AHB + 0x1800U)
#define GPIOG					(AHB + 0x1C00U)

#define pGPIOA					(GPIO_RegDef_st *)GPIOA
#define pGPIOB					(GPIO_RegDef_st *)GPIOB
#define pGPIOC					(GPIO_RegDef_st *)GPIOC
#define pGPIOD					(GPIO_RegDef_st *)GPIOD
#define pGPIOE					(GPIO_RegDef_st *)GPIOE
#define pGPIOH					(GPIO_RegDef_st *)GPIOH
#define pGPIOF					(GPIO_RegDef_st *)GPIOF
#define pGPIOG					(GPIO_RegDef_st *)GPIOG

#define GPIOA_CLK_EN()			(pRCC->AHBENR |= 1 << 0)		// Peripheral clock enable for GPIO peripherals
#define GPIOB_CLK_EN()			(pRCC->AHBENR |= 1 << 1)
#define GPIOC_CLK_EN()			(pRCC->AHBENR |= 1 << 2)
#define GPIOD_CLK_EN()			(pRCC->AHBENR |= 1 << 3)
#define GPIOE_CLK_EN()			(pRCC->AHBENR |= 1 << 4)
#define GPIOH_CLK_EN()			(pRCC->AHBENR |= 1 << 5)
#define GPIOF_CLK_EN()			(pRCC->AHBENR |= 1 << 6)
#define GPIOG_CLK_EN()			(pRCC->AHBENR |= 1 << 7)

#define GPIOA_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 0))		// Peripheral clock disable for GPIO peripherals
#define GPIOB_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 1))
#define GPIOC_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 2))
#define GPIOD_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 3))
#define GPIOE_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 4))
#define GPIOH_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 5))
#define GPIOF_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 6))
#define GPIOG_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 7))

#define GPIOA_RESET()			do{pRCC->AHBRSTR |= 1 << 0;pRCC->AHBRSTR &= ~(1 << 0);}while(0) 	// GPIO reset
#define GPIOB_RESET()			do{pRCC->AHBRSTR |= 1 << 1;pRCC->AHBRSTR &= ~(1 << 1);}while(0)
#define GPIOC_RESET()			do{pRCC->AHBRSTR |= 1 << 2;pRCC->AHBRSTR &= ~(1 << 2);}while(0)
#define GPIOD_RESET()			do{pRCC->AHBRSTR |= 1 << 3;pRCC->AHBRSTR &= ~(1 << 3);}while(0)
#define GPIOE_RESET()			do{pRCC->AHBRSTR |= 1 << 4;pRCC->AHBRSTR &= ~(1 << 4);}while(0)
#define GPIOH_RESET()			do{pRCC->AHBRSTR |= 1 << 5;pRCC->AHBRSTR &= ~(1 << 5);}while(0)
#define GPIOF_RESET()			do{pRCC->AHBRSTR |= 1 << 6;pRCC->AHBRSTR &= ~(1 << 6);}while(0)
#define GPIOG_RESET()			do{pRCC->AHBRSTR |= 1 << 7;pRCC->AHBRSTR &= ~(1 << 7);}while(0)

// GPIO register macros

// GPIO MODE register
#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFN			2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_INTFE			4
#define GPIO_MODE_INTRE			5
#define GPIO_MODE_INTFRE		6

// GPIO OTYPE register
#define GPIO_OTYPE_PP			0
#define GPIO_OTYPE_OD			1

// GPIO OSPEED register
#define GPIO_OSPEED_L			0
#define GPIO_OSPEED_M			1
#define GPIO_OSPEED_H			2
#define GPIO_OSPEED_VH			3

// GPIO PUPD register
#define GPIO_PUPD_NO			0
#define GPIO_PUPD_PU			1
#define GPIO_PUPD_PD			2
#define GPIO_PUPD_RES			3

// GPIO Pin Numbers
#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7



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

// --------------------------------------------------------------------------------------------------------//
// Generic macros
// --------------------------------------------------------------------------------------------------------//

#define TRUE		1
#define FALSE		0
#define SET			TRUE
#define RESET		FALSE


#endif /* STM32L152XX_H_ */
