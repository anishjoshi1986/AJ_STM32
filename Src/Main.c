/*
 * Main.c
 *
 *  Created on: Nov 9, 2025
 *      Author: anish
 */

#include "stm32l152xx_spidrv.h"
#include "stm32l152xx_gpiodrv.h"

GPIO_Handle_st DiscoBoard_LD3;
GPIO_Handle_st DiscoBoard_LD4;
GPIO_Handle_st PushButton_Inp;

void spi_comms(void);
void led(void);

int main(void)
{
	spi_comms();

	led();

	while(1)
	{

	}

	return 0;
}

void EXTI0_IRQHandler (void)
{
	if(pEXTI->PR & 1)
		pEXTI->PR |= 1;

	GPIO_TogglePin(&DiscoBoard_LD4);
	GPIO_TogglePin(&DiscoBoard_LD3);
}

void spi_comms()
{
	SPI_Handle_st SPI_Gyro;

	SPI_Gyro.pSPIX = pSPI1;
	SPI_Gyro.SPI_Cfg.master = TRUE;
	SPI_Gyro.SPI_Cfg.bustype = SPI_BUSTYPE_HDX;
	SPI_Gyro.SPI_Cfg.rxonly = FALSE;
	SPI_Gyro.SPI_Cfg.speed = 7;
	SPI_Gyro.SPI_Cfg.dff = FALSE;
	SPI_Gyro.SPI_Cfg.cpha = TRUE;
	SPI_Gyro.SPI_Cfg.cpol = TRUE;
	SPI_Gyro.SPI_Cfg.ssm = FALSE;
	SPI_Gyro.SPI_Cfg.crcen = FALSE;

	SPI_ClkCtrl(&SPI_Gyro, SET);
	SPI_Init(&SPI_Gyro);

	GPIO_Handle_st SPI_SCK;
	GPIO_Handle_st SPI_MISO;
	GPIO_Handle_st SPI_MOSI;

	SPI_SCK.pGPIOX = pGPIOA;
	SPI_SCK.GPIO_PinCfg.pin = GPIO_PIN_5;
	SPI_SCK.GPIO_PinCfg.altfn = GPIO_MODE_ALTFN;
	SPI_SCK.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI_SCK.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	SPI_MISO.pGPIOX = pGPIOA;
	SPI_MISO.GPIO_PinCfg.pin = GPIO_PIN_6;
	SPI_MISO.GPIO_PinCfg.altfn = GPIO_MODE_ALTFN;
	SPI_MISO.GPIO_PinCfg.otype = GPIO_PUPD_PD;
	SPI_MISO.GPIO_PinCfg.pupd = GPIO_PUPD_PD;

	SPI_MOSI.pGPIOX = pGPIOA;
	SPI_MOSI.GPIO_PinCfg.pin = GPIO_PIN_7;
	SPI_MOSI.GPIO_PinCfg.altfn = GPIO_MODE_ALTFN;
	SPI_MOSI.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI_MOSI.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	GPIO_ClkCtrl(&SPI_SCK, SET);
	GPIO_ClkCtrl(&SPI_MISO, SET);
	GPIO_ClkCtrl(&SPI_MOSI, SET);
	GPIO_Init(&SPI_SCK);
	GPIO_Init(&SPI_MISO);
	GPIO_Init(&SPI_MOSI);
}

void led()
{
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

	GPIO_ClkCtrl(&DiscoBoard_LD3, SET);
	GPIO_ClkCtrl(&DiscoBoard_LD4, SET);
	GPIO_Init(&DiscoBoard_LD3);
	GPIO_Init(&DiscoBoard_LD4);
	GPIO_Init(&PushButton_Inp);

	IRQConfig(IRQ_NO_EXTI0, SET);
}
