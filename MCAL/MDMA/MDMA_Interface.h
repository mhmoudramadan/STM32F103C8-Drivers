/*
 * MDMA_Interface.h
 *
 *  Created on: May 13, 2022 12:16:43 AM 
 *  Topic-->DMA_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MDMA_MDMA_INTERFACE_H_
#define MCAL_MDMA_MDMA_INTERFACE_H_

#define DMA_TE		0
#define DMA_TC		1
#define DMA_NT		2

/*Channels*/
typedef enum
{
	DMA_CH1,
	DMA_CH2,
	DMA_CH3,
	DMA_CH4,
	DMA_CH5,
	DMA_CH6,
	DMA_CH7
}MDMA_Channels;
/*DMA Priority*/
typedef enum
{
	LOW_PRIORITY,
	MEDIUM_PRIORITY,
	HIGH_PRIORITY,
	VERYHIGH_PRIORITY
}MDMA_Priority_Levels;

/*DMA transfer Modes*/
typedef enum
{
	MEMORY_TO_MEMORY,
	PREIPHERAL_TO_MEMORY,
	MEMORY_TO_PREIPHERAL,
	PREIPHERAL_TO_PREIPHERAL
}MDMA_Transfer_Modes;

/*DMA Data Size
 * 1-Byte
 * 2-Half word
 * 3-Word*/
typedef enum
{
	DATA_8_Bit,
	DATA_16_BIT,
	DATA_32_BIT
}MDMA_DataSize;

/*DMA States*/
typedef enum
{
	DMA_DISABLE,
	DAM_ENABLE
}MDMA_States;

/*struct to hold DMA Channel Configuration*/
typedef struct
{
	/*Priority Level*/
	MDMA_Priority_Levels P_Level;
	/*Transfer Modes*/
	MDMA_Transfer_Modes Transfer_Mode;
	/*Data size of Memory Element consider distantion size
	 * MEM_TO_PER */
	MDMA_DataSize Memory_Size;
	/*Data size of Peripheral element consider source size *
	 * MEM_TO_PER*/
	 MDMA_DataSize Peripheral_Size;
	 /*Option for memory Increment EN/Dis*/
	 MDMA_States Memory_Increment;
	 /*Option for peripheral Increment EN/Dis*/
	 MDMA_States Peripheral_Increment;
	 /*En/Dis Circular mode*/
	 MDMA_States Circular_Mode;
	 /*En/Dis Transfer Complete interrupt*/
	 MDMA_States Transfer_Interrupt;
	 /*En/Dis HALF Transfer Complete interrupt*/
	 MDMA_States HalfTransfer_Interrupt;
	 /*En/Dis Error Transfer  interrupt*/
	 MDMA_States Error_Transfer_Interrupt;
}MDMA_Configuration;

/*DMA Transfer Parameters*/
typedef struct
{
	MDMA_Transfer_Modes Transfer_Mode;
	/*Source*/
	uint32 *Puint32SourceAddress;
	/*Distenation*/
	uint32 *Puint32DistenationAddress;
	/*Block Size*/
	uint16 copy_uint16BlockSize;
}MDMA_TransferData;

/*DMA Prototypes*/
void MDMA_VidSet_ConfigChannel(MDMA_Channels copy_channel,MDMA_Configuration *copy_Configuration);
void MDMA_VidTransfer(MDMA_Channels copy_channel,MDMA_TransferData *copy_trnsfer);
uint8 MDMA_uint8Get_Status(MDMA_Channels copy_Channel);
void MDMA_VidSetCALLBACK(MDMA_Channels copy_Channel,void(*PtrToFun)(void));
#endif /* MCAL_MDMA_MDMA_INTERFACE_H_ */
