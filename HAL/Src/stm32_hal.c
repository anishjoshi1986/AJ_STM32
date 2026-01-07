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

uint32_t STM32_Pack_RCC_CR(STM32_RCC_CR *RCC_CR)
{
	uint32_t packed = 0;

	packed |= (RCC_CR->RTCPRE & 0x03) << 29;
	packed |= (RCC_CR->CSSON & 0x01) << 28;
	packed |= (RCC_CR->PLLON & 0x01) << 24;
	packed |= (RCC_CR->HSEBYP & 0x01) << 18;
	packed |= (RCC_CR->HSEON & 0x01) << 16;
	packed |= (RCC_CR->MSION & 0x01) << 8;
	packed |= (RCC_CR->HSION & 0x01) << 0;

	uint32_t temp = pRCC->CR;
	temp &= ~RCC_CR_MASK;
	temp |= (packed & RCC_CR_MASK);

	return temp;
}

void STM32_UnPack_RCC_CR(STM32_RCC_CR *RCC_CR, uint32_t packed)
{
	RCC_CR->RTCPRE = (packed >> 29) & 0x03;
	RCC_CR->CSSON = (packed >> 28) & 0x01;
	RCC_CR->PLLRDY = (packed >> 25) & 0x01;
	RCC_CR->PLLON = (packed >> 24) & 0x01;
	RCC_CR->HSEBYP = (packed >> 18) & 0x01;
	RCC_CR->HSERDY = (packed >> 17) & 0x01;
	RCC_CR->HSEON = (packed >> 16) & 0x01;
	RCC_CR->MSIRDY = (packed >> 9) & 0x01;
	RCC_CR->MSION = (packed >> 8) & 0x01;
	RCC_CR->HSIRDY = (packed >> 1) & 0x01;
	RCC_CR->HSION = (packed >> 0) & 0x01;

}


uint32_t STM32_Pack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR)
{
	uint32_t packed = 0;

	packed |= (RCC_ICSCR->MSITRIM & 0xFF) << 24;
	packed |= (RCC_ICSCR->MSIRANGE & 0x07) << 13;
	packed |= (RCC_ICSCR->HSITRIM & 0x1F) << 8;

	uint32_t temp = pRCC->ICSCR;
	temp &= ~RCC_ICSCR_MASK;
	temp |= (packed & RCC_ICSCR_MASK);

	return packed;
}

void STM32_UnPack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR, uint32_t packed)
{
	RCC_ICSCR->MSITRIM = (packed >> 24) & 0xFF;
	RCC_ICSCR->MSIRANGE = (packed >> 13) & 0x07;
	RCC_ICSCR->HSITRIM = (packed >> 8) & 0x1F;

}


uint32_t STM32_Pack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR)
{
	uint32_t packed = 0;

	packed |= (RCC_CFGR->MCOPRE & 0x07) << 28;
	packed |= (RCC_CFGR->MCOSEL & 0x07) << 24;
	packed |= (RCC_CFGR->PLLDIV & 0x03) << 22;
	packed |= (RCC_CFGR->PLLMUL & 0x0F) << 18;
	packed |= (RCC_CFGR->PLLSRC & 0x01) << 16;
	packed |= (RCC_CFGR->PPRE2 & 0x07) << 11;
	packed |= (RCC_CFGR->PPRE1 & 0x07) << 8;
	packed |= (RCC_CFGR->HPRE & 0x0F) << 4;
	packed |= (RCC_CFGR->SW & 0x03) << 0;

	uint32_t temp = pRCC->CFGR;
	temp &= ~RCC_CFGR_MASK;
	temp |= (packed & RCC_CFGR_MASK);

	return packed;
}

