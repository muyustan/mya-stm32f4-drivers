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

	mya_gpio_pin_config(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_Mode_OUTPUT, GPIO_OType_PushPull, GPIO_PuPd_NOPULL, GPIO_OSpeed_Medium);

//
//	GPIOA_EN();
//	mya_gpio_pin_config(GPIOA, GPIO_PIN_0, GPIO_Mode_INPUT, GPIO_OType_PushPull, GPIO_PuPd_NOPULL);
//
//
//	/** interrupt service routine configurations ***/
//
//	mya_exti_init();
//	mya_exti_config(EXTI_EXTI0, EXTI_PORT_A, EXTI_TRIG_RISING);
//	mya_nvic_enable(NVIC_EXTI0);
//	NVIC->IPR[1] |= (0x01 << (16 + 4)); // set priority as 1 for EXTI0 line

	/*** USART ***/

	RCC_USART1_EN();
	GPIOA_EN();
	GPIOB_EN();

	mya_gpio_alternate_func_config(GPIOB, 6, GPIO_AF_USART1_TX);
	mya_gpio_alternate_func_config(GPIOA, 10, GPIO_AF_USART1_RX);

	mya_gpio_pin_config(GPIOB, GPIO_PIN_6, GPIO_Mode_AF, GPIO_OType_PushPull, GPIO_PuPd_UP, GPIO_OSpeed_VeryHigh);

	mya_gpio_pin_config(GPIOA, 10, GPIO_Mode_AF, GPIO_OType_PushPull, GPIO_PuPd_UP, GPIO_OSpeed_VeryHigh);

	mya_usart_init(USART1, 9600, 84);
	
	for(;;){

		USART1->DR = 0x41;
		while(!(USART1->SR & USART_SR_TC)) {;}
		USART1->DR = '\n';
		while(!(USART1->SR & USART_SR_TC)) {;}
		USART1->DR = '\r';
		while(!(USART1->SR & USART_SR_TC)) {;}
		mya_gpio_pin_toggle(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);
		mya_delay_ms(500);

	}

		return 0;
}
