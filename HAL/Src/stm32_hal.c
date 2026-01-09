/*
 * stm32_hal.c
 *
 *  Created on: Jan 3, 2026
 *      Author: anish
 */

#include "../Hdr/stm32_hal.h"

float MSIRANGE_ARR[7] = {65.536, 131.072, 262.144, 524.288, 1048, 2097, 4194};
float PLLMUL_ARR[9] = {3, 4, 6, 8, 12, 16, 24, 32, 48};
float HPRE_ARR[9] = {1, 2, 4, 8, 16, 64, 128, 256, 512};
float PPRE_ARR[5] = {1, 2, 4, 8, 16};

U32 STM32_Pack_RCC_CR(STM32_RCC_CR *RCC_CR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_CR_CFG->RTCPRE & 0x03U) << 29;
	packed |= (U32)(RCC_CR_CFG->CSSON & 1U) << 28;
	packed |= (U32)(RCC_CR_CFG->PLLON & 1U) << 24;
	packed |= (U32)(RCC_CR_CFG->HSEBYP & 1U) << 18;
	packed |= (U32)(RCC_CR_CFG->HSEON & 1U) << 16;
	packed |= (U32)(RCC_CR_CFG->MSION & 1U) << 8;
	packed |= (U32)(RCC_CR_CFG->HSION & 1U) << 0;

	return packed;
}

void STM32_UnPack_RCC_CR(STM32_RCC_CR *RCC_CR_CFG, U32 packed)
{
	RCC_CR_CFG->RTCPRE = (packed >> 29) & 0x03U;
	RCC_CR_CFG->CSSON = (packed >> 28) & 1U;
	RCC_CR_CFG->PLLRDY = (packed >> 25) & 1U;
	RCC_CR_CFG->PLLON = (packed >> 24) & 1U;
	RCC_CR_CFG->HSEBYP = (packed >> 18) & 1U;
	RCC_CR_CFG->HSERDY = (packed >> 17) & 1U;
	RCC_CR_CFG->HSEON = (packed >> 16) & 1U;
	RCC_CR_CFG->MSIRDY = (packed >> 9) & 1U;
	RCC_CR_CFG->MSION = (packed >> 8) & 1U;
	RCC_CR_CFG->HSIRDY = (packed >> 1) & 1U;
	RCC_CR_CFG->HSION = (packed >> 0) & 1U;

}


U32 STM32_Pack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_ICSCR_CFG->MSITRIM & 0xFF) << 24;
	packed |= (U32)(RCC_ICSCR_CFG->MSIRANGE & 0x07U) << 13;
	packed |= (U32)(RCC_ICSCR_CFG->HSITRIM & 0x1F) << 8;

	return packed;
}

void STM32_UnPack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR_CFG, U32 packed)
{
	RCC_ICSCR_CFG->MSITRIM = (packed >> 24) & 0xFF;
	RCC_ICSCR_CFG->MSIRANGE = (packed >> 13) & 0x07U;
	RCC_ICSCR_CFG->HSITRIM = (packed >> 8) & 0x1F;

}


U32 STM32_Pack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_CFGR_CFG->MCOPRE & 0x07U) << 28;
	packed |= (U32)(RCC_CFGR_CFG->MCOSEL & 0x07U) << 24;
	packed |= (U32)(RCC_CFGR_CFG->PLLDIV & 0x03U) << 22;
	packed |= (U32)(RCC_CFGR_CFG->PLLMUL & 0x0FU) << 18;
	packed |= (U32)(RCC_CFGR_CFG->PLLSRC & 1U) << 16;
	packed |= (U32)(RCC_CFGR_CFG->PPRE2 & 0x07U) << 11;
	packed |= (U32)(RCC_CFGR_CFG->PPRE1 & 0x07U) << 8;
	packed |= (U32)(RCC_CFGR_CFG->HPRE & 0x0FU) << 4;
	packed |= (U32)(RCC_CFGR_CFG->SW & 0x03U) << 0;

	return packed;
}

