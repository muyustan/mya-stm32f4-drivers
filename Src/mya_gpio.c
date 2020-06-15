/*
 * mya_gpio.c
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#include "mya_gpio.h"

void mya_gpio_pin_config (GPIO_Type* Port, uint32_t Pin, GPIO_Mode Mode, GPIO_PuPd PuPd){

	Port->MODER &= ~(0x03 << 2 * Pin); // clear first, default to "input"
	Port->OTYPER &= ~(0x01 << Pin); // clear first, default to "push-pull"
	Port->PUPDR &= ~(0x03 << 2 * Pin); // clear first, default to "no pull up or pull down"
	Port->OSPEEDR &= ~(0x03 << 2 * Pin); // clear first, default to "low speed"

	Port->MODER |= (Mode << 2 * Pin); // set the mode
	// Port->OSPEEDR |= (OutSpeed << 2 * Pin); // set the output speed

	if(Mode == GPIO_Mode_OUTPUT){

		Port->PUPDR &= ~(0x00 << 2 * Pin); // ensure no internal pull up or down

	}

	else if (Mode == GPIO_Mode_INPUT){

		Port->PUPDR &= ~(PuPd << 2 * Pin); // set the pu-pd choice

	}


	return;

}


uint8_t mya_gpio_pin_read(GPIO_Type* Port, uint16_t Pin) {

	return (Port->IDR & (Pin));

}

void mya_gpio_pin_write(GPIO_Type* Port, uint16_t Pin, GPIO_PinState State){

	/* just appreciate how beautiful BSRR is */

	if(State == LOW) {
		Port->BSRR = Pin << 16; // reset bits
	}
	else
		Port->BSRR = Pin; // set bits

	return;
}

void mya_gpio_pin_toggle(GPIO_Type* Port, uint16_t Pin){

	uint8_t pos = 0x00;
	uint16_t hold = 0x00;
	uint16_t temp = 0x00;

	for (pos = 0; pos <= 15; pos++) {

		temp = (0x01 << pos);

		if ((temp & Pin) != 0) { // do not use "== 1" instead of "!= 0"
			hold |= temp;
		}

	}

	Port->ODR ^= hold;
	
	return;
}
