/*
 * timer.h
 *
 *  Created on: May 28, 2025
 *      Author: gabri
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>
#include <stm32l4xx.h>

/* RCC */
#define GPIOAEN			(1U<<0)
#define TIM2EN			(1U<<0)

/* GPIOx */
#define MODER0_0		(1U<<0)
#define MODER0_1		(1U<<1)
#define MODER1_0		(1U<<2)
#define MODER1_1		(1U<<3)

/* TIMx */
#define CR1_CEN			(1U<<0)
#define CR1_DIR			(1U<<4)		/* read, 0 -> + */
#define SMCR_SMS_0		(1U<<0)
#define SMCR_SMS_1		(1U<<1)
#define SMCR_SMS_2		(1U<<2)
#define SMCR_SMS_3		(1U<<16)
#define CCMR1_CC1S_0	(1U<<0)
#define CCMR1_CC1S_1	(1U<<1)
#define CCMR1_CC2S_0	(1U<<8)
#define CCMR1_CC2S_1	(1U<<9)
#define CCER_CC1P		(1U<<1)
#define CCER_CC2P		(1U<<5)
#define CCER_CC1E		(1U<<0)
#define CCER_CC2E		(1U<<4)

void tim2_init(void);
uint16_t tim2_rd(void);

#endif /* TIMER_H_ */
