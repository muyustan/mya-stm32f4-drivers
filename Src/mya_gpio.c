/*
 * mya_gpio.c
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#include "mya_gpio.h"


void mya_gpio_pin_config (GPIO_Type* GPIOx, uint32_t GPIO_PIN_x, GPIO_Mode Mode, GPIO_OType OType, GPIO_PuPd PuPd, GPIO_OSpeed OutSpeed){

	uint32_t temp = 0x00;
	uint8_t pos = 0;

	for (pos = 0; pos <= 15; pos++) {

		temp = (0x01 << pos);

		if (temp & GPIO_PIN_x) {

			GPIOx->MODER &= ~(0x03 << 2 * pos); // clear first, default to "input"
			GPIOx->MODER |= (Mode << 2 * pos); // set the mode

			GPIOx->OTYPER &= ~(0x01 << pos); // clear first, default to "push-pull"
			GPIOx->OTYPER |= (OType << pos); // set output type

			GPIOx->PUPDR &= ~(0x03 << 2 * pos); // clear first, default to "no pull up or pull down"
			GPIOx->PUPDR |= (PuPd << 2 * pos); // set pull up pull down choice

			GPIOx->OSPEEDR &= (0x03 << 2 * pos); // clear the bit field
			GPIOx->OSPEEDR |= (OutSpeed << 2 * pos); // set the output speed

		}

	}
	
	return;

}


uint8_t mya_gpio_pin_read(GPIO_Type* GPIOx, uint16_t GPIO_PIN_x) {

	return (GPIOx->IDR & (GPIO_PIN_x));

}

void mya_gpio_pin_write(GPIO_Type* GPIOx, uint16_t GPIO_PIN_x, GPIO_PinState State){

	/* just appreciate how beautiful BSRR is */

	if(State == LOW) {
		GPIOx->BSRR = GPIO_PIN_x << 16; // reset bits
	}
	else
		GPIOx->BSRR = GPIO_PIN_x; // set bits

	return;
}

void mya_gpio_pin_toggle(GPIO_Type* GPIOx, uint16_t GPIO_PIN_x){

	uint8_t pos = 0x00;
	uint16_t hold = 0x00;
	uint16_t temp = 0x00;

	for (pos = 0; pos <= 15; pos++) {

		temp = (0x01 << pos);

		if ((temp & GPIO_PIN_x) != 0) { // do not use "== 1" instead of "!= 0"
			hold |= temp;
		}

	}

	GPIOx->ODR ^= hold;
	
	return;
}

void mya_gpio_alternate_func_config(GPIO_Type* GPIOx, uint8_t pinNumber, uint8_t GPIO_AF_x){

	GPIOx->AFR[pinNumber >> 3] |= (GPIO_AF_x << (4 * (pinNumber % 8)));

	return;
}
