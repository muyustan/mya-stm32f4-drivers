#ifndef MYA_STM32F407VG_H
#define MYA_STM32F407VG_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define WRITE_MEM(MEMADDR, WORD) (*((uint32_t *) MEMADDR) = WORD) 
#define READ_MEM(MEMADDR) *((uint32_t *) MEMADDR)
#define HIGH	1
#define LOW		0

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


/* define bit masks for APB1ENR */

#define RCC_APB1ENR_TIM2EN	((uint32_t))0x00000001U)
#define RCC_APB1ENR_TIM3EN	((uint32_t))0x00000002U)
#define RCC_APB1ENR_TIM4EN	((uint32_t))0x00000004U)
#define RCC_APB1ENR_TIM5EN	((uint32_t))0x00000008U)
#define RCC_APB1ENR_TIM6EN	((uint32_t))0x00000010U)
#define RCC_APB1ENR_TIM7EN	((uint32_t))0x00000020U)
#define RCC_APB1ENR_TIM12EN	((uint32_t))0x00000040U)
#define RCC_APB1ENR_TIM13EN	((uint32_t))0x00000080U)
#define RCC_APB1ENR_TIM14EN	((uint32_t))0x00000100U)
// .........

/* define bit masks for APB2ENR */

#define RCC_APB2ENR_TIM1EN			((uint32_t)0x00000001U)
#define RCC_APB2ENR_TIM8EN			((uint32_t)0x00000002U)
// bits [3:2] reserved
#define RCC_APB2ENR_USART1EN		((uint32_t)0x00000010U)
#define RCC_APB2ENR_USART6EN		((uint32_t)0x00000020U)
// bits [7:6] reserved
#define RCC_APB2ENR_ADC1EN			((uint32_t)0x00000100U)
#define RCC_APB2ENR_ADC2EN			((uint32_t)0x00000200U)
#define RCC_APB2ENR_ADC3EN			((uint32_t)0x00000400U)
#define RCC_APB2ENR_SDIOEN			((uint32_t)0x00000800U)
#define RCC_APB2ENR_SPI1EN			((uint32_t)0x00001000U)
#define RCC_APB2ENR_SPI4EN			((uint32_t)0x00002000U)
#define RCC_APB2ENR_SYSCFGEN		((uint32_t)0x00004000U)
// bit 15 reserved
#define RCC_APB2ENR_TIM9			((uint32_t)0x00010000U)
#define RCC_APB2ENR_TIM10			((uint32_t)0x00020000U)
#define RCC_APB2ENR_TIM11			((uint32_t)0x00040000U)
// reserved							((uint32_t)0x00080000U)
#define RCC_APB2ENR_SPI5EN			((uint32_t)0x00100000U)
#define RCC_APB2ENR_SPI6EN			((uint32_t)0x00200000U)
#define RCC_APB2ENR_SAI1EN			((uint32_t)0x00400000U)
// reserved							((uint32_t)0x00800000U)
// reserved							((uint32_t)0x01000000U)
// reserved							((uint32_t)0x02000000U)
#define RCC_APB2ENR_LTDCEN			((uint32_t)0x04000000U)
// bits [31:27] reserved


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
	#define RCC_CFGR_HPRE_DIV1		((uint32_t)0x00000000U)
	#define RCC_CFGR_HPRE_DIV2		((uint32_t)0x00000080U)
	#define RCC_CFGR_HPRE_DIV4		((uint32_t)0x00000090U)
	#define RCC_CFGR_HPRE_DIV8		((uint32_t)0x000000A0U)
	#define RCC_CFGR_HPRE_DIV16		((uint32_t)0x000000B0U)
	#define RCC_CFGR_HPRE_DIV64		((uint32_t)0x000000C0U)
	#define RCC_CFGR_HPRE_DIV128	((uint32_t)0x000000D0U)
	#define RCC_CFGR_HPRE_DIV256	((uint32_t)0x000000E0U)
	#define RCC_CFGR_HPRE_DIV512	((uint32_t)0x000000F0U)
