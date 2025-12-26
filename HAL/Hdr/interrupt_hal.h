/*
 * interrupt_hal.h
 *
 *  Created on: Dec 26, 2025
 *      Author: anish
 */

#ifndef HAL_HDR_INTERRUPT_HAL_H_
#define HAL_HDR_INTERRUPT_HAL_H_

#include "stm32_hal.h"

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

#define IRQ_NO_EXTI0			6										// Interrupt positions in NVIC
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI9_5			23
#define IRQ_NO_EXTI15_10		40

#define IRQ_NO_TIM2				28

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


#endif /* HAL_HDR_INTERRUPT_HAL_H_ */
