#ifndef MYA_STM32F407VG_H
#define MYA_STM32F407VG_H

#include <stdint.h>

#define WRITE_REG(REGADDR, WORD) (*((uint32_t *) REGADDR) = WORD) 
#define READ_REG(REGADDR) *((uint32_t *) REGADDR) 

/************ RCC ***********/

/* define bit masks for AHB1ENR */

#define RCC_AHB1ENR_GPIOAEN 	((uint32_t)0x000000001U)
#define RCC_AHB1ENR_GPIOBEN 	((uint32_t)0x000000002U)
#define RCC_AHB1ENR_GPIOCEN 	((uint32_t)0x000000004U)
#define RCC_AHB1ENR_GPIODEN 	((uint32_t)0x000000008U)
#define RCC_AHB1ENR_GPIOEEN 	((uint32_t)0x000000010U)
#define RCC_AHB1ENR_GPIOFEN 	((uint32_t)0x000000020U)
#define RCC_AHB1ENR_GPIOGEN 	((uint32_t)0x000000040U)
#define RCC_AHB1ENR_GPIOHEN 	((uint32_t)0x000000080U)
#define RCC_AHB1ENR_GPIOIEN 	((uint32_t)0x000000100U)
#define RCC_AHB1ENR_GPIOJEN 	((uint32_t)0x000000200U)
#define RCC_AHB1ENR_GPIOKEN 	((uint32_t)0x000000400U)
#define RCC_AHB1ENR_CRCEN		((uint32_t)0x000001000U)
#define RCC_AHB1ENR_BKPSRAMEN	((uint32_t)0x000040000U)
// ..........

/* define bit masks for PLLCFGR */

#define RCC_PLLCFGR_PLLM 	((uint32_t)0x0000003FU)
	#define RCC_PLLCFGR_PLLM_DIV4	 	((uint32_t)0x00000004U)
#define RCC_PLLCFGR_PLLN 	((uint32_t)0x00007FC0U)
	#define RCC_PLLCFGR_PLLN_MUL168 	((uint32_t)0x00002A00U)
#define RCC_PLLCFGR_PLLP 	((uint32_t)0x00030000U)
	#define RCC_PLLCFGR_PLLP_DIV2	 	((uint32_t)0x00000000U)
#define RCC_PLLCFGR_PLLSRC 	((uint32_t)0x00400000U)
#define RCC_PLLCFGR_PLLQ	((uint32_t)0x0F000000U)
	#define RCC_PLLCFGR_PLLQ_DIV2		((uint32_t)0x02000000U)

/* define bit masks for CR */

#define RCC_CR_HSEON 	((uint32_t)0x00010000U)
#define RCC_CR_HSERDY 	((uint32_t)0x00020000U)
#define RCC_CR_CSSON 	((uint32_t)0x00080000U)
#define RCC_CR_PLLON 	((uint32_t)0x01000000U)
#define RCC_CR_PLLRDY 	((uint32_t)0x02000000U)

/* define bit masks for CFGR */

#define RCC_CFGR_SW		((uint32_t)0x00000003U) // system clock switch
	#define RCC_CFGR_SW_HSI ((uint32_t)0x00000000U) // choose HSI as system clock
	#define RCC_CFGR_SW_HSE ((uint32_t)0x00000001U) // choose HSE as system clock
	#define RCC_CFGR_SW_PLL ((uint32_t)0x00000002U) // choose PLL as system clock
#define RCC_CFGR_SWS	((uint32_t)0x0000000CU)
	#define RCC_CFGR_SWS_HSI ((uint32_t)0x00000000U) // HSI used as system clock
	#define RCC_CFGR_SWS_HSE ((uint32_t)0x00000001U) // HSE used as system clock
	#define RCC_CFGR_SWS_PLL ((uint32_t)0x00000002U) // PLL used as system clock
#define RCC_CFGR_HPRE	((uint32_t)0x000000F0U)
#define RCC_CFGR_PPRE1 	((uint32_t)0x00001C00U)
#define RCC_CFGR_PPRE2 	((uint32_t)0x0000E000U)

#define RCC_BASE 0x40023800

typedef struct {

	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RESERVED_0;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RESERVED_1[2];
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RESERVED_2;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RESERVED_3[2];

} RCC_Type;

#define RCC ((RCC_Type*) RCC_BASE)

/********** END RCC *********/


