/*
 * buzzer.c
 *
 *  Created on: May 23, 2025
 *      Author: gabri
 */


#include "buzzer.h"


void buzzer_init(void) {
	RCC->AHB2ENR |= GPIOAEN;

	GPIOA->MODER |= MODER6_0;
	GPIOA->MODER &= ~MODER6_1;
}

void buzzer_on(void) {
	GPIOA->BSRR |= BSRR6_S;
}

void buzzer_off(void) {
	GPIOA->BSRR |= BSRR6_R;
}
