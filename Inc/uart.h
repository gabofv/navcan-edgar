/*
 * uart.h
 *
 *  Created on: May 7, 2025
 *      Author: gabri
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "../Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"

// PA2 for USART2_TX (only virtual COM port)

/* RCC */
#define GPIOAEN					(1U<<0)
#define USART2EN				(1U<<17)

/* USART */
#define CR1_UE					(1U<<0)
#define CR1_TE					(1U<<3)
#define ISR_TXE					(1U<<7)

/* Other */
#define DBG_UART_BAUDRATE		115200
#define SYS_FREQ				4000000
#define APB1_CLK				SYS_FREQ

void uart_init(void);

#endif /* UART_H_ */
