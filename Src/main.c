#include "main.h"

void dummy_delay (int t){

	while(t--);
}


void EXTI0_IRQHandler(){

	EXTI->PR |= (0x01); // clear pending bits

	mya_gpio_pin_toggle(GPIOD, GPIO_PIN_14);

}



int main(void)
{

	mya_rcc_clock_config();	

	GPIOD_EN();
	
	mya_gpio_pin_config(GPIOD, 12, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	// mya_gpio_pin_config(GPIOD, 13, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 14, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);
	mya_gpio_pin_config(GPIOD, 15, GPIO_Mode_OUTPUT, GPIO_PuPd_NOPULL);


	GPIOA_EN();
	mya_gpio_pin_config(GPIOA, 0, GPIO_Mode_INPUT, GPIO_PuPd_NOPULL);


	/** interrupt service routine configurations ***/
	
	mya_exti_init();
	mya_exti_config(EXTI_EXTI0, EXTI_PORT_A, EXTI_TRIG_RISING);
	mya_nvic_enable(NVIC_EXTI0);
	NVIC->IPR[1] |= (0x01 << (16 + 4)); // set priority as 1 for EXTI0 line

	/*** timer pwm **/

	


	// SCB->VTOR = 0x20000A00;

	
	for(;;){

		mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 1);
		mya_delay_ms(5000);
		mya_gpio_pin_write(GPIOD, GPIO_PIN_15, 0);
		mya_delay_ms(1500);


	}

		return 0;
}
