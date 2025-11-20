/*
 * LEDToggle_Ex01.c
 *
 *  Created on: Sep 11, 2025
 *      Author: anish
 */


#include "stm32l152xx.h"
#include "stm32l152xx_gPIOdrv.h"

int main(void)
{
	GPIO_Handle_st DiscoBoard_LD3;
	GPIO_Handle_st DiscoBoard_LD4;
	GPIO_Handle_st PushButton_Inp;

	PushButton_Inp.pGPIOX = pGPIOA;
	PushButton_Inp.GPIO_PinCfg.pin = GPIO_PIN_0;
	PushButton_Inp.GPIO_PinCfg.mode = GPIO_MODE_INTRE;
	PushButton_Inp.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	PushButton_Inp.GPIO_PinCfg.pupd = GPIO_PUPD_PD;

	DiscoBoard_LD3.pGPIOX = pGPIOB;
	DiscoBoard_LD3.GPIO_PinCfg.pin = GPIO_PIN_7;
	DiscoBoard_LD3.GPIO_PinCfg.mode = GPIO_MODE_OUT;
	DiscoBoard_LD3.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	DiscoBoard_LD3.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	DiscoBoard_LD4.pGPIOX = pGPIOB;
	DiscoBoard_LD4.GPIO_PinCfg.pin = GPIO_PIN_6;
	DiscoBoard_LD4.GPIO_PinCfg.mode = GPIO_MODE_OUT;
	DiscoBoard_LD4.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	DiscoBoard_LD4.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	GPIO_ClkCtrl(DiscoBoard_LD3.pGPIOX, SET);
	GPIO_ClkCtrl(DiscoBoard_LD4.pGPIOX, SET);

	GPIO_Init(&DiscoBoard_LD3);
	GPIO_Init(&DiscoBoard_LD4);
	GPIO_Init(&PushButton_Inp);

	IRQConfig(IRQ_NO_EXTI0, SET);

	while(1)
	{
		/*
		if(GPIO_ReadPin(pGPIOA, GPIO_PIN_0))
		{
			GPIO_WritePin(pGPIOB, GPIO_PIN_6, 1);
			GPIO_WritePin(pGPIOB, GPIO_PIN_7, 0);
		}
		else
		{
			GPIO_WritePin(pGPIOB, GPIO_PIN_7, 1);
			GPIO_WritePin(pGPIOB, GPIO_PIN_6, 0);
		}
		 */
	}

	return 0;
}

void EXTI0_IRQHandler (void)
{
	if(pEXTI->PR & 1)
		pEXTI->PR |= 1;

	GPIO_TogglePin(pGPIOB, GPIO_PIN_7);
}
