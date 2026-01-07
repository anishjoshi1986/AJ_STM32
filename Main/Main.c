/*
 * Main.c
 *
 *  Created on: Nov 9, 2025
 *      Author: anish
 */

#include "init_n_cfg.h"
#include "TaskScheduler.h"

int main(void)
{

	init_stm32clksys();

	init_stm32timersys();

	if(SPI1_ENABLE)
	{
		init_stm32spi();
	}
	if(GPIOA_ENABLE)
	{
		init_stm32gpio();
	}
	if(GYRO1_ENABLE)
	{
		init_gyro1();
	}


	while(1)
	{
		taskscheduler();
	}

	return 0;

}
