#include "main.h"

void dummy_delay (int t){

	while(t--);
}


void EXTI0_IRQHandler(){


	mya_gpio_pin_write(GPIOD, GPIO_PIN_14, 1);
	dummy_delay(1680000);
	mya_gpio_pin_write(GPIOD, GPIO_PIN_14, 0);

	EXTI->PR |= (0x01); // clear pending bits


}

void nevermind1(){

	mya_gpio_pin_write(GPIOD, GPIO_PIN_14, 1);
	dummy_delay(1680000);
	mya_gpio_pin_write(GPIOD, GPIO_PIN_14, 0);

	EXTI->PR |= (0x01); // clear pending bits

}



int main(void)
{

	mya_rcc_clock_config();

//	RCC->AHB3ENR |= 0x01; // FMC enable
	

	GPIOD_EN();
	
	mya_gpio_pin_config(GPIOD, 12, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 13, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 14, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 15, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);


	GPIOA_EN();
	mya_gpio_pin_config(GPIOA, 0, GPIO_Mode_INPUT, GPIO_PuPd_NOPULL);


	//*((volatile uint32_t*) 0x40020000) |= (uint32_t) 999;
	//*((volatile uint32_t*) 0x40023C10) |= 0x01;
	//*((volatile uint32_t*) 0x20000000) = 999;
	//*((volatile uint32_t*) 0x20010004) = 999;

	//*((volatile uint32_t*) 0x20020004) = 899;
	//*((volatile uint32_t*) 0x22000004) = 999;

	/** interrupt service routine configurations ***/
	
//	RCC_SYSCFG_EN();
	// NVIC->ISER[0] |= 0x40; // Enable NVIC for EXTI0, atomic operation
	mya_nvic_enable(NVIC_EXTI0);
//	 SYSCFG->EXTICR[0] &= ~(0x0F); // first clear bits 0,1,2, and 3
//	 SYSCFG->EXTICR[0] |= 0x01; // choose PA0 for EXTI0 line
//	 EXTI->IMR |= 0x01; // unmask EXTI0
//	 EXTI->RTSR |= 0x01; // enable rising edge trigger for EXTI0 line
	RCC_SYSCFG_EN();
	mya_exti_config(EXTI_EXTI0, EXTI_PORT_A, EXTI_TRIG_RISING);
	NVIC->IPR[1] |= (0x01 << (16 + 4)); // set priority as 1 for EXTI0 line


	// SCB->VTOR = 0x20000A00;

	*((volatile uint32_t*) 0x20000A58) = 0x20202020;
	*((volatile uint32_t*) 0x20000A5C) = 0x30303030;
	//*((volatile uint32_t*) 0x20000A50) = 0x40405050;
	//*((volatile uint32_t*) 0x20000A54) = 0x60606060;

	//
	for(;;){

		//mya_gpio_pin_toggle(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14);
	
		// for (int i = 0; i < 99999; i++)
		// {
		// 	/* dummy delay */
		// }
		
		dummy_delay(3000000);
		mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 1);
		dummy_delay(3000000);
		mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 0);
		

	}

		return 0;
}
