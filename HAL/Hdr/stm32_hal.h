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
	__vo uint32_t CR;
	__vo uint32_t ICSCR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHBRSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t APB1RSTR;
	__vo uint32_t AHBENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t AHBLPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t APB1LPENR;
	__vo uint32_t CSR;

}STM32_RCCRegDef_st;

#define RCC						(AHB + 0x3800U)
#define pRCC					((STM32_RCCRegDef_st *)RCC)


// RCC CR Cals
#define RTCPRE_VAL		0
#define CSS_ENABLE		0
#define PLL_ENABLE		0
#define HSEBYP_ENABLE	0
#define HSE_ENABLE		0
#define MSI_ENABLE		0
#define HSI_ENABLE		1
#define HSI_FREQ		16000000U
#define HSE_FREQ		0

typedef struct
{
	uint8_t RTCPRE : 2;
	uint8_t CSSON : 1;
	uint8_t PLLRDY : 1;
	uint8_t PLLON : 1;
	uint8_t HSEBYP : 1;
	uint8_t HSERDY : 1;
	uint8_t HSEON : 1;
	uint8_t MSIRDY : 1;
	uint8_t MSION : 1;
	uint8_t HSIRDY : 1;
	uint8_t HSION : 1;

}STM32_RCC_CR;
#define RCC_CR_MASK		((0x03 << 29) | (0x01 << 28) | (0x01 << 24) | (0x01 << 18) | (0x01 << 16) | (0x01 << 8) | (0x01 << 0))


// RCC ICSCR Cals
#define MSITRIM_VAL		0
#define MSIRANGE_IND	0
#define HSITRIM_VAL		0

typedef struct
{
	uint8_t MSITRIM : 8;
	uint8_t MSIRANGE : 3;
	uint8_t HSITRIM : 5;
}STM32_RCC_ICSCR;
#define RCC_ICSCR_MASK	((0xFF << 24) | (0x07 << 13) | (0x1F << 8))


// RCC CFGR Cals
#define MCOPRE_VAL	0
#define MCOSEL_VAL	0
#define PLLDIV_VAL	0
#define PLLMUL_IND	0
#define PLLSRC_VAL	0
#define PPRE2_IND	0
#define PPRE1_IND	0
#define HPRE_IND	0
#define SW_VAL		0
typedef struct
{
	uint8_t MCOPRE : 3;
	uint8_t MCOSEL : 3;
	uint8_t PLLDIV : 2;
	uint8_t PLLMUL : 4;
	uint8_t PLLSRC : 1;
	uint8_t PPRE2 : 3;
	uint8_t PPRE1 : 3;
	uint8_t HPRE : 4;
	uint8_t SWS : 2;
	uint8_t SW : 2;

}STM32_RCC_CFGR;
#define RCC_CFGR_MASK		((0x07 << 28) | (0x07 << 24) | (0x03 << 22) | (0x0F << 18) | (0x01 << 16) | (0x07 << 11) | (0x07 << 8) | (0x0F << 4) | (0x03 << 0))


// RCC_AHBENR Cals
#define FSMCEN_VAL		0
#define AESEN_VAL		0
#define DMA2EN_VAL		0
#define DMA1EN_VAL		0
#define FLITFEN_VAL		0
#define CRCEN_VAL		0
#define GPIOGEN_VAL		0
#define GPIOFEN_VAL		0
#define GPIOHEN_VAL		0
#define GPIOEEN_VAL		0
#define GPIODEN_VAL		0
#define GPIOCEN_VAL		0
#define GPIOBEN_VAL		0
#define GPIOAEN_VAL		0
typedef struct
{
	uint8_t FSMCEN : 1;
	uint8_t AESEN : 1;
	uint8_t DMA2EN : 1;
	uint8_t DMA1EN : 1;
	uint8_t FLITFEN : 1;
	uint8_t CRCEN : 1;
	uint8_t GPIOGEN : 1;
	uint8_t GPIOFEN : 1;
	uint8_t GPIOHEN : 1;
	uint8_t GPIOEEN : 1;
	uint8_t GPIODEN : 1;
	uint8_t GPIOCEN : 1;
	uint8_t GPIOBEN : 1;
	uint8_t GPIOAEN : 1;

}STM32_RCC_AHBENR;


