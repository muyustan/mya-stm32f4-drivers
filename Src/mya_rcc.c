/*
 * mya_rcc.c
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#include "mya_rcc.h"

/* sets system clock to 168 MHz */
void mya_rcc_clock_config(void){

	/* System Clock Frequency when PLL used is calculated as 
	((INPUT_CLOCK (HSE_OR_HSI_IN_HZ) / PLL_M) * PLL_N) / PLL_P */

	// FLASH (this part is a key PART!!!)
	FLASH-> ACR |= (FLASH_ACR_LATENCY | FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN);
	
	RCC->CR |= RCC_CR_HSEON; // HSEON -> 1 Enable HSE clock
	while (!(RCC->CR & RCC_CR_HSERDY)) {;} // w8 for HSERDY flag

	RCC->CR |= RCC_CR_CSSON; // CSSON -> 1

	/* disable PLL before changes */
	RCC->CR &= ~RCC_CR_PLLON;
	while ((RCC->CR & RCC_CR_PLLRDY)) {} // wait till PLL is unlocked
	
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC; // HSE selected as PLL source 

	/* set PLLM value */
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_DIV4; // PLL_M = 4

	/* set PLLN value */
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_MUL168; // PLL_N = 168 (0xA8)

	/* set PLLP value */
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLP_DIV2; // PLL_P = 2

	/* set PLLQ value */
	// RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ);
	// RCC->PLLCFGR |= RCC_PLLCFGR_PLLQ_DIV2; // PLL_Q = 2
	/* not needed since the reset value for PLLQ is already 2 */

	RCC->CFGR &= ~RCC_CFGR_HPRE; // AHB prescaler = 1

	RCC->CFGR &= ~RCC_CFGR_PPRE1; // APB1 prescaler clear
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4; // APB1 prescaler = 4
	
	RCC->CFGR &= ~RCC_CFGR_PPRE2; // APB2 prescaler clear
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; // APB2 prescaler = 2

	RCC->CR |= RCC_CR_PLLON; // activate PLL
	while (!(RCC->CR & RCC_CR_PLLRDY)) {} // wait till PLL is locked/ready

	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL; // choose PLL as system clock
	/* Wait for SYSCLK to be PPL */
	while((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL);

	return;
}
