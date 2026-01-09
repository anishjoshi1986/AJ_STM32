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

#define ARPEBUF_ENABLE		(U8)1
#define OPM_ENABLE			(U8)0
#define URS_ENABLE			(U8)1
#define UDIS_ENABLE			(U8)0
#define	CNT_ENABLE			(U8)1
typedef struct
{
	U8 ARPE : 1;
	U8 OPM : 1;
	U8 URS : 1;
	U8 UDIS : 1;
	U8 CEN : 1;

}STM32_BTIMx_CR1;
#define BTIMx_CR1_MASK		(U32)((1U << 7) | (1U << 3) | (1U << 2) | \
							(1U << 1) | (1U << 0))

#define UDE_ENABLE		(U8)0
#define UIE_ENABLE		(U8)0
typedef struct
{
	U8 UDE : 1;
	U8 UIE : 1;

}STM32_BTIMx_DIER;
#define BTIMx_DIER_MASK		(U32)((1U << 8) | (1U << 0))

#define UIF_RESET		(U8)0
typedef struct
{
	U8 UIF : 1;

}STM32_BTIMx_SR;
#define BTIMx_SR_MASK		(U32)(1U << 0)

typedef struct
{
	U16 CNT;

}STM32_BTIMx_CNT;

typedef struct
{
	U16 PSC;

}STM32_BTIMx_PSC;

#define MAX_ARR			(U8)10
typedef struct
{
	U16 ARR;

}STM32_BTIMx_ARR;

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

static U32 STM32_Pack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1);
static void STM32_Unpack_BTIMx_CR1(STM32_BTIMx_CR1 *BTIMx_CR1, U32 packed);

static U32 STM32_Pack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER);
static void STM32_Unpack_BTIMx_DIER(STM32_BTIMx_DIER *BTIMx_DIER, U32 packed);

void BTIMx_Init(BTIMx_Handle_st *pBTIMx_Handle);

#endif /* HAL_HDR_TIMER_HAL_H_ */
