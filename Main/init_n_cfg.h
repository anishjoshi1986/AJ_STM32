/*
 * init_n_cfg.h
 *
 *  Created on: Dec 23, 2025
 *      Author: anish
 */

#ifndef INIT_N_CFG_H_
#define INIT_N_CFG_H_

#include "../HAL/Hdr/interrupt_hal.h"

#include "../Drivers/Hdr/gyro1_drv.h"
#include "../HAL/Hdr/gpio_hal.h"
#include "../HAL/Hdr/spi_hal.h"
#include "../HAL/Hdr/timer_hal.h"

#define TIM2_ENABLE						0U
#define TIM3_ENABLE						0U
#define TIM4_ENABLE						0U
#define TIM5_ENABLE						0U
#define TIM6_ENABLE						0U
#define TIM7_ENABLE						0U
#define TIM9_ENABLE						0U
#define TIM10_ENABLE					0U
#define TIM11_ENABLE					0U

#define SPI1_ENABLE						1U
#define SPI2_ENABLE						0U
#define SPI3_ENABLE						0U

#define I2C2_ENABLE						0U
#define I2C1_ENABLE						0U

#define UART1_ENABLE					0U
#define UART2_ENABLE					0U
#define UART3_ENABLE					0U
#define UART4_ENABLE					0U
#define UART5_ENABLE					0U

#define USART1_ENABLE					0U
#define USART2_ENABLE					0U
#define USART3_ENABLE					0U

#define GPIOG_ENABLE					0U
#define GPIOF_ENABLE					0U
#define GPIOH_ENABLE					0U
#define GPIOE_ENABLE					0U
#define GPIOD_ENABLE					0U
#define GPIOC_ENABLE					0U
#define GPIOB_ENABLE					1U
#define GPIOA_ENABLE					1U
#define GYRO1_ENABLE					0U

#define USB_ENABLE						0U

#define DMA1_ENABLE						0U
#define DMA2_ENABLE						0U

#define SDIO_ENABLE						0U
#define ADC1_ENABLE						0U
#define SYSCFG_ENABLE					1U
#define	FSMC_ENABLE						0U
#define AES_ENABLE						0U
#define FLITF_ENABLE					0U
#define CRC_ENABLE						0U
#define COMP_ENABLE						0U
#define DAC_ENABLE						0U
#define PWR_ENABLE						0U

#define WWD_ENABLE						0U
#define LCD_ENABLE						0U

#define IRQ_NO_EXTI0_ENABLE				0U										// Interrupt positions in NVIC
#define IRQ_NO_EXTI1_ENABLE				0U
#define IRQ_NO_EXTI2_ENABLE				0U
#define IRQ_NO_EXTI3_ENABLE				0U
#define IRQ_NO_EXTI4_ENABLE				0U
#define IRQ_NO_EXTI9_5_ENABLE			0U
#define IRQ_NO_EXTI15_10_ENABLE			0U

#define IRQ_NO_TIM6_ENABLE				1U
#define IRQ_NO_TIM7_ENABLE				1U

#define SPI1_BR							0U


void init_stm32clksys();
void init_stm32timersys();
void init_stm32spi();
void init_stm32gpio();
void init_gyro1();
void IRQ_init();

#endif /* MAIN_INIT_N_CFG_H_ */
