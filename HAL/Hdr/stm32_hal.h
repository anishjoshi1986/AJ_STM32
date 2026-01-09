/*
 * stm32l152xx.h
 *
 *  Created on: Sep 1, 2025
 *      Author: anish
 */

#ifndef STM32_HAL_H_
#define STM32_HAL_H_

#include <stdint.h>
#include "generic_macros.h"

// ----------------------------------------------------------------------------------------------------//
// Base addresses of different memory sections - found from memory map in STM32L15xRC datasheet
// ----------------------------------------------------------------------------------------------------//
#define FLASH 					0x08000000U
#define SRAM					0x20000000U
#define EEPROM					0x08080000U
#define ROM						0x1FF00000U
#define CORTEXM3				0xE0000000U

// Base addresses of different buses - found from memory map/reg boundary addresses in RM
// --------------------------------------------------------------------------------------------------------//
#define APB1					0x40000000U
#define APB2					0x40010000U
#define AHB						0x40020000U

// ----------------------------------------------------------------------------------------------------//
// RCC peripheral configuration
// ----------------------------------------------------------------------------------------------------//

typedef struct
{
	__vo U32 CR;
	__vo U32 ICSCR;
	__vo U32 CFGR;
	__vo U32 CIR;
	__vo U32 AHBRSTR;
	__vo U32 APB2RSTR;
	__vo U32 APB1RSTR;
	__vo U32 AHBENR;
	__vo U32 APB2ENR;
	__vo U32 APB1ENR;
	__vo U32 AHBLPENR;
	__vo U32 APB2LPENR;
	__vo U32 APB1LPENR;
	__vo U32 CSR;

}STM32_RCCRegDef_st;

#define RCC						(AHB + 0x3800U)
#define pRCC					((STM32_RCCRegDef_st *)RCC)


// RCC CR Cals
#define RTCPRE_VAL		0U
#define CSS_ENABLE		0U
#define PLL_ENABLE		0U
#define HSEBYP_ENABLE	0U
#define HSE_ENABLE		0U
#define MSI_ENABLE		0U
#define HSI_ENABLE		1U
#define HSI_FREQ_Hz		(U32)16000000
#define HSE_FREQ_Hz		(U32)0

typedef struct
{
	U8 RTCPRE : 2;
	U8 CSSON : 1;
	U8 PLLRDY : 1;
	U8 PLLON : 1;
	U8 HSEBYP : 1;
	U8 HSERDY : 1;
	U8 HSEON : 1;
	U8 MSIRDY : 1;
	U8 MSION : 1;
	U8 HSIRDY : 1;
	U8 HSION : 1;

}STM32_RCC_CR_Cfg;
#define RCC_CR_MASK		(U32)((0x03U << 29) | (1U << 28) | (1U << 24) | \
						(1U << 18) | (1U << 16) | (1U << 8) | (1U << 0))


// RCC ICSCR Cals
#define MSITRIM_VAL		0U
#define MSIRANGE_IND	0U
#define HSITRIM_VAL		0U

typedef struct
{
	U8 MSITRIM : 8;
	U8 MSIRANGE : 3;
	U8 HSITRIM : 5;
}STM32_RCC_ICSCR_Cfg;
#define RCC_ICSCR_MASK	(U32)((0xFF << 24) | (0x07U << 13) | (0x1F << 8))


// RCC CFGR Cals
#define MCOPRE_VAL	0U
#define MCOSEL_VAL	0U
#define PLLDIV_VAL	0U
#define PLLMUL_IND	0U
#define PLLSRC_VAL	0U
#define PPRE2_IND	0U
#define PPRE1_IND	0U
#define HPRE_IND	0U
#define SW_VAL		0U
typedef struct
{
	U8 MCOPRE : 3;
	U8 MCOSEL : 3;
	U8 PLLDIV : 2;
	U8 PLLMUL : 4;
	U8 PLLSRC : 1;
	U8 PPRE2 : 3;
	U8 PPRE1 : 3;
	U8 HPRE : 4;
	U8 SWS : 2;
	U8 SW : 2;

}STM32_RCC_CFGR_Cfg;
#define RCC_CFGR_MASK		(U32)((0x07U << 28) | (0x07U << 24) | (0x03U << 22) | \
							(0x0FU << 18) | (1U << 16) | (0x07U << 11) | \
							(0x07U << 8) | (0x0FU << 4) | (0x03U << 0))


