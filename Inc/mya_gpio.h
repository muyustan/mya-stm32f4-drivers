/*
 * mya_gpio.h
 *
 *  Created on: May 10, 2020
 *      Author: muyustan
 */

#ifndef MYA_GPIO_H_
#define MYA_GPIO_H_

#include "mya_stm32f407vg.h"

#define GPIOA_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN)
#define GPIOB_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN)
#define GPIOC_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN)
#define GPIOD_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN)
#define GPIOE_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN)
#define GPIOF_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN) 
#define GPIOG_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN)
#define GPIOH_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN)
#define GPIOI_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN)
#define GPIOJ_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN)
#define GPIOK_EN() (RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN)

/* alternate function configurations */


#define GPIO_AF_MCO1				(uint8_t)0x00U
#define GPIO_AF_JTMS_SWDIO			(uint8_t)0x00U
#define GPIO_AF_JTMS_SWCLK			(uint8_t)0x00U
#define GPIO_AF_JTDI_TRACESWO		(uint8_t)0x00U
#define GPIO_AF_NJTRST				(uint8_t)0x00U
#define GPIO_AF_RTC_REFIN			(uint8_t)0x00U
#define GPIO_AF_MCO2				(uint8_t)0x00U
#define GPIO_AF_TRACECLK			(uint8_t)0x00U
#define GPIO_AF_TRACED0				(uint8_t)0x00U
#define GPIO_AF_TRACED1				(uint8_t)0x00U
#define GPIO_AF_TRACED2				(uint8_t)0x00U
#define GPIO_AF_TRACED3				(uint8_t)0x00U


#define GPIO_AF_TIM2_CH1_ETR		(uint8_t)0x01U
#define GPIO_AF_TIM2_CH1			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH2			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH3			(uint8_t)0x01U
#define GPIO_AF_TIM2_CH4			(uint8_t)0x01U
#define GPIO_AF_TIM1_BKIN			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH1N			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH1			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH2			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH3			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH4			(uint8_t)0x01U
#define GPIO_AF_TIM1_ETR			(uint8_t)0x01U
#define GPIO_AF_TIM2_ETR			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH2N			(uint8_t)0x01U
#define GPIO_AF_TIM1_CH3N			(uint8_t)0x01U



#define GPIO_AF_USART1_TX			(uint8_t)0x07U
#define GPIO_AF_USART1_RX			(uint8_t)0x07U



//#define GPIO_AF_MCO1	(uint8_t)0x08U
//#define GPIO_AF_MCO1	(uint8_t)0x09U
//#define GPIO_AF_MCO1	(uint8_t)0x0AU
//#define GPIO_AF_MCO1	(uint8_t)0x0BU
//#define GPIO_AF_MCO1	(uint8_t)0x0CU
//#define GPIO_AF_MCO1	(uint8_t)0x0DU
//#define GPIO_AF_MCO1	(uint8_t)0x0EU
//#define GPIO_AF_MCO1	(uint8_t)0x0FU




/* end alternate function configurations */



typedef enum MODER {

	GPIO_Mode_INPUT =	0b00,
	GPIO_Mode_OUTPUT =	0b01,
	GPIO_Mode_AF =		0b10,
	GPIO_Mode_ANALOG =	0b11

} GPIO_Mode;

typedef enum PUPDR {

	GPIO_PuPd_NoPull=	0b00,
	GPIO_PuPd_Up =		0b01,
	GPIO_PuPd_Down =	0b10
	// 0x03 is reserved

} GPIO_PuPd;

typedef enum OTYPER {

	GPIO_OType_PushPull =	0b0,
	GPIO_OType_OpenDrain =	0b1,

} GPIO_OType;

typedef enum OSPEEDR {

	GPIO_OSpeed_Low =		0b00,
	GPIO_OSpeed_Medium =	0b01,
	GPIO_OSpeed_High =		0b10,
	GPIO_OSpeed_VeryHigh =	0b11,


} GPIO_OSpeed;

typedef enum PIN_STATE {

	GPIO_PinState_LOW = 0,
	GPIO_PinState_HIGH = 1

} GPIO_PinState;


void mya_gpio_pin_config (GPIO_Type* GPIOx, uint32_t GPIO_PIN_x, GPIO_Mode Mode, GPIO_OType OType, GPIO_PuPd PuPd, GPIO_OSpeed OutSpeed);

uint8_t mya_gpio_pin_read (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x);

void mya_gpio_pin_write (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x, GPIO_PinState State);

void mya_gpio_pin_toggle (GPIO_Type* GPIOx, uint16_t GPIO_PIN_x);

void mya_gpio_alternate_func_config(GPIO_Type* GPIOx, uint8_t pinNumber, uint8_t GPIO_AF_x);


#endif /* MYA_GPIO_H_ */
