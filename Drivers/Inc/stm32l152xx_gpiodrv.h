/*
 * stm32l152_gpiodrv.h
 *
 *  Created on: Sep 3, 2025
 *      Author: anish
 */

#ifndef STM32L152XX_GPIODRV_H_
#define STM32L152XX_GPIODRV_H_

#include "stm32l152xx.h"

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

uint8_t GPIO_ReadPin(GPIO_Handle_st *pGPIO_Handle, uint8_t pin);							// Read n Write pins													// Read, write pin
uint16_t GPIO_ReadPort(GPIO_Handle_st *pGPIO_Handle);
void GPIO_WritePin(GPIO_Handle_st *pGPIO_Handle, uint8_t pin, uint8_t value);
void GPIO_WritePort(GPIO_Handle_st *pGPIO_Handle, uint16_t value);
void GPIO_TogglePin(GPIO_Handle_st *pGPIO_Handle, uint8_t pin);

void GPIO_Init(GPIO_Handle_st *pGPIO_Handle);										// Initialize based on user input

void GPIO_AltFnSetup(GPIO_Handle_st *pGPIO_Handle, uint8_t pin, uint8_t altfn);

#endif /* STM32L152XX_GPIODRV_H_ */
