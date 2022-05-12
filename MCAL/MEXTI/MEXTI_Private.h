/*
 * MEXTI_Private.h
 *
 *  Created on: May 12, 2022 5:26:14 AM MEXTI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

/*EXTI Register Mapping*/
typedef struct
{
	/*Interrupt Mask Register*/
	volatile uint32 IMR;
	/*Event Mask Register*/
	volatile uint32 EMR;
	/*Rising Trigger Selection Register*/
	volatile uint32 RTSR;
	/*Falling Trigger Selection Register*/
	volatile uint32 FTSR;
	/*Software Interrupt Event Register*/
	volatile uint32 SWIER;
	/*Pending Register*/
	volatile uint32 PR;
}MEXTI_t;

/*EXTI Base address*/
#define EXTI  ((volatile MEXTI_t *)0x40010400)
#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
