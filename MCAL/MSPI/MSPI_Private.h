/*
 * MSPI_Private.h
 *
 *  Created on: May 16, 2022 6:00:15 AM 
 *  Topic-->SPI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSPI_MSPI_PRIVATE_H_
#define MCAL_MSPI_MSPI_PRIVATE_H_

/*SPI Rgister Mapping*/
typedef struct
{
	volatile uint32 CR1;
	volatile uint32 CR2;
	volatile uint32 SR;
	volatile uint32 DR;
	volatile uint32 CRCPR;
	volatile uint32 RXCRCR;
	volatile uint32 TXCRCR;
	volatile uint32 I2SCFGR;
	volatile uint32 I2SSPR;
}MSPI_Reg;

/*Define Base Address*/
#define SPI1_BASE_ADDRESS  0x40013000
#define SPI2_BASE_ADDRESS  0x40003800
/*SPI Configuration*/
volatile MSPI_Reg *MSPI[2]=
{
		((volatile MSPI_Reg*)SPI1_BASE_ADDRESS),
		((volatile MSPI_Reg*)SPI2_BASE_ADDRESS),
};
/*Registe Bit Definitions*/
/*CR1*/
#define  CPHA       	0
#define  CPOL       	1
#define  MSTR       	2
#define  BR0        	3
#define  SPE        	6
#define  LSBFIRST   	7
#define  SS1        	8
#define  SSM        	9
#define  RXONLY     	10
#define  DFF        	11
#define  CRCNEXT	  	12
#define  CRCEN	  		13
#define  BIDIOE     	14
#define  BIDIMODE   	15
/*CR2*/
#define  RXDMEAN		0
#define  TXDMEAN		1
#define  SSOE			2
#define  ERRIE			5
#define  RXNEIE			6
#define  TXEIE			7
/*SR*/
#define  RXNE       	0
#define  TXE        	1
#define  CHSIDE     	2
#define  UDR        	3
#define  CRCERR     	4
#define  MODF       	5
#define  OVR        	6
#define  BSY        	7
#endif /* MCAL_MSPI_MSPI_PRIVATE_H_ */
