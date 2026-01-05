/*
 * * init_n_cfg.c
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#include <stdio.h>
#include "init_n_cfg.h"
#include "../HAL/Hdr/interrupt_hal.h"
#include "../HAL/Hdr/stm32_hal.h"

SPIHandle_st SPI1_Handle;
GPIOHandle_st SPI1_SCK;
GPIOHandle_st SPI1_MISO;
GPIOHandle_st SPI1_MOSI;
GPIOHandle_st SPI1_Gyro1_CS;

Gyro1Handle_st Gyro1_Handle;

GPIOHandle_st DiscoBoard_LD3;
GPIOHandle_st DiscoBoard_LD4;
GPIOHandle_st PushButton_Inp;



void init_stm32clksys()
{
	STM32_RCC_CR RCC_CR = {0};
	STM32_RCC_CFGR RCC_CFGR = {0};

	RCC_CR.RTCPRE = 0;
	RCC_CR.CSSON = DISABLE;
	RCC_CR.PLLON = DISABLE;
	RCC_CR.HSEBYP = DISABLE;
	RCC_CR.HSEON = DISABLE;
	RCC_CR.MSION = DISABLE;
	RCC_CR.HSION = ENABLE;

	pRCC->CR = STM32_Pack_RCC_CR(&RCC_CR);

	RCC_CFGR.MCOPRE = 0;
	RCC_CFGR.MCOSEL = 0;
	RCC_CFGR.PLLDIV = 0;
	RCC_CFGR.PLLMUL = 0;
	RCC_CFGR.PLLSRC = 0;
	RCC_CFGR.PPRE2 = 0;
	RCC_CFGR.PPRE1 = 0;
	RCC_CFGR.HPRE = 0;
	RCC_CFGR.SW = 1;

	pRCC->CFGR = STM32_Pack_RCC_CFGR(&RCC_CFGR);
	// Set all clock frequencies

}

void init_stm32timersys()
{
	BTIMx_Handle_st TS_TIM6;
	BTIMx_Handle_st TS_TIM7;

	TS_TIM6.pBTIMx = pTIM6;
	TS_TIM6.BTIMx_Cfg.freq = 1/PERIOD_1MS;
	TS_TIM6.BTIMx_Cfg.mode = 0;
	TS_TIM6.BTIMx_Cfg.reload = 0;

	BTIMx_ClkCtrl(&TS_TIM6, ENABLE);
	BTIMx_Init(&TS_TIM6);

	IRQConfig(IRQ_NO_TIM6, SET);


	TS_TIM7.pBTIMx = pTIM7;
	TS_TIM7.BTIMx_Cfg.freq = 1/PERIOD_10MS;
	TS_TIM7.BTIMx_Cfg.mode = 0;
	TS_TIM7.BTIMx_Cfg.reload = 0;

	BTIMx_ClkCtrl(&TS_TIM7, ENABLE);
	BTIMx_Init(&TS_TIM7);

	IRQConfig(IRQ_NO_TIM7, SET);
}


void init_stm32spi()

{

	SPI1_Handle.pSPIX = pSPI1;
	SPI1_Handle.SPI_Cfg.master = TRUE;
	SPI1_Handle.SPI_Cfg.bustype = SPI_BUSTYPE_HDX;
	SPI1_Handle.SPI_Cfg.rxonly = FALSE;
	SPI1_Handle.SPI_Cfg.speed = 7;
	SPI1_Handle.SPI_Cfg.dff = FALSE;
	SPI1_Handle.SPI_Cfg.cpha = TRUE;
	SPI1_Handle.SPI_Cfg.cpol = TRUE;
	SPI1_Handle.SPI_Cfg.ssm = FALSE;
	SPI1_Handle.SPI_Cfg.crcen = FALSE;

	SPI_ClkCtrl(&SPI1_Handle, SET);
	SPI_Init(&SPI1_Handle);

	SPI1_SCK.pGPIOX = pGPIOA;
	SPI1_SCK.GPIO_PinCfg.pin = GPIO_PIN_5;
	SPI1_SCK.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI1_SCK.GPIO_PinCfg.altfn = 5;
	SPI1_SCK.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI1_SCK.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	SPI1_MISO.pGPIOX = pGPIOA;
	SPI1_MISO.GPIO_PinCfg.pin = GPIO_PIN_6;
	SPI1_MISO.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI1_MISO.GPIO_PinCfg.altfn = 5;
	SPI1_MISO.GPIO_PinCfg.otype = GPIO_PUPD_PD;
	SPI1_MISO.GPIO_PinCfg.pupd = GPIO_PUPD_PD;

	SPI1_MOSI.pGPIOX = pGPIOA;
	SPI1_MOSI.GPIO_PinCfg.pin = GPIO_PIN_7;
	SPI1_MOSI.GPIO_PinCfg.mode = GPIO_MODE_ALTFN;
	SPI1_MOSI.GPIO_PinCfg.altfn = 5;
	SPI1_MOSI.GPIO_PinCfg.otype = GPIO_OTYPE_PP;
	SPI1_MOSI.GPIO_PinCfg.pupd = GPIO_PUPD_NO;

	GPIO_ClkCtrl(&SPI1_SCK, SET);
	GPIO_ClkCtrl(&SPI1_MISO, SET);
	GPIO_ClkCtrl(&SPI1_MOSI, SET);
	GPIO_Init(&SPI1_SCK);
	GPIO_Init(&SPI1_MISO);
	GPIO_Init(&SPI1_MOSI);

}

void init_gyro1()
{
	Gyro1_Handle.pGPIO_Handle = &SPI1_Gyro1_CS;
	Gyro1_Handle.pSPI_Handle = &SPI1_Handle;

	GYRO1_CTRL_REG1 CTRL_REG1;
	GYRO1_CTRL_REG2 CTRL_REG2;
	GYRO1_CTRL_REG3 CTRL_REG3;
	GYRO1_CTRL_REG4 CTRL_REG4;
	GYRO1_CTRL_REG5 CTRL_REG5;

	CTRL_REG1.DR = 0x03;
	CTRL_REG1.BW = 0x03;
	CTRL_REG1.PD = DISABLE;
	CTRL_REG1.Zen = ENABLE;
	CTRL_REG1.Yen = ENABLE;
	CTRL_REG1.Xen = ENABLE;

	CTRL_REG2.HPM = 0x00;
	CTRL_REG2.HPCF = 0x00;

	CTRL_REG3.I1_Int1 = DISABLE;
	CTRL_REG3.I1_Boot = ENABLE;
	CTRL_REG3.H_Lactive = 0;
	CTRL_REG3.PP_OD = 0;
	CTRL_REG3.I2_DRDY = DISABLE;
	CTRL_REG3.I2_WTM = ENABLE;
	CTRL_REG3.I2_ORun = ENABLE;
	CTRL_REG3.I2_Empty = ENABLE;

	CTRL_REG4.BLE = 0x00;
	CTRL_REG4.FS = 0x00;
	CTRL_REG4.ST = 0x00;
	CTRL_REG4.SIM = 0x00;

	CTRL_REG5.BOOT = 0x00;
	CTRL_REG5.FIFO_EN = ENABLE;
	CTRL_REG5.HPen = ENABLE;
	CTRL_REG5.INT_Sel = 0x01;
	CTRL_REG5.Out_Sel = 0x01;

	uint8_t Gyro1_Init_Status = Gyro1_Write(&Gyro1_Handle, GYRO1_CTRL_REG1_ADDR, Gyro1_Pack_CTRL_REG1(&CTRL_REG1)) ||
			Gyro1_Write(&Gyro1_Handle, GYRO1_CTRL_REG2_ADDR, Gyro1_Pack_CTRL_REG2(&CTRL_REG2)) ||
			Gyro1_Write(&Gyro1_Handle, GYRO1_CTRL_REG3_ADDR, Gyro1_Pack_CTRL_REG3(&CTRL_REG3)) ||
			Gyro1_Write(&Gyro1_Handle, GYRO1_CTRL_REG4_ADDR, Gyro1_Pack_CTRL_REG4(&CTRL_REG4)) ||
			Gyro1_Write(&Gyro1_Handle, GYRO1_CTRL_REG5_ADDR, Gyro1_Pack_CTRL_REG5(&CTRL_REG5));

	uint8_t err = !Gyro1_Init_Status;
	printf("%d",err);

}

void init_stm32gpio()
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