// RCC_AHBENR Cals
#define FSMCEN_VAL		0U
#define AESEN_VAL		0U
#define DMA2EN_VAL		0U
#define DMA1EN_VAL		0U
#define FLITFEN_VAL		0U
#define CRCEN_VAL		0U
#define GPIOGEN_VAL		0U
#define GPIOFEN_VAL		0U
#define GPIOHEN_VAL		0U
#define GPIOEEN_VAL		0U
#define GPIODEN_VAL		0U
#define GPIOCEN_VAL		0U
#define GPIOBEN_VAL		0U
#define GPIOAEN_VAL		0U
typedef struct
{
	U8 FSMCEN : 1;
	U8 AESEN : 1;
	U8 DMA2EN : 1;
	U8 DMA1EN : 1;
	U8 FLITFEN : 1;
	U8 CRCEN : 1;
	U8 GPIOGEN : 1;
	U8 GPIOFEN : 1;
	U8 GPIOHEN : 1;
	U8 GPIOEEN : 1;
	U8 GPIODEN : 1;
	U8 GPIOCEN : 1;
	U8 GPIOBEN : 1;
	U8 GPIOAEN : 1;

}STM32_RCC_AHBENR_Cfg;
#define RCC_AHBENR_MASK			(U32)((1U << 30) | (1U << 27) | (1U << 25) | \
								(1U << 24) | (1U << 15) | (1U << 12) | \
								(1U << 7) | (1U << 6) | (1U << 5) | \
								(1U << 4) | (1U << 3) | (1U << 2) | \
								(1U << 1) | (1U << 0))


// RCC APB2ENR Cals
#define USART1EN_VAL	0U
#define SPI1EN_VAL		1U
#define SDIOEN_VAL		0U
#define ADC1EN_VAL		0U
#define TIM11EN_VAL		0U
#define TIM10EN_VAL		0U
#define TIM9EN_VAL		0U
#define SYSCFGEN_VAL	0U
typedef struct
{
	U8 USART1EN : 1;
	U8 SPIEN : 1;
	U8 SDIOEN : 1;
	U8 ADC1EN : 1;
	U8 TIM11EN : 1;
	U8 TIM10EN : 1;
	U8 TIM9EN : 1;
	U8 SYSCFGEN : 1;

}STM32_RCC_APB2ENR_Cfg;
#define RCC_APB2ENR_MASK			(U32)((1U << 14) | (1U << 12) | (1U << 11) | \
									(1U << 9) | (1U << 4) | (1U << 3) | \
									(1U << 2) | (1U << 0))


