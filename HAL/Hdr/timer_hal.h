/*
 * timer_hal.h
 *
 *  Created on: Dec 30, 2025
 *      Author: anish
 */

#ifndef TIMER_HAL_H_
#define TIMER_HAL_H_

#include "stm32_hal.h"

#define TIM6			(APB1 + 0x1000U)
#define TIM7			(APB1 + 0x1400U)

typedef struct
{
	uint8_t ARPE : 1;
	uint8_t OPM : 1;
	uint8_t URS : 1;
	uint8_t UDIS : 1;
	uint8_t CEN : 1;

}STM32_BTIMx_CR1;

typedef struct
{
	uint8_t UDE : 1;
	uint8_t UIE : 1;

}STM32_BTIMx_DIER;

typedef struct
{
	uint8_t UIF : 1;

}STM32_BTIMx_SR;

typedef struct
{
	uint16_t CNT;

}STM32_BTIMx_CNT;

typedef struct
{
	uint16_t PSC;

}STM32_BTIMx_PSC;

typedef struct
{
	uint16_t ARR;

}STM32_BTIMx_ARR;

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t Reserved1;
	__vo uint32_t DIER;
	__vo uint32_t SR;
	__vo uint32_t EGR;
	__vo uint32_t Reserved2;
	__vo uint32_t Reserved3;
	__vo uint32_t Reserved4;
	__vo uint32_t CNT;
	__vo uint32_t PSC;
	__vo uint32_t ARR;

}STM32_BTIMx_RegDef_st;

#define pTIM6			(STM32_BTIMx_RegDef_st *)TIM6
#define pTIM7			(STM32_BTIMx_RegDef_st *)TIM7

typedef struct
{
	uint8_t mode;
	uint8_t reload;
	uint8_t freq;
}BTIMx_Cfg_st;

typedef struct
{
	STM32_BTIMx_RegDef_st *pBTIMx;
	BTIMx_Cfg_st BTIMx_Cfg;

}BTIMx_Handle_st;

uint16_t STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1);
void STM32_Unpack_BTIMx_CNT(STM32_BTIMx_CR1 *BTIMx_CR1, uint16_t packed);

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle);

#endif /* HAL_HDR_TIMER_HAL_H_ */
