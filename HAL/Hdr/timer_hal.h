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

#define ARPEBUF_ENABLE		1U
#define OPM_ENABLE			0U
#define URS_ENABLE			1U
#define UDIS_ENABLE			0U
#define	CNT_ENABLE			1U
typedef struct
{
	U8 ARPE : 1;
	U8 OPM : 1;
	U8 URS : 1;
	U8 UDIS : 1;
	U8 CEN : 1;

}STM32_BTIMx_CR1_Cfg;
#define BTIMx_CR1_MASK		(U32)((1U << 7) | (1U << 3) | (1U << 2) | \
							(1U << 1) | (1U << 0))

#define UDE_ENABLE		0U
#define UIE_ENABLE		1U
typedef struct
{
	U8 UDE : 1;
	U8 UIE : 1;

}STM32_BTIMx_DIER_Cfg;
#define BTIMx_DIER_MASK		(U32)((1U << 8) | (1U << 0))

#define UIF_RESET		0U
typedef struct
{
	U8 UIF : 1;

}STM32_BTIMx_SR_Cfg;
#define BTIMx_SR_MASK		(U32)(1U << 0)

typedef struct
{
	U16 CNT;

}STM32_BTIMx_CNT_Cfg;

typedef struct
{
	U16 PSC;

}STM32_BTIMx_PSC_Cfg;

#define MAX_ARR			10U
typedef struct
{
	U16 ARR;

}STM32_BTIMx_ARR_Cfg;

typedef struct
{
	__vo U32 CR1;
	__vo U32 CR2;
	__vo U32 Reserved1;
	__vo U32 DIER;
	__vo U32 SR;
	__vo U32 EGR;
	__vo U32 Reserved2;
	__vo U32 Reserved3;
	__vo U32 Reserved4;
	__vo U32 CNT;
	__vo U32 PSC;
	__vo U32 ARR;

}STM32_BTIMx_RegDef_st;

#define pTIM6			(STM32_BTIMx_RegDef_st *)TIM6
#define pTIM7			(STM32_BTIMx_RegDef_st *)TIM7

typedef struct
{
	U8 interrupt;
	U16 freq;

}BTIMx_Cfg_st;

typedef struct
{
	STM32_BTIMx_RegDef_st *pBTIMx;
	BTIMx_Cfg_st BTIMx_Cfg;

}BTIMx_Handle_st;

U32 STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1_Cfg *BTIMx_CR1);
void STM32_Unpack_BTIMx_CR1(STM32_BTIMx_CR1_Cfg *BTIMx_CR1, U32 packed);

U32 STM32_Pack_BTIMx_DIER(STM32_BTIMx_DIER_Cfg *BTIMx_DIER);
void STM32_Unpack_BTIMx_DIER(STM32_BTIMx_DIER_Cfg *BTIMx_DIER, U32 packed);

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle);

#endif /* HAL_HDR_TIMER_HAL_H_ */