#define RCC_CFGR_PPRE1 	((uint32_t)0x00001C00U)
	#define RCC_CFGR_PPRE1_DIV1 	((uint32_t)0x00000000U)
	#define RCC_CFGR_PPRE1_DIV2 	((uint32_t)0x00001000U)
	#define RCC_CFGR_PPRE1_DIV4 	((uint32_t)0x00001400U)
	#define RCC_CFGR_PPRE1_DIV8 	((uint32_t)0x00001800U)
	#define RCC_CFGR_PPRE1_DIV16 	((uint32_t)0x00001C00U)
#define RCC_CFGR_PPRE2 	((uint32_t)0x0000E000U)
	#define RCC_CFGR_PPRE2_DIV1 	((uint32_t)0x00000000U)
	#define RCC_CFGR_PPRE2_DIV2 	((uint32_t)0x00008000U)
	#define RCC_CFGR_PPRE2_DIV4 	((uint32_t)0x0000A000U)
	#define RCC_CFGR_PPRE2_DIV8 	((uint32_t)0x0000C000U)
	#define RCC_CFGR_PPRE2_DIV16 	((uint32_t)0x0000E000U)

	/* define bit masks for CIR */

#define RCC_CIR_HSERDYC ((uint32_t)0x00080000U)

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

#define GPIOA_BASE 0x40020000U
#define GPIOB_BASE 0x40020400U
#define GPIOC_BASE 0x40020800U
#define GPIOD_BASE 0x40020C00U
#define GPIOE_BASE 0x40021000U
#define GPIOF_BASE 0x40021400U
#define GPIOG_BASE 0x40021800U
#define GPIOH_BASE 0x40021C00U
#define GPIOI_BASE 0x40022000U
#define GPIOJ_BASE 0x40022400U
#define GPIOK_BASE 0x40022800U

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

#define GPIOA ((GPIO_Type*) GPIOA_BASE)
#define GPIOB ((GPIO_Type*) GPIOB_BASE)
#define GPIOC ((GPIO_Type*) GPIOC_BASE)
#define GPIOD ((GPIO_Type*) GPIOD_BASE)
#define GPIOE ((GPIO_Type*) GPIOE_BASE)
#define GPIOF ((GPIO_Type*) GPIOF_BASE)
#define GPIOG ((GPIO_Type*) GPIOG_BASE)
#define GPIOH ((GPIO_Type*) GPIOH_BASE)
#define GPIOI ((GPIO_Type*) GPIOI_BASE)
#define GPIOJ ((GPIO_Type*) GPIOJ_BASE)
#define GPIOK ((GPIO_Type*) GPIOK_BASE)

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

/******** TIMERS ************/

#define TIM_CR_CEN	0x0001U
#define TIM_CR_UDIS	0x0002U
#define TIM_CR_URS	0x0004U
#define TIM_CR_OPM	0x0008U
#define TIM_CR_DIR	0x0010U
#define TIM_CR_CMS	0x0060U
#define TIM_CR_ARPE	0x0080U
#define TIM_CR_CKD	0x0300U

/******** TIM1 and TIM8 ***********/

#define TIM1_BASE 0x40010000
#define TIM8_BASE 0x40010400

typedef struct TIM1_and_TIM8
{
	volatile uint32_t CR1; // offset 0x00
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR; // offset 0x4C

} TIM_1_8_Type;


#define TIM1 ((TIM_1_8_Type*) TIM1_BASE)
#define TIM8 ((TIM_1_8_Type*) TIM8_BASE)


/******* END TIM1 and TIM8 ********/ 

/******** TIM2 to TIM5 ***********/

#define TIM2_BASE 0x40000000
#define TIM3_BASE 0x40000400
#define TIM4_BASE 0x40000800
#define TIM5_BASE 0x40000C00

