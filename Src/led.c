/*
 * led.c
 *
 *  Created on: May 30, 2025
 *      Author: gabri
 */

#include "led.h"


void Led_Init(Led_Type* const inst, LedState_Type _state) {
	inst->state = _state;

	/* Enable clock */
	RCC->AHB2ENR |= GPIOBEN;

	/* Set output mode */
	GPIOB->MODER |= MODER3_0;
	GPIOB->MODER &= ~MODER3_1;
}

void Led_setState(Led_Type* const inst, LedState_Type _state) {
	inst->state = _state;

	switch (inst->state) {
		case OFF:
			GPIOB->BSRR |= BSRR3_R;
			break;
		case ON:
			GPIOB->BSRR |= BSRR3_S;
			break;
	}
}

void Led_trigger(Led_Type* const inst) {
	switch (inst->state) {
		case OFF:
			GPIOB->BSRR |= BSRR3_S;
			inst->state = ON;
			break;
		case ON:
			GPIOB->BSRR |= BSRR3_R;
			inst->state = OFF;
			break;
	}
}
