/*
 * stm32l152_gpiodrv.c
 *
 *  Created on: Sep 3, 2025
 *      Author: anish
 */

#include <stm32l152xx_gpio.h>

// --------------------------------------------------------------------------------------------------------//
// GPIO clock control
// --------------------------------------------------------------------------------------------------------//

void GPIO_ClkCtrl(GPIO_Handle_st *pGPIO_Handle, uint8_t ClkCmd)
{
	if(ClkCmd == SET)
	{
		if(pGPIO_Handle->pGPIOX == pGPIOA)
		{
			GPIOA_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOB)
		{
			GPIOB_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOC)
		{
			GPIOC_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOD)
		{
			GPIOD_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOE)
		{
			GPIOE_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOH)
		{
			GPIOH_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOF)
		{
			GPIOF_CLK_EN();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOG)
		{
			GPIOG_CLK_EN();
		}

	else
	{
		if(pGPIO_Handle->pGPIOX == pGPIOA)
		{
			GPIOA_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOB)
		{
			GPIOB_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOC)
		{
			GPIOC_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOD)
		{
			GPIOD_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOE)
		{
			GPIOE_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOH)
		{
			GPIOH_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOF)
		{
			GPIOF_CLK_DIS();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOG)
		{
			GPIOG_CLK_DIS();
		}
	}
	}
}

// --------------------------------------------------------------------------------------------------------//
// GPIO init
// --------------------------------------------------------------------------------------------------------//

void GPIO_Init(GPIO_Handle_st *pGPIO_Handle)
{
	uint32_t temp;

	if(pGPIO_Handle->GPIO_PinCfg.mode <= GPIO_MODE_ANALOG)
	{
		// non interrupt
		temp = pGPIO_Handle->GPIO_PinCfg.mode << (2 * pGPIO_Handle->GPIO_PinCfg.pin);
		pGPIO_Handle->pGPIOX->MODER &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PinCfg.pin));
		pGPIO_Handle->pGPIOX->MODER |= temp;
	}
	else
	{
		uint8_t temp1 = pGPIO_Handle->GPIO_PinCfg.pin / 4;
		uint8_t temp2 = pGPIO_Handle->GPIO_PinCfg.pin % 4;

		pSYSCFG->EXTICR[temp1] = pGPIO_Handle->GPIO_PinCfg.port << (4 * temp2);

		if(pGPIO_Handle->GPIO_PinCfg.mode == GPIO_MODE_INTFE)
		{
			// Configure falling edge interrupt
			pEXTI->FTSR &= ~(1 << pGPIO_Handle->GPIO_PinCfg.pin);
			pEXTI->FTSR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;
		}
		else if(pGPIO_Handle->GPIO_PinCfg.mode == GPIO_MODE_INTRE)
		{
			// Configure rising edge interrupt
			pEXTI->RTSR &= ~(1 << pGPIO_Handle->GPIO_PinCfg.pin);
			pEXTI->RTSR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;
		}
		else
		{
			// Configure rising and falling edge interrupt
			pEXTI->FTSR &= ~(1 << pGPIO_Handle->GPIO_PinCfg.pin);
			pEXTI->FTSR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;

			pEXTI->RTSR &= ~(1 << pGPIO_Handle->GPIO_PinCfg.pin);
			pEXTI->RTSR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;
		}

		// Disable interrupt mask
		pEXTI->IMR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;

		SYSCFG_CLK_EN();

	}

	temp = 0;

	// Output type register
	temp = pGPIO_Handle->GPIO_PinCfg.otype << pGPIO_Handle->GPIO_PinCfg.pin;
	pGPIO_Handle->pGPIOX->OTYPER &= ~(0x01 << pGPIO_Handle->GPIO_PinCfg.pin);
	pGPIO_Handle->pGPIOX->OTYPER |= temp;
	temp = 0;

	// Output speed register
	temp = pGPIO_Handle->GPIO_PinCfg.speed << (2 * pGPIO_Handle->GPIO_PinCfg.pin);
	pGPIO_Handle->pGPIOX->OSPEEDR &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PinCfg.pin));
	pGPIO_Handle->pGPIOX->OSPEEDR |= temp;
	temp = 0;

	// Pull-Up Pull-Down register
	temp = pGPIO_Handle->GPIO_PinCfg.pupd << (2 * pGPIO_Handle->GPIO_PinCfg.pin);
	pGPIO_Handle->pGPIOX->PUPDR &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PinCfg.pin));
	pGPIO_Handle->pGPIOX->PUPDR |= temp;
	temp = 0;

	// Alternate function register
	if(pGPIO_Handle->GPIO_PinCfg.mode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;

		temp1 = pGPIO_Handle->GPIO_PinCfg.pin / 8;		// Decides which register AFRL or AFRH
		temp2 = pGPIO_Handle->GPIO_PinCfg.pin % 8;		// Bitshift operand to decide which pin of L or H

		pGPIO_Handle->pGPIOX->AFR[temp1] &= ~(0x0F << (4 * temp2));
		pGPIO_Handle->pGPIOX->AFR[temp1] |= pGPIO_Handle->GPIO_PinCfg.altfn << (4 * temp2);
	}

}

