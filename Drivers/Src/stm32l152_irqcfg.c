/*
 * IRQConfig.c
 *
 *  Created on: Sep 30, 2025
 *      Author: anish
 */

#include <stdint.h>
#include <stm32l152xx.h>

void IRQConfig(uint8_t IRQn, uint8_t En)
{
	if(En)
	{
		if(IRQn <= 31)
		{
			*NVIC_ISER0 |= (1 << IRQn);
		}
		else if(IRQn > 31 && IRQn <= 63)
		{
			*NVIC_ISER1 |= (1 << (IRQn % 32));
		}
		else if(IRQn > 63)
		{
			*NVIC_ISER2 |= (1 << (IRQn % 32));
		}
	}
	else
	{
		if(IRQn <= 31)
		{
			*NVIC_ISER0 &= (1 << IRQn);
		}
		else if(IRQn > 31 && IRQn <= 63)
		{
			*NVIC_ISER1 &= (1 << (IRQn % 32));
		}
		else if(IRQn > 63)
		{
			*NVIC_ISER2 &= (1 << (IRQn % 32));
		}
	}
}

void IRQPriorityConfig(uint8_t IRQn, uint8_t IRQPriority)
{
	uint8_t temp1 = IRQn / 4;
	uint8_t temp2 = IRQn % 4;

	*(NVIC_IPR0 + 4*temp1) |= IRQPriority << (8 * temp2);
}
