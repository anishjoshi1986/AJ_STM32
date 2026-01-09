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

uint16_t STM32_Pack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER)
{
	uint16_t packed = 0;

	packed |= (BTIMx_DIER->UDE & 0x01) << 8;
	packed |= (BTIMx_DIER->UIE & 0x01) << 0;

	return packed;
}

void STM32_Unpack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER, uint16_t packed)
{
	BTIMx_DIER->UDE = (packed >> 8) & 0x01;
	BTIMx_DIER->UIE = (packed >> 0) & 0x01;

}

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle)
{
	STM32_CLKSPDS clk_speeds = {0};
	STM32_Get_CLKSPDS(&clk_speeds);

	STM32_BTIMx_CR1 BTIMx_CR1 = {0};
	BTIMx_CR1.ARPE = ARPEBUF_ENABLE;
	BTIMx_CR1.OPM = OPM_ENABLE;
	BTIMx_CR1.URS = URS_ENABLE;
	BTIMx_CR1.UDIS = UDIS_ENABLE;
	BTIMx_CR1.CEN = CNT_ENABLE;
	pBTIMx_Handle->pBTIMx->CR1 = STM32_Pack_BTIMx_CR1(&BTIMx_CR1);

	uint32_t prescaler = clk_speeds.TIMxCLK1 / (pBTIMx_Handle->BTIMx_Cfg.freq) / MAX_ARR;
	if(prescaler < UINT16_T_MAX)
		pBTIMx_Handle->pBTIMx->PSC = (uint16_t)prescaler;
	else
		pBTIMx_Handle->pBTIMx->PSC = UINT16_T_MAX;

	pBTIMx_Handle->pBTIMx->ARR = MAX_ARR;

	STM32_BTIMx_DIER BTIMx_DIER = {0};
	BTIMx_DIER.UDE = UDE_ENABLE;
	BTIMx_DIER.UIE = UIE_ENABLE;
	pBTIMx_Handle->pBTIMx->DIER = STM32_Pack_BTIMx_DIER(&BTIMx_DIER);

}
