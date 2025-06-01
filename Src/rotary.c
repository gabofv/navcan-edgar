/*
 * rotary.c
 *
 *  Created on: May 22, 2025
 *      Author: gabri
 */

#include "rotary.h"

void rsw_init(void) {
	 /* Should also include init for pin A, B */
	RCC->AHB2ENR |= GPIOAEN;

	/* Set pin to input mode */
	GPIOA->MODER &= ~MODER4_0;
	GPIOA->MODER &= ~MODER4_1;

	/* Set pin to weak pull-up mode */
	GPIOA->PUPDR |= PUPDR4_0;
	GPIOA->PUPDR &= ~PUPDR4_1;
}

uint8_t rsw_rd(void) {
	return (GPIOA->IDR & (1U << 4)) >> 4;
}