// --------------------------------------------------------------------------------------------------------//
// GPIO reset
// --------------------------------------------------------------------------------------------------------//

void GPIO_Reset(GPIO_Handle_st *pGPIO_Handle)
{
	if(pGPIO_Handle->pGPIOX == pGPIOA)
		{
			GPIOA_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOB)
		{
			GPIOB_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOC)
		{
			GPIOC_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOD)
		{
			GPIOD_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOE)
		{
			GPIOE_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOH)
		{
			GPIOH_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOF)
		{
			GPIOF_RESET();
		}
		else if(pGPIO_Handle->pGPIOX == pGPIOG)
		{
			GPIOG_RESET();
		}
}

// --------------------------------------------------------------------------------------------------------//
// GPIO Read n Write
// --------------------------------------------------------------------------------------------------------//

uint8_t GPIO_ReadPin(GPIO_Handle_st *pGPIO_Handle)
{
	uint8_t value;

	value = (uint8_t)((pGPIO_Handle->pGPIOX->IDR >> pGPIO_Handle->GPIO_PinCfg.pin) & (1));

	return value;
}

uint16_t GPIO_ReadPort(GPIO_Handle_st *pGPIO_Handle)
{
	uint16_t value;

	value = (uint16_t)pGPIO_Handle->pGPIOX->IDR;

	return value;
}

void GPIO_WritePin(GPIO_Handle_st *pGPIO_Handle, uint8_t value)
{
	if(value)
	{
		pGPIO_Handle->pGPIOX->ODR |= 1 << pGPIO_Handle->GPIO_PinCfg.pin;
	} else
	{
		pGPIO_Handle->pGPIOX->ODR &= ~(1 << pGPIO_Handle->GPIO_PinCfg.pin);
	}
}

void GPIO_WritePort(GPIO_Handle_st *pGPIO_Handle, uint16_t value)
{
	pGPIO_Handle->pGPIOX->ODR = value;
}

void GPIO_TogglePin(GPIO_Handle_st *pGPIO_Handle)
{
	pGPIO_Handle->pGPIOX->ODR ^= (1 << pGPIO_Handle->GPIO_PinCfg.pin);
}

void GPIO_AltFnSetup(GPIO_Handle_st *pGPIO_Handle)
{
	uint32_t temp1;
	uint32_t temp2;

	temp1 = pGPIO_Handle->GPIO_PinCfg.pin / 8;
	temp2 = pGPIO_Handle->GPIO_PinCfg.pin % 8;
	pGPIO_Handle->pGPIOX->AFR[temp1] |= pGPIO_Handle->GPIO_PinCfg.altfn << 4*temp2;
}
