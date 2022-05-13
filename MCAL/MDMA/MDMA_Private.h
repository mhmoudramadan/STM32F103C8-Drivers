/*
 * MDMA_Private.h
 *
 *  Created on: May 13, 2022 12:17:46 AM 
 *  Topic-->DMA_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MDMA_MDMA_PRIVATE_H_
#define MCAL_MDMA_MDMA_PRIVATE_H_

/*DMA channel Register Mapping*/
typedef struct
{
	volatile uint32 CCR;
	volatile uint32 CNDTR;
	volatile uint32 CPAR;
	volatile uint32 CMAR;
	volatile uint32 RES;
}MDMA_Channel_Register;

/*DMA Register Mapping*/
typedef struct
{
	volatile uint32 ISR;
	volatile uint32 IFCR;
	MDMA_Channel_Register Channel[7];
}MDMA_Register;

/*DMA Base address*/
#define DMA ((volatile MDMA_Register *)0x40020000)

/*DMA Register Bit Definitions*/
/*ISR */
#define DMA_GIF1		0
#define DMA_TCIF1		1
#define DMA_HTIF1		2
#define DMA_TEIF1		3

#define DMA_GIF2		4
#define DMA_TCIF2		5
#define DMA_HTIF2		6
#define DMA_TEIF2		7

#define DMA_GIF3		8
#define DMA_TCIF3		9
#define DMA_HTIF3		10
#define DMA_TEIF3		11

#define DMA_GIF4		12
#define DMA_TCIF4		13
#define DMA_HTIF4		14
#define DMA_TEIF4		15

#define DMA_GIF5		16
#define DMA_TCIF5		17
#define DMA_HTIF5		18
#define DMA_TEIF5		19

#define DMA_GIF6		20
#define DMA_TCIF6		21
#define DMA_HTIF6		22
#define DMA_TEIF6		23

#define DMA_GIF7		24
#define DMA_TCIF7		25
#define DMA_HTIF7		26
#define DMA_TEIF7		27

/*DMA Channel register bit definition*/
	/*CRC*/
#define DMA_EN 			0
#define DMA_TCIE		1
#define DMA_HTIE		2
#define DMA_TEIE		3
#define DMA_DIR			4
#define DMA_CIRC		5
#define DMA_PINC		6
#define DMA_MINC		7
#define DMA_PSIZE0		8
#define DMA_PSIZE1		9
#define DMA_MSIZE0		10
#define DMA_MSIZE1		11
#define DMA_PL0			12
#define DMA_PL1			13
#define DMA_MEM2MEM		14

#endif /* MCAL_MDMA_MDMA_PRIVATE_H_ */
