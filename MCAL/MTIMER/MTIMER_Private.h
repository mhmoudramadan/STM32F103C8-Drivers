/*
 * MTIMER_Private.h
 *
 *  Created on: May 13, 2022 3:58:34 AM 
 *  Topic-->TIMER_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MTIMER_MTIMER_PRIVATE_H_
#define MCAL_MTIMER_MTIMER_PRIVATE_H_

/*Advanced Timer Register Mapping
 * --> 1 & 8*/
typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMCR;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CCMR1;
	volatile uint32 CCMR2;
	volatile uint32 CCER;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 RCR;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 BDTR;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}Advanced_Timer;

/*GPT--> General Purpose Timer register mapping
 * 2:5 & 9:14*/
typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SMCR;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CCMR1;
	volatile uint32 CCMR2;
	volatile uint32 CCER;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
	volatile uint32 CCR1;
	volatile uint32 CCR2;
	volatile uint32 CCR3;
	volatile uint32 CCR4;
	volatile uint32 DCR;
	volatile uint32 DMAR;
}GPT_Timer;

/*Basic Timer register Mapping
 *  6,7*/
typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 DIER;
	volatile uint32 SR;
	volatile uint32 EGR;
	volatile uint32 CNT;
	volatile uint32 PSC;
	volatile uint32 ARR;
}Basic_Timer;

/*Timer Base address */
/*Advanced Timer*/
#define TIM1  ((volatile Advanced_Timer*)0x40012C00)
#define TIM8  ((volatile Advanced_Timer*)0x40013400)

/*GPT*/
#define TIM2   	((volatile GPT_Timer*)0x40000000)
#define TIM3   	((volatile GPT_Timer*)0x40000400)
#define TIM4   	((volatile GPT_Timer*)0x40000800)
#define TIM5   	((volatile GPT_Timer*)0x40000C00)
#define TIM9   	((volatile GPT_Timer*)0x40014C00)
#define TIM10  	((volatile GPT_Timer*)0x40015000)
#define TIM11  	((volatile GPT_Timer*)0x40015400)
#define TIM12   ((volatile GPT_Timer*)0x40001800)
#define TIM13  	((volatile GPT_Timer*)0x40001C00)
#define TIM14	((volatile GPT_Timer*)0x4000200)


/*Basic Timer*/
#define TIM6   ((volatile Basic_Timer*)0x40001000)
#define TIM7   ((volatile Basic_Timer*)0x40001400)

#endif /* MCAL_MTIMER_MTIMER_PRIVATE_H_ */
