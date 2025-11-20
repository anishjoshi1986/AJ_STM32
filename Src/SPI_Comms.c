/*
 * SPI_Comms.c
 *
 *  Created on: Nov 9, 2025
 *      Author: anish
 */

#include "stm32l152xx_spidrv.h"

int main(void)
{
	SPI_Handle_st SPI2_Gyro;

	SPI2_Gyro.pSPIX = pSPI1;
	SPI2_Gyro.SPI_Cfg.master = TRUE;
	SPI2_Gyro.SPI_Cfg.bustype = SPI_BUSTYPE_FDX;
	SPI2_Gyro.SPI_Cfg.rxonly = FALSE;
	SPI2_Gyro.SPI_Cfg.speed = 2;
	SPI2_Gyro.SPI_Cfg.dff = FALSE;
	SPI2_Gyro.SPI_Cfg.cpha = TRUE;
	SPI2_Gyro.SPI_Cfg.cpol = FALSE;
	SPI2_Gyro.SPI_Cfg.ssm = FALSE;

	SPI_Init(&SPI2_Gyro);
	SPI_ClkCtrl(&SPI2_Gyro, SET);

	return 0;
}
