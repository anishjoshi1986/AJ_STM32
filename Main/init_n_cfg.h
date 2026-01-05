/*
 * init_n_cfg.h
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#ifndef INIT_N_CFG_H_
#define INIT_N_CFG_H_

#include "../Drivers/Hdr/gyro1_drv.h"
#include "../HAL/Hdr/gpio_hal.h"
#include "../HAL/Hdr/spi_hal.h"
#include "../HAL/Hdr/timer_hal.h"

#define SPI1_ENABLE		1
#define CAN_ENABLE		1
#define GPIO_ENABLE		1
#define GYRO1_ENABLE	1


void init_stm32clksys();
void init_stm32timersys();
void init_stm32spi();
void init_stm32gpio();
void init_gyro1();

#endif /* MAIN_INIT_N_CFG_H_ */
