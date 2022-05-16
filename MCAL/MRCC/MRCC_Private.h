/*
 * MRCC_Private.h
 *
 *  Created on: May 10, 2022 3:59:23 AM RCC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_

/*Base Address 0x40021000*/

#define RCC_CR 			*((volatile uint32*)0x40021000)
#define RCC_CFGR 		*((volatile uint32*)0x40021004)
#define RCC_CIR 		*((volatile uint32*)0x40021008)
#define RCC_APB2RSTR 	*((volatile uint32*)0x4002100C)
#define RCC_APB1RSTR 	*((volatile uint32*)0x40021010)
#define RCC_AHBENR 		*((volatile uint32*)0x40021014)
#define RCC_APB2ENR 	*((volatile uint32*)0x40021018)
#define RCC_APB1ENR 	*((volatile uint32*)0x4002101C)
#define RCC_BDCR    	*((volatile uint32*)0x40021020)
#define RCC_CSR			*((volatile uint32*)0x40021024)

/*clock security option*/
#define ENABLE  1
#define DISABLE 0

/*Clock System option*/
#define RCC_HSE_CRYSTAL    0
#define RCC_HSE_RC		   1
#define RCC_HSI            2
#define RCC_PLL            3
/*PLL source*/
#define RCC_PLL_HSI_SOURCE_BY2	0
#define RCC_PLL_HSE_SOURCE		1
#define RCC_PLL_HSE_SOURCE_BY2	2
/*option for MCO PIN source*/
#define NO_SOUCRE		0
#define HSE_SOURCE		1
#define HSI_SOURCE		2
#define PLL_SOURCE		3
#define SYSTME_SOURCE	4
/*ADC Prescaler*/
#define RCC_PRESCALER_2		2
#define RCC_PRESCALER_4		3
#define RCC_PRESCALER_6		4
#define RCC_PRESCALER_8		5
/*RCC_APB1 PRESCALER Option*/
#define RCC_PPRE1_PRESCALER_0     0
#define RCC_PPRE1_PRESCALER_2     ((uint32)0x00000400)
#define RCC_PPRE1_PRESCALER_4     ((uint32)0x00000500)
#define RCC_PPRE1_PRESCALER_8     ((uint32)0x00000600)
#define RCC_PPRE1_PRESCALER_16    ((uint32)0x00000700)

/*RCC_APB2 PRESCALER Option*/

#define  RCC_PPRE2_PRESCALER_0   0
#define  RCC_PPRE2_PRESCALER_2    ((uint32)0x00002000)
#define  RCC_PPRE2_PRESCALER_4    ((uint32)0x00002800)
#define  RCC_PPRE2_PRESCALER_8    ((uint32)0x00003000)
#define  RCC_PPRE2_PRESCALER_16   ((uint32)0x00003800)

/*RCC_AHB PRESCALER Option*/
#define RCC_HPRE_PRESCALER_0    0
#define RCC_HPRE_PRESCALER_2    ((uint32)0x00000080)
#define RCC_HPRE_PRESCALER_4    ((uint32)0x00000090)
#define RCC_HPRE_PRESCALER_8    ((uint32)0x000000A0)
#define RCC_HPRE_PRESCALER_16   ((uint32)0x000000B0)
#define RCC_HPRE_PRESCALER_64   ((uint32)0x000000C0)
#define RCC_HPRE_PRESCALER_128  ((uint32)0x000000D0)
#define RCC_HPRE_PRESCALER_256  ((uint32)0x000000E0)
#define RCC_HPRE_PRESCALER_512  ((uint32)0x000000F0)

/*RCC CR Register BITS*/
#define RCC_CR_HSION		0
#define RCC_CR_HSIRDY		1
#define RCC_CR_HSITRIM0		3
#define RCC_CR_HSITRIM1		4
#define RCC_CR_HSITRIM2		5
#define RCC_CR_HSITRIM3		6
#define RCC_CR_HSITRIM4		7
#define RCC_CR_HSICAL0		8
#define RCC_CR_HSICAL1		9
#define RCC_CR_HSICAL2		10
#define RCC_CR_HSICAL3		11
#define RCC_CR_HSICAL4		12
#define RCC_CR_HSICAL5		13
#define RCC_CR_HSICAL6		14
#define RCC_CR_HSICAL7		15
#define RCC_CR_HSEON		16
#define RCC_CR_HSERDY		17
#define RCC_CR_HSEBYP		18
#define RCC_CR_CSSON		19
#define RCC_CR_PLLON		24
#define RCC_CR_PLLRDY		25

/*RCC CFGR Register BITS*/
#define RCC_CFGR_SW0			0
#define RCC_CFGR_SW1			1
#define RCC_CFGR_SWS0			2
#define RCC_CFGR_SWS1			3
#define RCC_CFGR_HPRE0			4
#define RCC_CFGR_HPRE2			5
#define RCC_CFGR_HPRE3			6
#define RCC_CFGR_HPRE4			7
#define RCC_CFGR_PPRE1_0		8
#define RCC_CFGR_PPRE1_1		9
#define RCC_CFGR_PPRE1_2		10
#define RCC_CFGR_PPRE2_0		11
#define RCC_CFGR_PPRE2_1		12
#define RCC_CFGR_PPRE2_2		13
#define RCC_CFGR_ADCPRE0		14
#define RCC_CFGR_ADCPRE1		15
#define RCC_CFGR_PLLSRC			16
#define RCC_CFGR_PLLXTPRE		17
#define RCC_CFGR_PLLMUL0		18
#define RCC_CFGR_PLLMUL1		19
#define RCC_CFGR_PLLMUL2		20
#define RCC_CFGR_PLLMUL3		21
#define RCC_CFGR_USBPRE			22
#define RCC_CFGR_MCO_0			24
#define RCC_CFGR_MCO_1			25
#define RCC_CFGR_MCO_2			26

#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