void STM32_UnPack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR_CFG, U32 packed)
{
	RCC_CFGR_CFG->MCOPRE = (packed >> 28) & 0x07U;
	RCC_CFGR_CFG->MCOSEL = (packed >> 24) & 0x07U;
	RCC_CFGR_CFG->PLLDIV = (packed >> 22) & 0x03U;
	RCC_CFGR_CFG->PLLMUL = (packed >> 18) & 0x0FU;
	RCC_CFGR_CFG->PLLSRC = (packed >> 16) & 1U;
	RCC_CFGR_CFG->PPRE2 = (packed >> 11) & 0x07U;
	RCC_CFGR_CFG->PPRE1 = (packed >> 8) & 0x07U;
	RCC_CFGR_CFG->HPRE = (packed >> 4) & 0x0FU;
	RCC_CFGR_CFG->SWS = (packed >> 2) & 0x03U;
	RCC_CFGR_CFG->SW = (packed >> 0) & 0x03U;

}


U32 STM32_Pack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_AHBENR_CFG->FSMCEN & 1U) << 30;
	packed |= (U32)(RCC_AHBENR_CFG->AESEN & 1U) << 27;
	packed |= (U32)(RCC_AHBENR_CFG->DMA2EN & 1U) << 25;
	packed |= (U32)(RCC_AHBENR_CFG->DMA1EN & 1U) << 24;
	packed |= (U32)(RCC_AHBENR_CFG->FLITFEN & 1U) << 15;
	packed |= (U32)(RCC_AHBENR_CFG->CRCEN & 1U) << 12;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOGEN & 1U) << 7;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOFEN & 1U) << 6;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOHEN & 1U) << 5;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOEEN & 1U) << 4;
	packed |= (U32)(RCC_AHBENR_CFG->GPIODEN & 1U) << 3;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOCEN & 1U) << 2;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOBEN & 1U) << 1;
	packed |= (U32)(RCC_AHBENR_CFG->GPIOAEN & 1U) << 0;


	return packed;
}

void STM32_UnPack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR_CFG, U32 packed)
{
	RCC_AHBENR_CFG->FSMCEN = (packed >> 30) & 1U;
	RCC_AHBENR_CFG->AESEN = (packed >> 27) & 1U;
	RCC_AHBENR_CFG->DMA2EN = (packed >> 25) & 1U;
	RCC_AHBENR_CFG->DMA1EN = (packed >> 24) & 1U;
	RCC_AHBENR_CFG->FLITFEN = (packed >> 15) & 1U;
	RCC_AHBENR_CFG->CRCEN = (packed >> 12) & 1U;
	RCC_AHBENR_CFG->GPIOGEN = (packed >> 7) & 1U;
	RCC_AHBENR_CFG->GPIOFEN = (packed >> 6) & 1U;
	RCC_AHBENR_CFG->GPIOHEN = (packed >> 5) & 1U;
	RCC_AHBENR_CFG->GPIOEEN = (packed >> 4) & 1U;
	RCC_AHBENR_CFG->GPIODEN = (packed >> 3) & 1U;
	RCC_AHBENR_CFG->GPIOCEN = (packed >> 2) & 1U;
	RCC_AHBENR_CFG->GPIOBEN = (packed >> 1) & 1U;
	RCC_AHBENR_CFG->GPIOAEN = (packed >> 0) & 1U;

}


U32 STM32_Pack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_APB2ENR_CFG->USART1EN & 1U) << 15;
	packed |= (U32)(RCC_APB2ENR_CFG->SPIEN & 1U) << 12;
	packed |= (U32)(RCC_APB2ENR_CFG->SDIOEN & 1U) << 10;
	packed |= (U32)(RCC_APB2ENR_CFG->ADC1EN & 1U) << 9;
	packed |= (U32)(RCC_APB2ENR_CFG->TIM11EN & 1U) << 4;
	packed |= (U32)(RCC_APB2ENR_CFG->TIM10EN & 1U) << 3;
	packed |= (U32)(RCC_APB2ENR_CFG->TIM9EN & 1U) << 2;
	packed |= (U32)(RCC_APB2ENR_CFG->SYSCFGEN & 1U) << 0;

	return packed;
}