/******* GPIO ********/

#define GPIO_BASE 0x40020000
#define GPIO_MEM_SIZE 0x0400

typedef struct {

	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2]; // AFRL and AFRH


} GPIO_Type;

#define GPIOA ((GPIO_Type*) GPIO_BASE)
#define GPIOB ((GPIO_Type*) (GPIO_BASE + GPIO_MEM_SIZE))
#define GPIOC ((GPIO_Type*) (GPIO_BASE + 2 * GPIO_MEM_SIZE))
#define GPIOD ((GPIO_Type*) (GPIO_BASE + 3 * GPIO_MEM_SIZE))
#define GPIOE ((GPIO_Type*) (GPIO_BASE + 4 * GPIO_MEM_SIZE))
#define GPIOF ((GPIO_Type*) (GPIO_BASE + 5 * GPIO_MEM_SIZE))
#define GPIOG ((GPIO_Type*) (GPIO_BASE + 6 * GPIO_MEM_SIZE))
#define GPIOH ((GPIO_Type*) (GPIO_BASE + 7 * GPIO_MEM_SIZE))
#define GPIOI ((GPIO_Type*) (GPIO_BASE + 8 * GPIO_MEM_SIZE))
#define GPIOJ ((GPIO_Type*) (GPIO_BASE + 9 * GPIO_MEM_SIZE))
#define GPIOK ((GPIO_Type*) (GPIO_BASE + 10 * GPIO_MEM_SIZE))

/*********** END GPIO *************/




/********** NVIC ***********/


#define NVIC_BASE 0xE000E100


typedef struct NVIC {

	volatile uint32_t ISER[8];
	volatile uint32_t RESERVED_1[24];
	volatile uint32_t ICER[8];
	volatile uint32_t RESERVED_2[24];
	volatile uint32_t ISPR[8];
	volatile uint32_t RESERVED_3[24];
	volatile uint32_t ICPR[8];
	volatile uint32_t RESERVED_4[24];
	volatile uint32_t IABR[8];
	volatile uint32_t RESERVED_5[24];
	// volatile uint32_t IPR[60];
	volatile uint8_t IPR[240]; // instead of the above one, this is more convenient since we will use them bytewise

} NVIC_Type;

#define NVIC ((NVIC_Type*) NVIC_BASE)

/********** END NVIC ********/

/********** SYSCFG *********/

#define SYSCFG_BASE 0x40013800

typedef struct SYSCFG {
	
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED[3];
	volatile uint32_t CMPCR;

} SYSCFG_Type;


#define SYSCFG ((SYSCFG_Type*) SYSCFG_BASE)


/******** END SYSCFG *******/


/********** EXTI **********/


#define EXTI_BASE 0x40013C00

typedef struct EXTI {
	
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

} EXTI_Type;

#define EXTI ((EXTI_Type*) EXTI_BASE)


/********* END EXTI *********/


/************ SCB (System Control Block) *************/


#define SCB_BASE 0xE000ED00U // ACTLR excluded

typedef struct SCB {

	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOR; // vector table offset register
	// continue filling, left at AIRCR register


} SCB_Type;

#define SCB ((SCB_Type*) SCB_BASE)

/*********** END SCB ************/


/************ SysTick ***********/

/* define bit masks */

#define SysTick_CTRL_ENABLE		((uint32_t)0x00000001U)
#define SysTick_CTRL_TICKINT	((uint32_t)0x00000002U)
#define SysTick_CTRL_CLKSOURCE	((uint32_t)0x00000004U)
#define SysTick_CTRL_COUNTFLAG	((uint32_t)0x00010000U)

#define SysTick_BASE ((uint32_t)0xE000E010U)

typedef struct SysTick {

	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;

} SysTick_Type;

#define SysTick ((SysTick_Type*) SysTick_BASE)

/********** END SysTick *********/




/********** FLASH ***************/

#define FLASH_BASE 0x40023C00

#define FLASH_ACR_LATENCY 	0x00000007U
#define FLASH_ACR_PRFTEN	0x00000100U
#define FLASH_ACR_ICEN		0x00000200U
#define FLASH_ACR_DCEN		0x00000400U


typedef struct FLASH {
	
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t OPTCR;

} FLASH_Type;

#define FLASH ((FLASH_Type*) FLASH_BASE)


/********* END FLASH **************/


#endif // header guard
