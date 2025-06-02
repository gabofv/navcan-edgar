/*
 * timer.c
 *
 *  Created on: May 28, 2025
 *      Author: gabri
 */

#include "timer.h"


void tim2_init(void) {
	RCC->AHB2ENR |= GPIOAEN;

	GPIOA->MODER &= ~MODER0_0;
	GPIOA->MODER |= MODER0_1;

	GPIOA->MODER &= ~MODER1_0;
	GPIOA->MODER |= MODER1_1;

	/* Enable internal pull-up on PA0 and PA1 */
	GPIOA->PUPDR &= ~((3U << (0*2)) | (3U << (1*2)));
	GPIOA->PUPDR |=  ((1U << (0*2)) | (1U << (1*2)));


	/* Set PA0 alternate function (TIM2_CH1) */
	GPIOA->AFR[0] |= (1U<<0);
	GPIOA->AFR[0] &= ~(1U<<1);
	GPIOA->AFR[0] &= ~(1U<<2);
	GPIOA->AFR[0] &= ~(1U<<3);

	/* Set PA1 alternate function (TIM2_CH2) */
	GPIOA->AFR[0] |= (1U<<4);
	GPIOA->AFR[0] &= ~(1U<<5);
	GPIOA->AFR[0] &= ~(1U<<6);
	GPIOA->AFR[0] &= ~(1U<<7);

	RCC->APB1ENR1 |= TIM2EN;
	(void)RCC->APB1ENR1;

	/* Count up to 500 */
	TIM2->ARR = (500<<2);

	/* Set TIM2 mode to Encoder Mode 3 */
	TIM2->SMCR |= SMCR_SMS_0;
	TIM2->SMCR |= SMCR_SMS_1;
	TIM2->SMCR &= ~SMCR_SMS_2;
	TIM2->SMCR &= ~SMCR_SMS_3;

	/* Map CC1 to TI1 - TIM2_CH1 */
	TIM2->CCMR1 |= CCMR1_CC1S_0;
	TIM2->CCMR1 &= ~CCMR1_CC1S_1;

	/* Map CC2 to TI2 - TIM2_CH2 */
	TIM2->CCMR1 |= CCMR1_CC2S_0;
	TIM2->CCMR1 &= ~CCMR1_CC2S_1;

	/* Set rising edge as active edge */
	TIM2->CCER &= ~(CCER_CC1P | CCER_CC2P);

	/* Enable capture on both channels */
	TIM2->CCER |= (CCER_CC1E | CCER_CC2E);

	/* Enable counter */
	TIM2->CR1 |= CR1_CEN;
}

uint16_t tim2_rd(void) {
	return (uint16_t) (TIM2->CNT >> 2);
}