// RCC APB2ENR Cals
#define USART1EN_VAL	0
#define SPI1EN_VAL		1
#define SDIOEN_VAL		0
#define ADC1EN_VAL		0
#define TIM11EN_VAL		0
#define TIM10EN_VAL		0
#define TIM9EN_VAL		0
#define SYSCFGEN_VAL	0
typedef struct
{
	uint8_t USART1EN : 1;
	uint8_t SPIEN : 1;
	uint8_t SDIOEN : 1;
	uint8_t ADC1EN : 1;
	uint8_t TIM11EN : 1;
	uint8_t TIM10EN : 1;
	uint8_t TIM9EN : 1;
	uint8_t SYSCFGEN : 1;

}STM32_RCC_APB2ENR;


// RCC APB1ENR Cals
#define COMPEN_VAL		0
#define DACEN_VAL		0
#define PWREN_VAL		0
#define USBEN_VAL		0
#define I2C2EN_VAL		0
#define I2C1EN_VAL		0
#define UART5EN_VAL		0
#define UART4EN_VAL		0
#define USART3EN_VAL	0
#define USART2EN_VAL	0
#define SPI3EN_VAL		0
#define SPI2EN_VAL		0
#define WWDEN_VAL		0
#define LCDEN_VAL		0
#define TIM7EN_VAL		1
#define TIM6EN_VAL		1
#define TIM5EN_VAL		0
#define TIM4EN_VAL		0
#define TIM3EN_VAL		0
#define TIM2EN_VAL		0
typedef struct
{
	uint8_t COMPEN : 1;
	uint8_t DACEN : 1;
	uint8_t PWREN : 1;
	uint8_t USBEN : 1;
	uint8_t I2C2EN : 1;
	uint8_t I2C1EN : 1;
	uint8_t UART5EN : 1;
	uint8_t UART4EN : 1;
	uint8_t USART3EN : 1;
	uint8_t USART2EN : 1;
	uint8_t SPI3EN : 1;
	uint8_t SPI2EN : 1;
	uint8_t WWDEN : 1;
	uint8_t LCDEN : 1;
	uint8_t TIM7EN : 1;
	uint8_t TIM6EN : 1;
	uint8_t TIM5EN : 1;
	uint8_t TIM4EN : 1;
	uint8_t TIM3EN : 1;
	uint8_t TIM2EN : 1;

}STM32_RCC_APB1ENR;


// Pack - Unpack functions
uint32_t STM32_Pack_RCC_CR(STM32_RCC_CR *RCC_CR);
void STM32_UnPack_RCC_CR(STM32_RCC_CR *RCC_CR, uint32_t packed);

uint32_t STM32_Pack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR);
void STM32_UnPack_RCC_ICSCR(STM32_RCC_ICSCR *RCC_ICSCR, uint32_t packed);

uint32_t STM32_Pack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR);
void STM32_UnPack_RCC_CFGR(STM32_RCC_CFGR *RCC_CFGR, uint32_t packed);

uint32_t STM32_Pack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR);
void STM32_UnPack_RCC_AHBENR(STM32_RCC_AHBENR *RCC_AHBENR, uint32_t packed);

uint32_t STM32_Pack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR);
void STM32_UnPack_RCC_APB2ENR(STM32_RCC_APB2ENR *RCC_APB2ENR, uint32_t packed);

uint32_t STM32_Pack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR);
void STM32_UnPack_RCC_APB1ENR(STM32_RCC_APB1ENR *RCC_APB1ENR, uint32_t packed);

typedef struct
{
	uint32_t ADCCLK;
	uint32_t SYSCLK;
	uint32_t HCLK;
	uint32_t PCLK1;
	uint32_t PCLK2;
	uint32_t TIMxCLK1;
	uint32_t TIMxCLK2;

}STM32_CLKSPDS;

void STM32_Get_CLKSPDS(STM32_CLKSPDS *clk_speeds);

// --------------------------------------------------------------------------------------------------------//
// SYSCFG register definition
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
}STM32_SYSCFGRegDef_st;

#define SYSCFG					(APB2 + 0x0000)
#define pSYSCFG					((STM32_SYSCFGRegDef_st *)SYSCFG)

#define SYSCFG_CLK_EN()			(pRCC->APB2ENR |= 1)					// Clock En/Dis
#define SYSCFG_CLK_DIS()		(pRCC->APB2ENR &= ~1)

#endif /* STM32L152XX_H_ */
