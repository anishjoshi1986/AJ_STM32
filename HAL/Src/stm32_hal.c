/*
 * stm32_hal.c
 *
 *  Created on: Jan 3, 2026
 *      Author: anish
 */

#include "../Hdr/stm32_hal.h"

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

	return packed;
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
