/*
 * init_n_cfg.h
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#ifndef INIT_N_CFG_H_
#define INIT_N_CFG_H_

#include "../HAL/Hdr/spi_hal.h"
#include "../Drivers/Hdr/gyro1_drv.h"
#include "../HAL/Hdr/gpio_hal.h"

void init_stm32spi();
void init_gyro1();

#endif /* MAIN_INIT_N_CFG_H_ */
