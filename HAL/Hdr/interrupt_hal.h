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
	__vo U32 IMR;
	__vo U32 EMR;
	__vo U32 RTSR;
	__vo U32 FTSR;
	__vo U32 SWIER;
	__vo U32 PR;
}EXTI_RegDef_st;

#define EXTI					(APB2 + 0x0400)
#define pEXTI					((EXTI_RegDef_st *)EXTI)

#define IRQ_NO_EXTI0			6U										// Interrupt positions in NVIC
#define IRQ_NO_EXTI1			7U
#define IRQ_NO_EXTI2			8U
#define IRQ_NO_EXTI3			9U
#define IRQ_NO_EXTI4			10U
#define IRQ_NO_EXTI9_5			23U
#define IRQ_NO_EXTI15_10		40U

#define IRQ_NO_TIM6				43U
#define IRQ_NO_TIM7				44U

// --------------------------------------------------------------------------------------------------------//
// Cortex M3 NVIC register definition
// --------------------------------------------------------------------------------------------------------//
#define NVIC_ISER0				(__vo U32 *)0xE000E100U
#define NVIC_ISER1				(__vo U32 *)0xE000E104U
#define NVIC_ISER2				(__vo U32 *)0xE000E108U

#define NVIC_ICER0				(__vo U32 *)0xE000E180U
#define NVIC_ICER1				(__vo U32 *)0xE000E184U
#define NVIC_ICER2				(__vo U32 *)0xE000E188U

#define NVIC_IPR0				(__vo U32 *)0xE000E400U

// --------------------------------------------------------------------------------------------------------//
// Set Cortex M3 interrupts
// --------------------------------------------------------------------------------------------------------//
void IRQConfig(U8 IRQn, U8 En);
void IRQPriorityConfig(U8 IRQn, U8 IRQPriority);


#endif /* HAL_HDR_INTERRUPT_HAL_H_ */
