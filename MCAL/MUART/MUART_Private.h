/*
 * MUART_Private.h
 *
 *  Created on: May 14, 2022 1:06:28 AM 
 *  Topic-->UART_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

/*Uart Register offest Mapping*/
typedef struct
{
	/*Status Register*/
	volatile uint32 SR;
	/*Data Register*/
	volatile uint32 DR;
	/*BaudRate Register*/
	volatile uint32 BRR;
	/*Control 1 Register*/
	volatile uint32 CR1;
	/*Control 2 Register*/
	volatile uint32 CR2;
	/*Control 3 Register*/
	volatile uint32 CR3;
	/*Guard time and prescaler register*/
	volatile uint32 GTPR;
}UART_t;
/*UART Base Address*/
#define UART_1_BASE_ADDRESS	 	0x40013800
#define UART_2_BASE_ADDRESS	 	0x40004400
#define UART_3_BASE_ADDRESS 	0x40004800
#define UART_4_BASE_ADDRESS 	0x40004C00
#define UART_5_BASE_ADDRESS 	0x40005000

#define CLEAR_REGITSER          0x00000000
#define ONE_BYTE				0xFF

#define UART_MAX_CHANNEL  5
static volatile UART_t * const MUART_CHANNEL[UART_MAX_CHANNEL]=

{		((volatile UART_t *const)(UART_1_BASE_ADDRESS)),
		((volatile UART_t *const)(UART_2_BASE_ADDRESS)),
		((volatile UART_t *const)(UART_3_BASE_ADDRESS)),
		((volatile UART_t *const)(UART_4_BASE_ADDRESS)),
		((volatile UART_t *const)(UART_5_BASE_ADDRESS)) };
/*Register Bits definitions */
/*SR*/
#define PE  	0
#define FE		1
#define NE		2
#define ORE		3
#define IDLE	4
#define RXNE	5
#define TC		6
#define TXE		7
#define LBD		8
#define CTS		9

/*CR1*/
#define SBK			0
#define RWU			1
#define RE			2
#define TE			3
#define IDLEIE		4
#define RXNEIE		5
#define TCIE		6
#define TXEIE		7
#define PEIE		8
#define PS			9
#define PCE			10
#define WAKE		11
#define M			12
#define UE			13

/*CR2*/
#define ADD			0
#define LBDL		5
#define LBDIE		6
#define LBCL		8
#define CPHA		9
#define CPOL		10
#define CLKEN		11
#define STOP		12
#define LINEN		14

/*CR3*/
#define EIE			0
#define IREN		1
#define IRLP		2
#define HDSEL		3
#define NACK		4
#define SCEN		5
#define DMAR		6
#define DMAT		7
#define RTSE		8
#define CTSE		9
#define CTSIE		10

/*GTPR*/
#define PSC			0
#define GT			1
#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
