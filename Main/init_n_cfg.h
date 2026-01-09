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

#define TIM2_ENABLE						0
#define TIM3_ENABLE						0
#define TIM4_ENABLE						0
#define TIM5_ENABLE						0
#define TIM6_ENABLE						0
#define TIM7_ENABLE						0
#define TIM9_ENABLE						0
#define TIM10_ENABLE					0
#define TIM11_ENABLE					0

#define SPI1_ENABLE						1
#define SPI2_ENABLE						0
#define SPI3_ENABLE						0

#define I2C2_ENABLE						0
#define I2C1_ENABLE						0

#define UART1_ENABLE					0
#define UART2_ENABLE					0
#define UART3_ENABLE					0
#define UART4_ENABLE					0
#define UART5_ENABLE					0

#define USART1_ENABLE					0
#define USART2_ENABLE					0
#define USART3_ENABLE					0

#define GPIOG_ENABLE					0
#define GPIOF_ENABLE					0
#define GPIOH_ENABLE					0
#define GPIOE_ENABLE					0
#define GPIOD_ENABLE					0
#define GPIOC_ENABLE					0
#define GPIOB_ENABLE					1
#define GPIOA_ENABLE					1
#define GYRO1_ENABLE					0

#define USB_ENABLE						0

#define DMA1_ENABLE						0
#define DMA2_ENABLE						0

#define SDIO_ENABLE						0
#define ADC1_ENABLE						0
#define SYSCFG_ENABLE					1
#define	FSMC_ENABLE						0
#define AES_ENABLE						0
#define FLITF_ENABLE					0
#define CRC_ENABLE						0
#define COMP_ENABLE						0
#define DAC_ENABLE						0
#define PWR_ENABLE						0

#define WWD_ENABLE						0
#define LCD_ENABLE						0

#define IRQ_NO_EXTI0_ENABLE				0										// Interrupt positions in NVIC
#define IRQ_NO_EXTI1_ENABLE				0
#define IRQ_NO_EXTI2_ENABLE				0
#define IRQ_NO_EXTI3_ENABLE				0
#define IRQ_NO_EXTI4_ENABLE				0
#define IRQ_NO_EXTI9_5_ENABLE			0
#define IRQ_NO_EXTI15_10_ENABLE			0

#define IRQ_NO_TIM6_ENABLE				1
#define IRQ_NO_TIM7_ENABLE				1


void init_stm32clksys();
void init_stm32timersys();
void init_stm32spi();
void init_stm32gpio();
void init_gyro1();

#endif /* MAIN_INIT_N_CFG_H_ */
