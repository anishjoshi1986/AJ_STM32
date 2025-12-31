/*
 * Main.c
 *
 *  Created on: Nov 9, 2025
 *      Author: anish
 */

#include "init_n_cfg.h"

int main(void)
{
	init_stm32timer();
	init_stm32spi();
	init_stm32gpio();
	init_gyro1();

	while(1)
	{

	}

	return 0;

}
