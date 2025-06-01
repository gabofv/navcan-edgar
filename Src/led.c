/*
 * led.c
 *
 *  Created on: May 30, 2025
 *      Author: gabri
 */

#include "led.h"


void led_init(void) {
	RCC->AHB2ENR |= GPIOBEN;

	GPIOB->MODER |= MODER3_0;
	GPIOB->MODER &= ~MODER3_1;
}

void led_on(void) {
	GPIOB->BSRR |= BSRR3_S;
}

void led_off(void) {
	GPIOB->BSRR |= BSRR3_R;
}
