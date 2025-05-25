/*
 * systick.h
 *
 *  Created on: May 11, 2025
 *      Author: gabri
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#include "../Drivers/CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"

void systick_ms_delay(uint32_t delay);
void systick_us_delay(uint32_t delay);

#endif /* SYSTICK_H_ */
