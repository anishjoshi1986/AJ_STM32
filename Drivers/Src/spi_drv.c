/*
 * spi_drv.c
 *
 *  Created on: Dec 17, 2025
 *      Author: anish
 */

#include "../../HAL/Hdr/spi_hal.h"

uint16_t dummy()
{
	SPI_Handle_st SPI_Gyro;

	/*
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
*/
	return (SPI_Read(&SPI_Gyro));

}
