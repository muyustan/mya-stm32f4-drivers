/*
 * mya_rcc.h
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#ifndef MYA_RCC_H_
#define MYA_RCC_H_

#include "mya_stm32f407vg.h"

#define RCC_GPIOA_EN() (RCC->AHB1ENR |= (0x01 << 0))
#define RCC_GPIOB_EN() (RCC->AHB1ENR |= (0x01 << 1))
#define RCC_GPIOC_EN() (RCC->AHB1ENR |= (0x01 << 2))
#define RCC_GPIOD_EN() (RCC->AHB1ENR |= (0x01 << 3))
#define RCC_GPIOE_EN() (RCC->AHB1ENR |= (0x01 << 4))
#define RCC_GPIOF_EN() (RCC->AHB1ENR |= (0x01 << 5))
#define RCC_GPIOG_EN() (RCC->AHB1ENR |= (0x01 << 6))
#define RCC_GPIOH_EN() (RCC->AHB1ENR |= (0x01 << 7))
#define RCC_GPIOI_EN() (RCC->AHB1ENR |= (0x01 << 8))
#define RCC_GPIOJ_EN() (RCC->AHB1ENR |= (0x01 << 9))
#define RCC_GPIOK_EN() (RCC->AHB1ENR |= (0x01 << 10))

void mya_rcc_clock_config(void);

#endif /* MYA_RCC_H_ */