typedef struct TIM2_to_TIM5
{
	volatile uint32_t CR1; // offset 0x00
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RESERVED_0;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t RESERVED_1;
	volatile uint32_t DCR;
	volatile uint32_t DMAR; // offset 0x4C
	volatile uint32_t TIM2_OR; 
	volatile uint32_t TIM5_OR; 

} TIM_2_to_5_Type;


#define TIM2 ((TIM_2_to_5_Type*) TIM2_BASE)
#define TIM3 ((TIM_2_to_5_Type*) TIM3_BASE)
#define TIM4 ((TIM_2_to_5_Type*) TIM4_BASE)
#define TIM5 ((TIM_2_to_5_Type*) TIM5_BASE)


/******* END TIM2 to TIM5 ********/ 

/******* END TIMERS *********/

/********** U(S)ART ************/

#define USART1_BASE 0x40011000U
#define USART2_BASE 0x40004400U
#define USART3_BASE 0x40004800U
#define USART6_BASE 0x40011400U

#define UART4_BASE 0x40004C00U
#define UART5_BASE 0x40005000U
#define UART7_BASE 0x40007800U
#define UART8_BASE 0x40007C00U

/* define bit masks for SR */

#define USART_SR_PE			((uint32_t)0x00000001U)
#define USART_SR_FE			((uint32_t)0x00000002U)
#define USART_SR_NF			((uint32_t)0x00000004U)
#define USART_SR_ORE		((uint32_t)0x00000008U)
#define USART_SR_IDLE		((uint32_t)0x00000010U)
#define USART_SR_RXNE		((uint32_t)0x00000020U)
#define USART_SR_TC			((uint32_t)0x00000040U)
#define USART_SR_TXE		((uint32_t)0x00000080U)
#define USART_SR_LBD		((uint32_t)0x00000100U)
#define USART_SR_CTS		((uint32_t)0x00000200U)

/* define bit masks for BRR */

#define USART_BRR_DIV_Fraction ((uint32_t)0x0000000FU)
#define USART_BRR_DIV_Mantissa ((uint32_t)0x0000FFF0U)

/* define bit masks for CR1 */

#define USART_CR1_SBK			((uint32_t)0x00000001U)
#define USART_CR1_RWU			((uint32_t)0x00000002U)
#define USART_CR1_RE			((uint32_t)0x00000004U)
#define USART_CR1_TE			((uint32_t)0x00000008U)
#define USART_CR1_IDLEIE		((uint32_t)0x00000010U)
#define USART_CR1_RXNEIE		((uint32_t)0x00000020U)
#define USART_CR1_TCIE			((uint32_t)0x00000040U)
#define USART_CR1_TXEIE			((uint32_t)0x00000080U)
#define USART_CR1_PEIE			((uint32_t)0x00000100U)
#define USART_CR1_PS			((uint32_t)0x00000200U)
#define USART_CR1_PCE			((uint32_t)0x00000400U)
#define USART_CR1_WAKE			((uint32_t)0x00000800U)
#define USART_CR1_M				((uint32_t)0x00001000U)
#define USART_CR1_UE			((uint32_t)0x00002000U)
// bit 14 is reserved
#define USART_CR1_OVER8			((uint32_t)0x00008000U)


typedef struct USART_UART {

	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

} USART_Type;

#define USART1 ((USART_Type*) USART1_BASE)
#define USART2 ((USART_Type*) USART2_BASE)
#define USART3 ((USART_Type*) USART3_BASE)
#define USART6 ((USART_Type*) USART6_BASE)

#define UART4 ((USART_Type*) UART4_BASE)
#define UART5 ((USART_Type*) UART5_BASE)
#define UART7 ((USART_Type*) UART7_BASE)
#define UART8 ((USART_Type*) UART8_BASE)

/******* END U(S)ART ***********/


#endif // header guard
