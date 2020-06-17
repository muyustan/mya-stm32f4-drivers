#include "main.h"

void dummy_delay (int t){

	while(t--);
}

void EXTI0_IRQHandler(){

	mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 1);
	dummy_delay(1680000);
	mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 0);

	EXTI->PR |= (0x01); // clear pending bits

}



int main(void)
{

	mya_rcc_clock_config();
	

	GPIOD_EN();
	
	mya_gpio_pin_config(GPIOD, 12, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 13, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 14, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 15, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);


	GPIOA_EN();
	mya_gpio_pin_config(GPIOA, 0, GPIO_Mode_INPUT, GPIO_PuPd_NOPULL);



	*((volatile uint32_t*) 0x40020000) |= (uint32_t) 999;
	*((volatile uint32_t*) 0x00000058) = 999;

	/** interrupt service routine configurations ***/
	
	RCC_SYSCFG_EN();
	NVIC->ISER[0] |= 0x40; // Enable NVIC for EXTI0, atomic operation
	SYSCFG->EXTICR[0] &= ~(0x0F); // first clear bits 0,1,2, and 3
	SYSCFG->EXTICR[0] |= 0x00; // choose PA0 for EXTI0 line
	EXTI->IMR |= 0x01; // unmask EXTI0
	EXTI->RTSR |= 0x01; // enable rising edge trigger for EXTI0 line
	//NVIC->IPR[1] |= (0x01 << (16 + 4)); // set priority as 1 for EXTI0 line

	//
	for(;;){

		//mya_gpio_pin_toggle(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14);
	
		// for (int i = 0; i < 99999; i++)
		// {
		// 	/* dummy delay */
		// }
		

	}

		return 0;
}
