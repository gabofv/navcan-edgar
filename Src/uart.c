/*
 * uart.c
 *
 *  Created on: May 7, 2025
 *      Author: gabri
 */

#include "uart.h"


static uint16_t compute_uart_baudr(uint32_t periph_clk, uint32_t br);
static void uart_set_baudr(uint32_t periph_clk, uint32_t br);
static void uart_write(int c);


int __io_putchar(int c) {
	uart_write(c);
	return c;
}

void uart_init(void) {
	/* Enable AHB2 bus clock for Port A */
	RCC->AHB2ENR |= GPIOAEN;

	/* Config PA2 for AF */
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/* AF low register to AF07 (USART2_TX) */
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/* Config USART1 */
	RCC->APB1ENR1 |= USART2EN;

	uart_set_baudr(APB1_CLK, DBG_UART_BAUDRATE);

	/* Enable transmitter */
	USART2->CR1 = CR1_TE;
	/* Enable UART */
	USART2->CR1 |= CR1_UE;
}

static void uart_write(int c) {
	/* Wait until tx is empty */
	while(!(USART2->ISR & ISR_TXE)) {}
	USART2->TDR = (c & 0xFF);
}

static uint16_t compute_uart_baudr(uint32_t periph_clk, uint32_t br) {
	// Add half of divisor to numerator to apply round-to-nearest
	// Formula valid when OVER8 = 0
	return (uint16_t) ((periph_clk + (br / 2U)) / br);
}

static void uart_set_baudr(uint32_t periph_clk, uint32_t br) {
	USART2->BRR = compute_uart_baudr(periph_clk, br);
}

