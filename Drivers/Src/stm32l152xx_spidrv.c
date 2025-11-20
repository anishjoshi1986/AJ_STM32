/*
 * stm32l152xx_spidrv.c
 *
 *  Created on: Oct 21, 2025
 *      Author: anish
 */

#include <stm32l152xx_spidrv.h>

uint8_t FailedWriteCount = 0;
uint8_t FailedWriteCount_Thres = 50;

void SPI_ClkCtrl(SPI_Handle_st* pSPI_Handle, uint8_t ClkCmd)
{
	SPI_ClkCtrl_Casc(pSPI_Handle, ClkCmd);
}

void SPI_Init(SPI_Handle_st* pSPI_Handle)
{
	SPI_Init_Casc(pSPI_Handle);
}

uint8_t SPI_WriteSingle(SPI_Handle_st* pSPI_Handle, uint8_t data, uint8_t dff)
{
	uint8_t cnt_wait4_mt_txbuf = 0;
	uint8_t timeout_thres = 255;

	while(1)
	{
		if(SPI_TXBuffBsy(pSPI_Handle))
		{
			cnt_wait4_mt_txbuf++;										// Increment counter for TX buffer timeout
		}
		else															// TX buffer is empty, Write to TX buffer
		{
			cnt_wait4_mt_txbuf = 0;
			SPI_WriteFaultCheck(-1);

			SPI_Write2DataReg(pSPI_Handle, data, dff);

			return 0x00;
		}

		if(cnt_wait4_mt_txbuf >= timeout_thres)							// Write failed
		{
			SPI_WriteFaultCheck(1);
			return 0xFF;
		}

	}
}

void SPI_WriteFaultCheck(uint8_t status)
{
	FailedWriteCount = FailedWriteCount + status;
	if(FailedWriteCount > FailedWriteCount_Thres)
	{
		// SPI_CommsFailed
	}
}

uint16_t SPI_ReadSingle(SPI_Handle_st *pSPI_Handle)
{
	if(!SPI_RXBuffMT(pSPI_Handle))
		return SPI_ReadDataReg(pSPI_Handle);
	else
		return 0xFF;
}
