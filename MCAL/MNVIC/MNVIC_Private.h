/*
 * MNVIC_Private.h
 *
 *  Created on: May 11, 2022 5:49:14 AM NVIC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_

/*NVIC Register Mapping*/
typedef struct
{
	/*Set enable Register*/
	volatile uint32 ISER[3];
	volatile uint32 RESERVED0[29];
	/*Clear Enable register*/
	volatile uint32 ICER[3];
	volatile uint32 RESERVED1[29];
	/*Set pending register*/
	volatile uint32 ISPR[3];
	volatile uint32 RESERVED2[29];
	/*Clear Pending register*/
	volatile uint32 ICPR[3];
	volatile uint32 RESERVED3[29];
	/*Active interrupt bit register*/
	volatile uint32 IABR[3];
	volatile uint32 RESERVED4[61];
	/*priority register*/
	volatile uint8 IPR[60];
}NVIC_t;

/*register */
#define NVIC_BASEADDRESS   0xE000E100
#define NVIC      ((volatile NVIC_t *)NVIC_BASEADDRESS)
#define NVIC_STIR *((volatile uint32*)NVIC_BASEADDRESS+0xE00)
#define SCB_AIRCR *((volatile uint32*)0xE000ED0C)

/*Group Priority options*/
#define NVIC_GROUP_0    0b111
#define NVIC_GROUP_2    0b110
#define NVIC_GROUP_4    0b101
#define NVIC_GROUP_8    0b100
#define NVIC_GROUP_16   0b011

#define GROUPING_BIT    8
#define VECTKEY  	0x05FA0000

#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
