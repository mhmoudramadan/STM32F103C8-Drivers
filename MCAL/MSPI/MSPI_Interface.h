/*
 * MSPI_Interface.h
 *
 *  Created on: May 16, 2022 5:59:57 AM 
 *  Topic-->SPI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSPI_MSPI_INTERFACE_H_
#define MCAL_MSPI_MSPI_INTERFACE_H_

typedef enum
{
	SPI1,
	SPI2,
	MAX_SPI_ONMC
}MSPI_Peripheral;

/*Options For Configuration
 * Mode -> 					1-Master *** 0-Slave
 * copy_CLK_POLARITY->  	1-High   *** 0-Low
 * copy_CLK_PHASHE->        1-Read First *** 0-Write First
 * Frame->                  1-LSB    *** 0-MSB
 * Frame Size ->            1-16-Bit *** 0-8-bit
 * SW_Sla_Mang->            1-Sw Mange*** 0-HW Mange
 * copy_TransmissonMode ->  1-Receive only *** 0-Full duplex(RC,TX)
 *  copy_Prescaler-->
 *   0 ->(f/2)
 *   1 ->(f/4)
 *   2 ->(f/8)
 *   3 ->(f/16)
 *   4 ->(f/32)
 *   5 ->(f/64)
 *   6 ->(f/128)
 *   7 ->(f/256) *******
 * copy_InterruptState-->   1-Enable ***** 0-Disable */

typedef struct
{
	uint8 copy_Mode;
	uint8 copy_CLK_POLARITY;
	uint8 copy_CLK_PHASHE;
	uint8 copy_FrameFormat;
	uint8 copy_FrameSize;
	uint8 copy_SW_SLAVE_Management;
	uint8 copy_TransmissonMode;
	uint8 copy_Prescaler;
	uint8 copy_InterruptState;
}MSPI_Configuraton;

#define SPI1_MOSI	PIN7
#define SPI1_MISO	PIN6
#define SPI1_CLK	PIN5
#define SPI1_NSS	PIN4

#define SPI2_MOSI	PIN15
#define SPI2_MISO	PIN14
#define SPI2_CLK	PIN13
#define SPI2_NSS	PIN12
/*Prototypes*/
void MSPI_VidInitPins(void);
ErrorState MSPI_ErrorState_Config_Channel(MSPI_Peripheral copy_Pre,MSPI_Configuraton *copy_Confg);
uint16 MSPI_uint16_Send_Receive_Sync(MSPI_Peripheral copy_Pre,uint16 copu_uint16Data);
void MSPI_Vid_Send_Receive_Async(MSPI_Peripheral copy_Pre,uint16 copu_uint16Data,void (*PtrToFun)(uint16));
#endif /* MCAL_MSPI_MSPI_INTERFACE_H_ */