void STM32_UnPack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR, uint32_t packed)
{
	RCC_CFGR->MCOPRE = (packed >> 28) & 0x07;
	RCC_CFGR->MCOSEL = (packed >> 24) & 0x07;
	RCC_CFGR->PLLDIV = (packed >> 22) & 0x03;
	RCC_CFGR->PLLMUL = (packed >> 18) & 0x0F;
	RCC_CFGR->PLLSRC = (packed >> 16) & 0x01;
	RCC_CFGR->PPRE2 = (packed >> 11) & 0x07;
	RCC_CFGR->PPRE1 = (packed >> 8) & 0x07;
	RCC_CFGR->HPRE = (packed >> 4) & 0x0F;
	RCC_CFGR->SWS = (packed >> 2) & 0x03;
	RCC_CFGR->SW = (packed >> 0) & 0x03;

}


uint32_t STM32_Pack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR)
{
	uint32_t packed = 0;

	packed |= (RCC_AHBENR->FSMCEN & 0x01) << 30;
	packed |= (RCC_AHBENR->AESEN & 0x01) << 27;
	packed |= (RCC_AHBENR->DMA2EN & 0x01) << 25;
	packed |= (RCC_AHBENR->DMA1EN & 0x01) << 24;
	packed |= (RCC_AHBENR->FLITFEN & 0x01) << 15;
	packed |= (RCC_AHBENR->CRCEN & 0x01) << 12;
	packed |= (RCC_AHBENR->GPIOGEN & 0x01) << 7;
	packed |= (RCC_AHBENR->GPIOFEN & 0x01) << 6;
	packed |= (RCC_AHBENR->GPIOHEN & 0x01) << 5;
	packed |= (RCC_AHBENR->GPIOEEN & 0x01) << 4;
	packed |= (RCC_AHBENR->GPIODEN & 0x01) << 3;
	packed |= (RCC_AHBENR->GPIOCEN & 0x01) << 2;
	packed |= (RCC_AHBENR->GPIOBEN & 0x01) << 1;
	packed |= (RCC_AHBENR->GPIOAEN & 0x01) << 0;


	return packed;
}

void STM32_UnPack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR, uint32_t packed)
{
	RCC_AHBENR->FSMCEN = (packed >> 30) & 0x01;
	RCC_AHBENR->AESEN = (packed >> 27) & 0x01;
	RCC_AHBENR->DMA2EN = (packed >> 25) & 0x01;
	RCC_AHBENR->DMA1EN = (packed >> 24) & 0x01;
	RCC_AHBENR->FLITFEN = (packed >> 15) & 0x01;
	RCC_AHBENR->CRCEN = (packed >> 12) & 0x01;
	RCC_AHBENR->GPIOGEN = (packed >> 7) & 0x01;
	RCC_AHBENR->GPIOFEN = (packed >> 6) & 0x01;
	RCC_AHBENR->GPIOHEN = (packed >> 5) & 0x01;
	RCC_AHBENR->GPIOEEN = (packed >> 4) & 0x01;
	RCC_AHBENR->GPIODEN = (packed >> 3) & 0x01;
	RCC_AHBENR->GPIOCEN = (packed >> 2) & 0x01;
	RCC_AHBENR->GPIOBEN = (packed >> 1) & 0x01;
	RCC_AHBENR->GPIOAEN = (packed >> 0) & 0x01;

}


uint32_t STM32_Pack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR)
{
	uint32_t packed = 0;

	packed |= (RCC_APB2ENR->USART1EN & 0x01) << 15;
	packed |= (RCC_APB2ENR->SPIEN & 0x01) << 12;
	packed |= (RCC_APB2ENR->SDIOEN & 0x01) << 10;
	packed |= (RCC_APB2ENR->ADC1EN & 0x01) << 9;
	packed |= (RCC_APB2ENR->TIM11EN & 0x01) << 4;
	packed |= (RCC_APB2ENR->TIM10EN & 0x01) << 3;
	packed |= (RCC_APB2ENR->TIM9EN & 0x01) << 2;
	packed |= (RCC_APB2ENR->SYSCFGEN & 0x01) << 0;

	return packed;
}
void STM32_UnPack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR, uint32_t packed)
{
	RCC_APB2ENR->USART1EN = (packed >> 15) & 0x01;
	RCC_APB2ENR->SPIEN = (packed >> 12) & 0x01;
	RCC_APB2ENR->SDIOEN = (packed >> 10) & 0x01;
	RCC_APB2ENR->ADC1EN = (packed >> 9) & 0x01;
	RCC_APB2ENR->TIM11EN = (packed >> 4) & 0x01;
	RCC_APB2ENR->TIM10EN = (packed >> 3) & 0x01;
	RCC_APB2ENR->TIM9EN = (packed >> 2) & 0x01;
	RCC_APB2ENR->SYSCFGEN = (packed >> 0) & 0x01;
}


