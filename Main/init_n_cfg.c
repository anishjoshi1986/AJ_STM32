/*
 * * init_n_cfg.c
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#include "init_n_cfg.h"

STM32_SPIHandle_st SPI_Gyro;

void init_stm32spi()

{

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

	STM32_SPI_ClkCtrl(&SPI_Gyro, SET);
	STM32_SPI_Init(&SPI_Gyro);

	GPIO_Handle_st SPI_SCK;
	GPIO_Handle_st SPI_MISO;
	GPIO_Handle_st SPI_MOSI;

	SPI_SCK.pGPIOX = pGPIOA;
	SPI_SCK.GPIO_PinCfg.pin = GPIO_PIN_5;
	SPI_SCK.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI_SCK.GPIO_PinCfg.altfn = 5;
	SPI_SCK.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI_SCK.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	SPI_MISO.pGPIOX = pGPIOA;
	SPI_MISO.GPIO_PinCfg.pin = GPIO_PIN_6;
	SPI_MISO.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI_MISO.GPIO_PinCfg.altfn = 5;
	SPI_MISO.GPIO_PinCfg.otype = GPIO_PUPD_PD;
	SPI_MISO.GPIO_PinCfg.pupd = GPIO_PUPD_PD;

	SPI_MOSI.pGPIOX = pGPIOA;
	SPI_MOSI.GPIO_PinCfg.pin = GPIO_PIN_7;
	SPI_MOSI.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI_MOSI.GPIO_PinCfg.altfn = 5;
	SPI_MOSI.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI_MOSI.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	GPIO_ClkCtrl(&SPI_SCK, SET);
	GPIO_ClkCtrl(&SPI_MISO, SET);
	GPIO_ClkCtrl(&SPI_MOSI, SET);
	GPIO_Init(&SPI_SCK);
	GPIO_Init(&SPI_MISO);
	GPIO_Init(&SPI_MOSI);

}

void init_gyro1()
{
	if(Gyro1_Write(&SPI_Gyro, GYRO1_CTRL_REG1_ADDR, 0x07))
	{

	} else
	{

	}
}
