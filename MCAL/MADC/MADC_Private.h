/*
 * MADC_Private.h
 *
 *  Created on: May 16, 2022 3:20:45 AM 
 *  Topic-->ADC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

/*ADC Register Mapping*/
typedef struct
{
	volatile uint32 SR;
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMPR1;
	volatile uint32 SMPR2;
	volatile uint32 JOFR1;
	volatile uint32 JOFR2;
	volatile uint32 JOFR3;
	volatile uint32 JOFR4;
	volatile uint32 HTR;
	volatile uint32 LTR;
	volatile uint32 SQR1;
	volatile uint32 SQR2;
	volatile uint32 SQR3;
	volatile uint32 JSQR;
	volatile uint32 JDR1;
	volatile uint32 JDR2;
	volatile uint32 JDR3;
	volatile uint32 JDR4;
	volatile uint32 DR;
}MADC_t;

/*ADC Base Address*/
#define ADC1_BASE 					0x40012400
#define ADC2_BASE					0x40012800
#define ADC3_BASE					0x40013C00
#define MAX_NO_OF_ADC_PERIPHERAL	3

volatile MADC_t *MADC_Channels[MAX_NO_OF_ADC_PERIPHERAL]=
{
		((volatile MADC_t *)ADC1_BASE),
		((volatile MADC_t *)ADC2_BASE),
		((volatile MADC_t *)ADC3_BASE)
};

/*Register Bit Definitions*/
/*SR*/
#define EOC		1
#define STRT	4
/*CR1*/
#define EOCIE		5
#define SCAN		8
#define DISCEN		11
#define DISCNUM		13
/*CR2*/
#define ADON     0
#define CONT     1
#define CAL      2
#define RSTCAL   3
#define DMA      8
#define ALIGN    11
#define EXTSEL   17
#define EXTTRIG  20
#define SWSTART  22
/*SMPR1 Register*/
#define SMP10    0
#define SMP11    3
#define SMP12    6
#define SMP13    9
#define SMP14    12
#define SMP15    15
#define SMP16    18
#define SMP17    21
/*SMPR2*/
#define SMP0     0
#define SMP1     3
#define SMP2     6
#define SMP3     9
#define SMP4     12
#define SMP5     15
#define SMP6     18
#define SMP7     21
#define SMP8     24
#define SMP9     27
/*SQR1*/
#define SQ13     0
#define SQ14     5
#define SQ15     10
#define SQ16     15
#define L0       20
/*SQR2*/
#define SQ7      0
#define SQ8      5
#define SQ9      10
#define SQ10     15
#define SQ11     20
#define SQ12     25
/*SQR3*/
#define SQ1      0
#define SQ2      5
#define SQ3      10
#define SQ4      15
#define SQ5      20
#define SQ6      25

#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