void STM32_UnPack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR_CFG, U32 packed)
{
	RCC_APB2ENR_CFG->USART1EN = (packed >> 15) & 1U;
	RCC_APB2ENR_CFG->SPIEN = (packed >> 12) & 1U;
	RCC_APB2ENR_CFG->SDIOEN = (packed >> 10) & 1U;
	RCC_APB2ENR_CFG->ADC1EN = (packed >> 9) & 1U;
	RCC_APB2ENR_CFG->TIM11EN = (packed >> 4) & 1U;
	RCC_APB2ENR_CFG->TIM10EN = (packed >> 3) & 1U;
	RCC_APB2ENR_CFG->TIM9EN = (packed >> 2) & 1U;
	RCC_APB2ENR_CFG->SYSCFGEN = (packed >> 0) & 1U;
}


U32 STM32_Pack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR_CFG)
{
	U32 packed = 0;

	packed |= (U32)(RCC_APB1ENR_CFG->COMPEN & 1U) << 31;
	packed |= (U32)(RCC_APB1ENR_CFG->DACEN & 1U) << 29;
	packed |= (U32)(RCC_APB1ENR_CFG->PWREN & 1U) << 28;
	packed |= (U32)(RCC_APB1ENR_CFG->USBEN & 1U) << 23;
	packed |= (U32)(RCC_APB1ENR_CFG->I2C2EN & 1U) << 22;
	packed |= (U32)(RCC_APB1ENR_CFG->I2C1EN & 1U) << 21;
	packed |= (U32)(RCC_APB1ENR_CFG->UART5EN & 1U) << 20;
	packed |= (U32)(RCC_APB1ENR_CFG->UART4EN & 1U) << 19;
	packed |= (U32)(RCC_APB1ENR_CFG->USART3EN & 1U) << 18;
	packed |= (U32)(RCC_APB1ENR_CFG->USART2EN & 1U) << 17;
	packed |= (U32)(RCC_APB1ENR_CFG->SPI3EN & 1U) << 15;
	packed |= (U32)(RCC_APB1ENR_CFG->SPI2EN & 1U) << 14;
	packed |= (U32)(RCC_APB1ENR_CFG->WWDEN & 1U) << 11;
	packed |= (U32)(RCC_APB1ENR_CFG->LCDEN & 1U) << 9;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM7EN & 1U) << 5;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM6EN & 1U) << 4;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM5EN & 1U) << 3;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM4EN & 1U) << 2;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM3EN & 1U) << 1;
	packed |= (U32)(RCC_APB1ENR_CFG->TIM2EN & 1U) << 0;

	return packed;
}

void STM32_UnPack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR_CFG, U32 packed)
{
	RCC_APB1ENR_CFG->COMPEN = (packed >> 31) & 1U;
	RCC_APB1ENR_CFG->DACEN = (packed >> 29) & 1U;
	RCC_APB1ENR_CFG->PWREN = (packed >> 28) & 1U;
	RCC_APB1ENR_CFG->USBEN = (packed >> 23) & 1U;
	RCC_APB1ENR_CFG->I2C2EN = (packed >> 22) & 1U;
	RCC_APB1ENR_CFG->I2C1EN = (packed >> 21) & 1U;
	RCC_APB1ENR_CFG->UART5EN = (packed >> 20) & 1U;
	RCC_APB1ENR_CFG->UART4EN = (packed >> 19) & 1U;
	RCC_APB1ENR_CFG->USART3EN = (packed >> 18) & 1U;
	RCC_APB1ENR_CFG->USART2EN = (packed >> 17) & 1U;
	RCC_APB1ENR_CFG->SPI3EN = (packed >> 15) & 1U;
	RCC_APB1ENR_CFG->SPI2EN = (packed >> 14) & 1U;
	RCC_APB1ENR_CFG->WWDEN = (packed >> 11) & 1U;
	RCC_APB1ENR_CFG->LCDEN = (packed >> 9) & 1U;
	RCC_APB1ENR_CFG->TIM7EN = (packed >> 5) & 1U;
	RCC_APB1ENR_CFG->TIM6EN = (packed >> 4) & 1U;
	RCC_APB1ENR_CFG->TIM5EN = (packed >> 3) & 1U;
	RCC_APB1ENR_CFG->TIM4EN = (packed >> 2) & 1U;
	RCC_APB1ENR_CFG->TIM3EN = (packed >> 1) & 1U;
	RCC_APB1ENR_CFG->TIM2EN = (packed >> 0) & 1U;

}

