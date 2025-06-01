/*
 * rotary.h
 *
 *  Created on: May 22, 2025
 *      Author: gabri
 */

#ifndef ROTARY_H_
#define ROTARY_H_

#include <stm32l4xx.h>

// Use gpio (push button) and timer (to read ABC)
// Here only implement gpio - will restructure program later

/* RCC */
#define GPIOAEN		(1U<<0)

/* GPIOx */
#define MODER4_0	(1U<<8)
#define MODER4_1	(1U<<9)
#define PUPDR4_0	(1U<<8)
#define PUPDR4_1	(1U<<9)


void rsw_init(void);
uint8_t rsw_rd(void);

#endif /* ROTARY_H_ */
