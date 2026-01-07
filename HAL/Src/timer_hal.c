/*
 * timer_hal.c
 *
 *  Created on: Dec 30, 2025
 *      Author: anish
 */

#include "../Hdr/timer_hal.h"

uint16_t STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1)
{
	uint16_t packed = 0;

	packed |= (BTIMx_CR1->ARPE & 0x01) << 7;
	packed |= (BTIMx_CR1->OPM & 0x01) << 3;
	packed |= (BTIMx_CR1->URS & 0x01) << 2;
	packed |= (BTIMx_CR1->UDIS & 0x01) << 1;
	packed |= (BTIMx_CR1->CEN & 0x01) << 0;

	return packed;
}

void STM32_Unpack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1, uint16_t packed)
{
	BTIMx_CR1->ARPE = (packed >> 7) & 0x01;
	BTIMx_CR1->OPM = (packed >> 3) & 0x01;
	BTIMx_CR1->URS = (packed >> 2) & 0x01;
	BTIMx_CR1->UDIS = (packed >> 1) & 0x01;
	BTIMx_CR1->CEN = (packed >> 0) & 0x01;

}

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle)
{
	STM32_CLKSPDS clk_speeds = {0};
	STM32_Get_CLKSPDS(&clk_speeds);

	pBTIMx_Handle->pBTIMx->PSC = clk_speeds.SYSCLK / 1000;
	pBTIMx_Handle->pBTIMx->ARR = pBTIMx_Handle->BTIMx_Cfg.freq;

}
