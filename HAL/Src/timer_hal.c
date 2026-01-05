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

void BTIMx_ClkCtrl(BTIMx_Handle_st *pBTIMx_Handle, uint8_t ClkCmd)
{
	if(ClkCmd == ENABLE)
	{
		if(pBTIMx_Handle->pBTIMx == pTIM6)
			TIM6_EN();
		if (pBTIMx_Handle->pBTIMx == pTIM7)
			TIM7_EN();
	}

	if(ClkCmd == DISABLE)
	{
		if(pBTIMx_Handle->pBTIMx == pTIM6)
			TIM6_DIS();
		if (pBTIMx_Handle->pBTIMx == pTIM7)
			TIM7_DIS();
	}

}

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle)
{
	// Determine SYSCLK


	// Unpack RCC_CFGR and get values of APB1 and AHB prescalers to determine input for TIMx_CLK
	STM32_RCC_CFGR RCC_CFGR;
	uint32_t packed = pRCC->CFGR;
	STM32_UnPack_RCC_CFGR(&RCC_CFGR, packed);
	float SYSCLK_FREQ = (float)HSI_FREQ / (float)(RCC_CFGR.HPRE * RCC_CFGR.PPRE1);

	pBTIMx_Handle->pBTIMx->PSC = SYSCLK_FREQ / 1000;
	pBTIMx_Handle->pBTIMx->ARR = pBTIMx_Handle->BTIMx_Cfg.freq;

	// Check if PLL is not ON
}