void STM32_ClkSys_Init(STM32_RCC_CR *RCC_CR_CFG, STM32_RCC_CFGR *RCC_CFGR_CFG, \
		STM32_RCC_AHBENR *RCC_AHBENR_CFG, STM32_RCC_APB1ENR *RCC_APB1ENR_CFG, \
		STM32_RCC_APB2ENR *RCC_APB2ENR_CFG)
{
	pRCC->CR = (pRCC->CR & ~RCC_CR_MASK) | (STM32_Pack_RCC_CR(RCC_CR_CFG) & RCC_CR_MASK);

	pRCC->CFGR = (pRCC->CFGR & ~RCC_CFGR_MASK) | (STM32_Pack_RCC_CFGR(RCC_CFGR_CFG) & RCC_CFGR_MASK);

	pRCC->AHBENR = (pRCC->AHBENR & ~RCC_AHBENR_MASK) | (STM32_Pack_RCC_AHBENR(RCC_AHBENR_CFG) & RCC_AHBENR_MASK);

	pRCC->APB1ENR = (pRCC->APB1ENR & ~RCC_APB1ENR_MASK) | (STM32_Pack_RCC_APB1ENR(RCC_APB1ENR_CFG) & RCC_APB1ENR_MASK);

	pRCC->APB2ENR = (pRCC->APB2ENR & ~RCC_APB2ENR_MASK) | (STM32_Pack_RCC_APB2ENR(RCC_APB2ENR_CFG) & RCC_APB2ENR_MASK);

}

void STM32_Get_CLKSPDS(STM32_CLKSPDS *clk_speeds)
{
	if(MSI_ENABLE)
	{
		clk_speeds->SYSCLK = MSIRANGE_ARR[MSIRANGE_IND];
	}

	if(HSI_ENABLE)
	{
		clk_speeds->SYSCLK = HSI_FREQ;
	}

	if(HSE_ENABLE)
	{
		clk_speeds->SYSCLK = HSE_FREQ;
	}

	if(PLL_ENABLE)
	{
		if(PLLSRC_VAL)
			clk_speeds->SYSCLK = (HSE_FREQ * PLLMUL_ARR[PLLMUL_IND]) /  (PLLDIV_VAL + 1);
		else
			clk_speeds->SYSCLK = (HSI_FREQ * PLLMUL_ARR[PLLMUL_IND]) /  (PLLDIV_VAL + 1);
	}

	clk_speeds->ADCCLK = HSI_FREQ;

	clk_speeds->HCLK = clk_speeds->SYSCLK / HPRE_ARR[HPRE_IND];

	clk_speeds->PCLK1 = clk_speeds->HCLK / PPRE_ARR[PPRE1_IND];

	clk_speeds->PCLK2 = clk_speeds->HCLK / PPRE_ARR[PPRE2_IND];

	if(PPRE_ARR[PPRE1_IND] == 1)
		clk_speeds->TIMxCLK1 = clk_speeds->PCLK1;
	else
		clk_speeds->TIMxCLK1 = 2 * clk_speeds->PCLK1;

	if(PPRE_ARR[PPRE2_IND] == 1)
		clk_speeds->TIMxCLK2 = clk_speeds->PCLK2;
	else
		clk_speeds->TIMxCLK2 = 2 * clk_speeds->PCLK2;
}
