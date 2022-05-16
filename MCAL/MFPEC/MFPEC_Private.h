/*
 * MFPEC_Private.h
 *
 *  Created on: May 16, 2022 1:13:19 AM 
 *  Topic-->FPEC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MFPEC_MFPEC_PRIVATE_H_
#define MCAL_MFPEC_MFPEC_PRIVATE_H_

/*FPEC Register Mapping*/
typedef struct
{
	volatile uint32 FLASH_ACR;
	volatile uint32 FLASH_KEYR;
	volatile uint32 FLASH_OPTKEYR;
	volatile uint32 FLASH_SR;
	volatile uint32 FLASH_CR;
	volatile uint32 FLASH_AR;
	volatile uint32 FLASH_OBR;
	volatile uint32 FLASH_WRPR;
}MFPEC_t;

/*FPEC Base Address*/
#define FPEC ((volatile MFPEC_t *)0x40022000)
/*Register Bits Definintions*/
/*ACR*/
#define LATENCY			0
#define HLFCYA			3
#define PRFTBE			4
#define PRFTBS			5
/*SR*/
#define BSY             0
#define PGERR           2
#define WRPRTERR        4
#define EOP             5
/*CR*/
#define PG              0
#define PER             1
#define MER             2
#define OPTPG           4
#define OPTER           5
#define STRT            6
#define LOCK            7
#define OPTWRE          9
#define ERRIE           10
#define EOPIE           12

#define MFPEC_KEY1		0x45670123
#define MFPEC_KEY2		0xCDEF89AB
#define RDPRT_KEY		0x00A5
#define PAGE_SIZE		1024
#define FLASH_FIRST_ADDRESS 	0x08000000
#endif /* MCAL_MFPEC_MFPEC_PRIVATE_H_ */