uint32_t STM32_Pack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR)
{
	uint32_t packed = 0;

	packed |= (RCC_APB1ENR->COMPEN & 0x01) << 31;
	packed |= (RCC_APB1ENR->DACEN & 0x01) << 29;
	packed |= (RCC_APB1ENR->PWREN & 0x01) << 28;
	packed |= (RCC_APB1ENR->USBEN & 0x01) << 23;
	packed |= (RCC_APB1ENR->I2C2EN & 0x01) << 22;
	packed |= (RCC_APB1ENR->I2C1EN & 0x01) << 21;
	packed |= (RCC_APB1ENR->UART5EN & 0x01) << 20;
	packed |= (RCC_APB1ENR->UART4EN & 0x01) << 19;
	packed |= (RCC_APB1ENR->USART3EN & 0x01) << 18;
	packed |= (RCC_APB1ENR->USART2EN & 0x01) << 17;
	packed |= (RCC_APB1ENR->SPI3EN & 0x01) << 15;
	packed |= (RCC_APB1ENR->SPI2EN & 0x01) << 14;
	packed |= (RCC_APB1ENR->WWDEN & 0x01) << 11;
	packed |= (RCC_APB1ENR->LCDEN & 0x01) << 9;
	packed |= (RCC_APB1ENR->TIM7EN & 0x01) << 5;
	packed |= (RCC_APB1ENR->TIM6EN & 0x01) << 4;
	packed |= (RCC_APB1ENR->TIM5EN & 0x01) << 3;
	packed |= (RCC_APB1ENR->TIM4EN & 0x01) << 2;
	packed |= (RCC_APB1ENR->TIM3EN & 0x01) << 1;
	packed |= (RCC_APB1ENR->TIM2EN & 0x01) << 0;

	return packed;
}

void STM32_UnPack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR, uint32_t packed)
{
	RCC_APB1ENR->COMPEN = (packed >> 31) & 0x01;
	RCC_APB1ENR->DACEN = (packed >> 29) & 0x01;
	RCC_APB1ENR->PWREN = (packed >> 28) & 0x01;
	RCC_APB1ENR->USBEN = (packed >> 23) & 0x01;
	RCC_APB1ENR->I2C2EN = (packed >> 22) & 0x01;
	RCC_APB1ENR->I2C1EN = (packed >> 21) & 0x01;
	RCC_APB1ENR->UART5EN = (packed >> 20) & 0x01;
	RCC_APB1ENR->UART4EN = (packed >> 19) & 0x01;
	RCC_APB1ENR->USART3EN = (packed >> 18) & 0x01;
	RCC_APB1ENR->USART2EN = (packed >> 17) & 0x01;
	RCC_APB1ENR->SPI3EN = (packed >> 15) & 0x01;
	RCC_APB1ENR->SPI2EN = (packed >> 14) & 0x01;
	RCC_APB1ENR->WWDEN = (packed >> 11) & 0x01;
	RCC_APB1ENR->LCDEN = (packed >> 9) & 0x01;
	RCC_APB1ENR->TIM7EN = (packed >> 5) & 0x01;
	RCC_APB1ENR->TIM6EN = (packed >> 4) & 0x01;
	RCC_APB1ENR->TIM5EN = (packed >> 3) & 0x01;
	RCC_APB1ENR->TIM4EN = (packed >> 2) & 0x01;
	RCC_APB1ENR->TIM3EN = (packed >> 1) & 0x01;
	RCC_APB1ENR->TIM2EN = (packed >> 0) & 0x01;

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