// RCC APB1ENR Cals
#define COMPEN_VAL		0U
#define DACEN_VAL		0U
#define PWREN_VAL		0U
#define USBEN_VAL		0U
#define I2C2EN_VAL		0U
#define I2C1EN_VAL		0U
#define UART5EN_VAL		0U
#define UART4EN_VAL		0U
#define USART3EN_VAL	0U
#define USART2EN_VAL	0U
#define SPI3EN_VAL		0U
#define SPI2EN_VAL		0U
#define WWDEN_VAL		0U
#define LCDEN_VAL		0U
#define TIM7EN_VAL		1U
#define TIM6EN_VAL		1U
#define TIM5EN_VAL		0U
#define TIM4EN_VAL		0U
#define TIM3EN_VAL		0U
#define TIM2EN_VAL		0U
typedef struct
{
	U8 COMPEN : 1;
	U8 DACEN : 1;
	U8 PWREN : 1;
	U8 USBEN : 1;
	U8 I2C2EN : 1;
	U8 I2C1EN : 1;
	U8 UART5EN : 1;
	U8 UART4EN : 1;
	U8 USART3EN : 1;
	U8 USART2EN : 1;
	U8 SPI3EN : 1;
	U8 SPI2EN : 1;
	U8 WWDEN : 1;
	U8 LCDEN : 1;
	U8 TIM7EN : 1;
	U8 TIM6EN : 1;
	U8 TIM5EN : 1;
	U8 TIM4EN : 1;
	U8 TIM3EN : 1;
	U8 TIM2EN : 1;

}STM32_RCC_APB1ENR_Cfg;
#define RCC_APB1ENR_MASK			(U32)((1U << 31) | (1U << 29) | (1U << 28) | \
									(1U << 23) | (1U << 22) | (1U << 21) | \
									(1U << 20) | (1U << 19) | (1U << 18) | \
									(1U << 17) | (1U << 15) | (1U << 14) | \
									(1U << 11) | (1U << 9) | (1U << 5) | \
									(1U << 4) | (1U << 3) | (1U << 2) | \
									(1U << 1) | (1U << 0))


// Pack - Unpack functions
U32 STM32_Pack_RCC_CR(STM32_RCC_CR_Cfg *RCC_CR_CFG);
void STM32_UnPack_RCC_CR(STM32_RCC_CR_Cfg *RCC_CR_CFG, U32 packed);

U32 STM32_Pack_RCC_ICSCR(STM32_RCC_ICSCR_Cfg *RCC_ICSCR_CFG);
void STM32_UnPack_RCC_ICSCR(STM32_RCC_ICSCR_Cfg *RCC_ICSCR_CFG, U32 packed);

U32 STM32_Pack_RCC_CFGR(STM32_RCC_CFGR_Cfg *RCC_CFGR_CFG);
void STM32_UnPack_RCC_CFGR(STM32_RCC_CFGR_Cfg *RCC_CFGR_CFG, U32 packed);

U32 STM32_Pack_RCC_AHBENR(STM32_RCC_AHBENR_Cfg *RCC_AHBENR_CFG);
void STM32_UnPack_RCC_AHBENR(STM32_RCC_AHBENR_Cfg *RCC_AHBENR_CFG, U32 packed);

U32 STM32_Pack_RCC_APB2ENR(STM32_RCC_APB2ENR_Cfg *RCC_APB2ENR_CFG);
void STM32_UnPack_RCC_APB2ENR(STM32_RCC_APB2ENR_Cfg *RCC_APB2ENR_CFG, U32 packed);

U32 STM32_Pack_RCC_APB1ENR(STM32_RCC_APB1ENR_Cfg *RCC_APB1ENR_CFG);
void STM32_UnPack_RCC_APB1ENR(STM32_RCC_APB1ENR_Cfg *RCC_APB1ENR_CFG, U32 packed);

typedef struct
{
	U32 ADCCLK_Hz;
	U32 SYSCLK_Hz;
	U32 HCLK_Hz;
	U32 PCLK1_Hz;
	U32 PCLK2_Hz;
	U32 TIMxCLK1_Hz;
	U32 TIMxCLK2_Hz;

}STM32_CLKSPDS;

void STM32_Get_CLKSPDS(STM32_CLKSPDS *clk_speeds);
void STM32_ClkSys_Init();

// --------------------------------------------------------------------------------------------------------//
// SYSCFG register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo U32 MEMRMP;
	__vo U32 PMC;
	__vo U32 EXTICR[4];
}STM32_SYSCFGRegDef_st;

#define SYSCFG					(APB2 + 0x0000)
#define pSYSCFG					((STM32_SYSCFGRegDef_st *)SYSCFG)

#define SYSCFG_CLK_EN()			(pRCC->APB2ENR |= 1)					// Clock En/Dis
#define SYSCFG_CLK_DIS()		(pRCC->APB2ENR &= ~1)

#endif /* STM32L152XX_H_ */
