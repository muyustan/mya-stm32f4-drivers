#include "main.h"


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


	for(;;){

		mya_gpio_pin_write(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14, LOW);



	if (mya_gpio_pin_read(GPIOA, GPIO_PIN_0))
	{
		/* code */

		mya_gpio_pin_write(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14, 1);


	}
	
		// for (int i = 0; i < 99999; i++)
		// {
		// 	/* dummy delay */
		// }
		


	}

		return 0;
}
