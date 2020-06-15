/*
 * mya_gpio.h
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#ifndef MYA_GPIO_H_
#define MYA_GPIO_H_

#include "mya_stm32f407vg.h"

#define GPIO_PIN_0  0x00000001
#define GPIO_PIN_1  0x00000002
#define GPIO_PIN_2  0x00000004
#define GPIO_PIN_3  0x00000008
#define GPIO_PIN_4  0x00000010
#define GPIO_PIN_5  0x00000020
#define GPIO_PIN_6  0x00000040
#define GPIO_PIN_7  0x00000080
#define GPIO_PIN_8  0x00000100
#define GPIO_PIN_9  0x00000200
#define GPIO_PIN_10 0x00000400
#define GPIO_PIN_11 0x00000800
#define GPIO_PIN_12 0x00001000
#define GPIO_PIN_13 0x00002000
#define GPIO_PIN_14 0x00004000
#define GPIO_PIN_15 0x00008000

#define GPIOA_EN() (RCC->AHB1ENR |= (0x01 << 0))
#define GPIOB_EN() (RCC->AHB1ENR |= (0x01 << 1))
#define GPIOC_EN() (RCC->AHB1ENR |= (0x01 << 2))
#define GPIOD_EN() (RCC->AHB1ENR |= (0x01 << 3))
#define GPIOE_EN() (RCC->AHB1ENR |= (0x01 << 4))
#define GPIOF_EN() (RCC->AHB1ENR |= (0x01 << 5))
#define GPIOG_EN() (RCC->AHB1ENR |= (0x01 << 6))
#define GPIOH_EN() (RCC->AHB1ENR |= (0x01 << 7))
#define GPIOI_EN() (RCC->AHB1ENR |= (0x01 << 8))
#define GPIOJ_EN() (RCC->AHB1ENR |= (0x01 << 9))
#define GPIOK_EN() (RCC->AHB1ENR |= (0x01 << 10))



typedef enum MODE {

	GPIO_Mode_INPUT = 0b00,
	GPIO_Mode_OUTPUT = 0b01,
	GPIO_Mode_AF = 0b10,
	GPIO_Mode_ANALOG = 0b11

} GPIO_Mode;

typedef enum OTYPE {

	GPIO_PuPd_NOPULL= 0b00,
	GPIO_PuPd_UP = 0b01,
	GPIO_PuPd_DOWN = 0b10
	// 0x03 is reserved

} GPIO_PuPd;

typedef enum PIN_STATE {

	LOW = 0,
	HIGH = 1

} GPIO_PinState;


void mya_gpio_pin_config (GPIO_Type* Port, uint32_t Pin, GPIO_Mode Mode, GPIO_PuPd PuPd);
uint8_t mya_gpio_pin_read (GPIO_Type* Port, uint16_t Pin);
void mya_gpio_pin_write (GPIO_Type* Port, uint16_t Pin, GPIO_PinState State);
void mya_gpio_pin_toggle (GPIO_Type* Port, uint16_t Pin);



#endif /* MYA_GPIO_H_ */
