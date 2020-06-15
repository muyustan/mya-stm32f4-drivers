/*
 * mya_rcc.c
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#include "mya_rcc.h"

void mya_rcc_clock_config(void){

	// sets system clock to 168 MHz

	RCC->CR |= (0x01 << 16); // HSEON -> 1
	while (!(RCC->CR & (0x01 << 17))) {;} // w8 for HSERDY flag
	RCC->CR |= (0x01 << 19); // CSSON -> 1

	RCC->PLLCFGR |= (0x01 << 22); // HSE selected as PLL source
	RCC->PLLCFGR |= 0x04; // PLL_M = 4
	RCC->PLLCFGR |= (0xA8 << 6); // PLL_N = 168 (0xA8)
	RCC->PLLCFGR |= 0x00; // PLL_P = 2

	RCC->CFGR |= (0x00 << 4); // AHB prescaler = 1
	RCC->CFGR |= (0x05 << 10); // APB1 prescaler = 4
	RCC->CFGR |= (0x04 << 13); // APB2 prescaler = 2

	RCC->CIR |= (0x01 << 19); // Clear HSERDY flag
	RCC->CIR |= (0x01 << 23); // Clear CSS flag

	return;
}

