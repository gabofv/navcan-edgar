/*
 * buzzer.h
 *
 *  Created on: May 23, 2025
 *      Author: gabri
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "../Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"

/* RCC */
#define GPIOAEN		(1U<<0)

/* GPIOx */
#define MODER6_0	(1U<<12)
#define MODER6_1	(1U<<13)
#define BSRR6_S		(1U<<6)
#define BSRR6_R		(1U<<(6+16))


void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);


#endif /* BUZZER_H_ */
