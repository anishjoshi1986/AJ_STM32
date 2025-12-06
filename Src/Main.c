/*
 * Main.c
 *
 *  Created on: Nov 9, 2025
 *      Author: anish
 */

#include "stm32l152xx_spidrv.h"
#include "stm32l152xx_gpiodrv.h"

void spi_comms(void);
void led(void);

int main(void)
{
	spi_comms();

	led();

	return 0;
}

void EXTI0_IRQHandler (void)
{
	if(pEXTI->PR & 1)
		pEXTI->PR |= 1;

	GPIO_TogglePin(pGPIOB, GPIO_PIN_7);
}

void spi_comms()
{
	SPI_Handle_st SPI_Gyro;

	SPI_Gyro.pSPIX = pSPI1;
	SPI_Gyro.SPI_Cfg.master = TRUE;
	SPI_Gyro.SPI_Cfg.bustype = SPI_BUSTYPE_FDX;
	SPI_Gyro.SPI_Cfg.rxonly = FALSE;
	SPI_Gyro.SPI_Cfg.speed = 7;
	SPI_Gyro.SPI_Cfg.dff = FALSE;
	SPI_Gyro.SPI_Cfg.cpha = TRUE;
	SPI_Gyro.SPI_Cfg.cpol = FALSE;
	SPI_Gyro.SPI_Cfg.ssm = FALSE;
	SPI_Gyro.SPI_Cfg.crcen = FALSE;

	SPI_ClkCtrl(&SPI_Gyro, SET);
	SPI_Init(&SPI_Gyro);
}

void led()
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
	}
}
