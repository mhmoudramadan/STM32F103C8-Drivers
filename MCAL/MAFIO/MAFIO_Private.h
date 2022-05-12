/*
 * MAFIO_Private.h
 *
 *  Created on: May 12, 2022 9:49:48 AM AFIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MAFIO_MAFIO_PRIVATE_H_
#define MCAL_MAFIO_MAFIO_PRIVATE_H_

/*AFIO Register Mapping*/
typedef struct
{
	/*Event Control Register*/
	volatile uint32 EVCR;
	/* Remapping and Debug I/O Configuration Register*/
	volatile uint32 MAPR;
	/*External Interrupt Register*/
	volatile uint32 EXTICR[4];
	/* Remapping and Debug I/O Configuration Register2*/
	volatile uint32 MAPR2;
}MAFIO_t;

/*Define AFIO Base Address with offest*/
#define AFIO ((volatile MAFIO_t *)0x40010000)

#endif /* MCAL_MAFIO_MAFIO_PRIVATE_H_ */
