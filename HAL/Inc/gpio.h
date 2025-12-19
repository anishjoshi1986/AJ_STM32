/*
 * gpio.h
 *
 *  Created on: Sep 3, 2025
 *      Author: anish
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "../../HAL/Inc/stm32.h"

// --------------------------------------------------------------------------------------------------------//
// GPIO peripheral address on AHB & reg struct - found from memory map/reg boundary addresses in RM
// --------------------------------------------------------------------------------------------------------//
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];
	__vo uint32_t BRR;

}GPIO_RegDef_st;

#define GPIOA					(AHB + 0x0000U)
#define GPIOB					(AHB + 0x0400U)
#define GPIOC					(AHB + 0x0800U)
#define GPIOD					(AHB + 0x0C00U)
#define GPIOE					(AHB + 0x1000U)
#define GPIOH					(AHB + 0x1400U)
#define GPIOF					(AHB + 0x1800U)
#define GPIOG					(AHB + 0x1C00U)

#define pGPIOA					(GPIO_RegDef_st *)GPIOA
#define pGPIOB					(GPIO_RegDef_st *)GPIOB
#define pGPIOC					(GPIO_RegDef_st *)GPIOC
#define pGPIOD					(GPIO_RegDef_st *)GPIOD
#define pGPIOE					(GPIO_RegDef_st *)GPIOE
#define pGPIOH					(GPIO_RegDef_st *)GPIOH
#define pGPIOF					(GPIO_RegDef_st *)GPIOF
#define pGPIOG					(GPIO_RegDef_st *)GPIOG

#define GPIOA_CLK_EN()			(pRCC->AHBENR |= 1 << 0)		// Peripheral clock enable for GPIO peripherals
#define GPIOB_CLK_EN()			(pRCC->AHBENR |= 1 << 1)
#define GPIOC_CLK_EN()			(pRCC->AHBENR |= 1 << 2)
#define GPIOD_CLK_EN()			(pRCC->AHBENR |= 1 << 3)
#define GPIOE_CLK_EN()			(pRCC->AHBENR |= 1 << 4)
#define GPIOH_CLK_EN()			(pRCC->AHBENR |= 1 << 5)
#define GPIOF_CLK_EN()			(pRCC->AHBENR |= 1 << 6)
#define GPIOG_CLK_EN()			(pRCC->AHBENR |= 1 << 7)

#define GPIOA_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 0))		// Peripheral clock disable for GPIO peripherals
#define GPIOB_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 1))
#define GPIOC_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 2))
#define GPIOD_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 3))
#define GPIOE_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 4))
#define GPIOH_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 5))
#define GPIOF_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 6))
#define GPIOG_CLK_DIS()			(pRCC->AHBENR &= ~(1 << 7))

#define GPIOA_RESET()			do{pRCC->AHBRSTR |= 1 << 0;pRCC->AHBRSTR &= ~(1 << 0);}while(0) 	// GPIO reset
#define GPIOB_RESET()			do{pRCC->AHBRSTR |= 1 << 1;pRCC->AHBRSTR &= ~(1 << 1);}while(0)
#define GPIOC_RESET()			do{pRCC->AHBRSTR |= 1 << 2;pRCC->AHBRSTR &= ~(1 << 2);}while(0)
#define GPIOD_RESET()			do{pRCC->AHBRSTR |= 1 << 3;pRCC->AHBRSTR &= ~(1 << 3);}while(0)
#define GPIOE_RESET()			do{pRCC->AHBRSTR |= 1 << 4;pRCC->AHBRSTR &= ~(1 << 4);}while(0)
#define GPIOH_RESET()			do{pRCC->AHBRSTR |= 1 << 5;pRCC->AHBRSTR &= ~(1 << 5);}while(0)
#define GPIOF_RESET()			do{pRCC->AHBRSTR |= 1 << 6;pRCC->AHBRSTR &= ~(1 << 6);}while(0)
#define GPIOG_RESET()			do{pRCC->AHBRSTR |= 1 << 7;pRCC->AHBRSTR &= ~(1 << 7);}while(0)

// GPIO register macros

// GPIO MODE register
#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFN			2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_INTFE			4
#define GPIO_MODE_INTRE			5
#define GPIO_MODE_INTFRE		6

// GPIO OTYPE register
#define GPIO_OTYPE_PP			0
#define GPIO_OTYPE_OD			1

// GPIO OSPEED register
#define GPIO_OSPEED_L			0
#define GPIO_OSPEED_M			1
#define GPIO_OSPEED_H			2
#define GPIO_OSPEED_VH			3

// GPIO PUPD register
#define GPIO_PUPD_NO			0
#define GPIO_PUPD_PU			1
#define GPIO_PUPD_PD			2
#define GPIO_PUPD_RES			3

// GPIO Pin Numbers
#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7


// --------------------------------------------------------------------------------------------------------//
// API structs for managing GPIO
// --------------------------------------------------------------------------------------------------------//

typedef struct
{
	uint8_t port;
	uint8_t pin;
	uint8_t mode;
	uint8_t speed;
	uint8_t otype;
	uint8_t pupd;
	uint8_t altfn;

}GPIO_PinCfg_st;

typedef struct
{
	GPIO_RegDef_st *pGPIOX;						// Pointer to the base address of the gpio reg
	GPIO_PinCfg_st GPIO_PinCfg;					// Pointer to pin config struct

}GPIO_Handle_st;

// --------------------------------------------------------------------------------------------------------//
// APIs for managing GPIO
// --------------------------------------------------------------------------------------------------------//

void GPIO_ClkCtrl(GPIO_Handle_st *pGPIO_Handle, uint8_t ClkCmd);							// Clock enable

void GPIO_Reset(GPIO_Handle_st *pGPIO_Handle);											// Peripheral reset

uint8_t GPIO_ReadPin(GPIO_Handle_st *pGPIO_Handle);							// Read n Write pins													// Read, write pin
uint16_t GPIO_ReadPort(GPIO_Handle_st *pGPIO_Handle);
void GPIO_WritePin(GPIO_Handle_st *pGPIO_Handle, uint8_t value);
void GPIO_WritePort(GPIO_Handle_st *pGPIO_Handle, uint16_t value);
void GPIO_TogglePin(GPIO_Handle_st *pGPIO_Handle);

void GPIO_Init(GPIO_Handle_st *pGPIO_Handle);										// Initialize based on user input

void GPIO_AltFnSetup(GPIO_Handle_st *pGPIO_Handle);

#endif /* STM32L152XX_GPIODRV_H_ */
