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


void led_init(void);
void led_on(void);
void led_off(void);

#endif /* LED_C_ */
