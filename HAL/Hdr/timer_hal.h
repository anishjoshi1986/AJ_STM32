/*
 * timer_hal.h
 *
 *  Created on: Dec 30, 2025
 *      Author: anish
 */

#ifndef TIMER_HAL_H_
#define TIMER_HAL_H_

#include "stm32_hal.h"

#define TIM6				(APB1 + 0x1000U)
#define TIM7				(APB1 + 0x1400U)

#define ARPEBUF_ENABLE		1
#define OPM_ENABLE			0
#define URS_ENABLE			1
#define UDIS_ENABLE			0
#define	CNT_ENABLE			1
typedef struct
{
	uint8_t ARPE : 1;
	uint8_t OPM : 1;
	uint8_t URS : 1;
	uint8_t UDIS : 1;
	uint8_t CEN : 1;

}STM32_BTIMx_CR1;

#define UDE_ENABLE		0
#define UIE_ENABLE		0
typedef struct
{
	uint8_t UDE : 1;
	uint8_t UIE : 1;

}STM32_BTIMx_DIER;

#define UIF_RESET		0
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

#define MAX_ARR			10
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
	uint8_t interrupt;
	uint16_t freq;

}BTIMx_Cfg_st;

typedef struct
{
	STM32_BTIMx_RegDef_st *pBTIMx;
	BTIMx_Cfg_st BTIMx_Cfg;

}BTIMx_Handle_st;

uint16_t STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1);
void STM32_Unpack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1, uint16_t packed);

uint16_t STM32_Pack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER);
void STM32_Unpack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER, uint16_t packed);

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle);

#endif /* HAL_HDR_TIMER_HAL_H_ */
