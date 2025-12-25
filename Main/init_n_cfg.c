/*
 * * init_n_cfg.c
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#include "init_n_cfg.h"

#ifndef ENABLE
#define ENABLE 1
#endif

#ifndef DISABLE
#define DISABLE 0
#endif

STM32_SPIHandle_st SPI1_Handle;
STM32_GPIOHandle_st SPI1_SCK;
STM32_GPIOHandle_st SPI1_MISO;
STM32_GPIOHandle_st SPI1_MOSI;
STM32_GPIOHandle_st SPI1_Gyro1_CS;

Gyro1Handle_st Gyro1_Handle;

STM32_GPIOHandle_st DiscoBoard_LD3;
STM32_GPIOHandle_st DiscoBoard_LD4;
STM32_GPIOHandle_st PushButton_Inp;

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

	STM32_SPI_ClkCtrl(&SPI1_Handle, SET);
	STM32_SPI_Init(&SPI1_Handle);

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

	uint8_t err;
	if(!Gyro1_Init_Status)
		err = 1;
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

void EXTI0_IRQHandler (void)
{
	if(pEXTI->PR & 1)
		pEXTI->PR |= 1;

	GPIO_TogglePin(&DiscoBoard_LD4);
	GPIO_TogglePin(&DiscoBoard_LD3);
}

