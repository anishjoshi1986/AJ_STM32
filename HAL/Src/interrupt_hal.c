/*
 * IRQConfig.c
 *
 *  Created on: Sep 30, 2025
 *      Author: anish
 */

#include "../Hdr/interrupt_hal.h"

void IRQConfig(uint8_t IRQn, uint8_t En)
{
	if(En)
	{
		if(IRQn <= 31)
		{
			*NVIC_ISER0 |= (1U << IRQn);
		}
		else if(IRQn > 31 && IRQn <= 63)
		{
			*NVIC_ISER1 |= (1U << (IRQn % 32));
		}
		else if(IRQn > 63)
		{
			*NVIC_ISER2 |= (1U << (IRQn % 32));
		}
	}
	else
	{
		if(IRQn <= 31)
		{
			*NVIC_ICER0 |= (1U << IRQn);
		}
		else if(IRQn > 31 && IRQn <= 63)
		{
			*NVIC_ICER1 |= (1U << (IRQn % 32));
		}
		else if(IRQn > 63)
		{
			*NVIC_ICER2 |= (1U << (IRQn % 32));
		}
	}
}

void IRQPriorityConfig(uint8_t IRQn, uint8_t IRQPriority)
{
	uint8_t temp1 = IRQn / 4;
	uint8_t temp2 = IRQn % 4;

	*(NVIC_IPR0 + 4*temp1) |= IRQPriority << (8 * temp2);
}

void EXTI0_IRQHandler (void)
{
	if(pEXTI->PR & 1)
		pEXTI->PR |= 1;

}

void TIM6_IRQHandler (void)
{

}

void TIM7_IRQHandler (void)
{

}
