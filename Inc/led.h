/*
 * led.c
 *
 *  Created on: May 30, 2025
 *      Author: gabri
 */

#ifndef LED_C_
#define LED_C_

#include <stm32l4xx.h>

// User LED (LD3) uses PB3

/* RCC */
#define GPIOBEN		(1U<<1)

/* GPIOx */
#define MODER3_0	(1U<<6)
#define MODER3_1	(1U<<7)
#define BSRR3_S		(1U<<3)
#define BSRR3_R		(1U<<(3+16))


typedef enum {
	OFF,
	ON
} LedState_Type;

typedef struct {
	LedState_Type state;
} Led_Type;


void Led_Init(Led_Type* const inst, LedState_Type _state);
void Led_setState(Led_Type* const inst, LedState_Type _state);
void Led_trigger(Led_Type* const inst);

#endif /* LED_C_ */
