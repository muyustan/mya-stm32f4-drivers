#include "main.h"

/* macro definitions */

#define GREEN_LED_PORT GPIOD
#define ORANGE_LED_PORT GPIOD
#define RED_LED_PORT GPIOD 
#define BLUE_LED_PORT GPIOD 

#define GREEN_LED_PIN GPIO_PIN_12
#define ORANGE_LED_PIN GPIO_PIN_13
#define RED_LED_PIN GPIO_PIN_14
#define BLUE_LED_PIN GPIO_PIN_15

/* end macro definitions */

int main(int argc, char **argv) {

	mya_rcc_clock_config();	

	GPIOD_EN();

	mya_gpio_pin_config(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_Mode_OUTPUT, GPIO_OType_PushPull, GPIO_PuPd_NoPull, GPIO_OSpeed_Medium);

	/*** USART ***/
	
	GPIOA_EN();
	GPIOB_EN();

	mya_gpio_alternate_func_config(GPIOB, 6, GPIO_AF_USART1_TX);
	mya_gpio_alternate_func_config(GPIOA, 10, GPIO_AF_USART1_RX);

	mya_gpio_pin_config(GPIOB, GPIO_PIN_6, GPIO_Mode_AF, GPIO_OType_PushPull, GPIO_PuPd_Up, GPIO_OSpeed_VeryHigh);

	mya_gpio_pin_config(GPIOA, GPIO_PIN_10, GPIO_Mode_AF, GPIO_OType_PushPull, GPIO_PuPd_Up, GPIO_OSpeed_VeryHigh);

	RCC_USART1_EN();
	mya_usart_init(USART1, 9600, 84);
	mya_nvic_enable(NVIC_USART1);
	
	for(;;){


	}

		return 0;
}

/* Interrupt Service Routines */

void USART1_IRQHandler(void) {

    /* check if the source for interrupt is RXNE */
	if (USART1->SR & USART_SR_RXNE){

			char command = USART1->DR;
			switch (command)
			{
			case 'G':
				mya_gpio_pin_toggle(GREEN_LED_PORT, GREEN_LED_PIN);
				break;
			case 'O':
				mya_gpio_pin_toggle(ORANGE_LED_PORT, ORANGE_LED_PIN);
				break;
			case 'R':
				mya_gpio_pin_toggle(RED_LED_PORT, RED_LED_PIN);
				break;
			case 'B':
				mya_gpio_pin_toggle(BLUE_LED_PORT, BLUE_LED_PIN);
				break;
			default:
				break;
			}

			/* echo the incoming char */
			mya_usart_transmit_byte(USART1, command);

		}

    // GPIOD->ODR ^= 0xF000;


    return;
}
