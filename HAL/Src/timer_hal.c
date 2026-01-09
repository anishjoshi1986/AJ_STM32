/*
 * timer_hal.c
 *
 *  Created on: Dec 30, 2025
 *      Author: anish
 */

#include "../Hdr/timer_hal.h"

static U32 STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1)
{
	U32 packed = 0;

	packed |= (BTIMx_CR1->ARPE & 1U) << 7;
	packed |= (BTIMx_CR1->OPM & 1U) << 3;
	packed |= (BTIMx_CR1->URS & 1U) << 2;
	packed |= (BTIMx_CR1->UDIS & 1U) << 1;
	packed |= (BTIMx_CR1->CEN & 1U) << 0;

	return packed;
}

static void STM32_Unpack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1, U32 packed)
{
	BTIMx_CR1->ARPE = (packed >> 7) & 1U;
	BTIMx_CR1->OPM = (packed >> 3) & 1U;
	BTIMx_CR1->URS = (packed >> 2) & 1U;
	BTIMx_CR1->UDIS = (packed >> 1) & 1U;
	BTIMx_CR1->CEN = (packed >> 0) & 1U;

}

static U32 STM32_Pack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER)
{
	U32 packed = 0;

	packed |= (BTIMx_DIER->UDE & 1U) << 8;
	packed |= (BTIMx_DIER->UIE & 1U) << 0;

	return packed;
}

static void STM32_Unpack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER, U32 packed)
{
	BTIMx_DIER->UDE = (packed >> 8) & 1U;
	BTIMx_DIER->UIE = (packed >> 0) & 1U;

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
	U32 temp = pBTIMx_Handle->pBTIMx->CR1;
	pBTIMx_Handle->pBTIMx->CR1 = (temp & ~BTIMx_CR1_MASK) | (STM32_Pack_BTIMx_CR1(&BTIMx_CR1) & BTIMx_CR1_MASK);

	U32 prescaler = clk_speeds.TIMxCLK1 / (pBTIMx_Handle->BTIMx_Cfg.freq) / MAX_ARR;
	if(prescaler < UINT16_T_MAX)
		pBTIMx_Handle->pBTIMx->PSC = prescaler;
	else
		pBTIMx_Handle->pBTIMx->PSC = UINT16_T_MAX;

	pBTIMx_Handle->pBTIMx->ARR = MAX_ARR;

	STM32_BTIMx_DIER BTIMx_DIER = {0};
	BTIMx_DIER.UDE = UDE_ENABLE;
	BTIMx_DIER.UIE = UIE_ENABLE;
	pBTIMx_Handle->pBTIMx->DIER = STM32_Pack_BTIMx_DIER(&BTIMx_DIER);

}
