/*
 * MDMA_Program.c
 *
 *  Created on: May 13, 2022 12:17:13 AM 
 *  Topic-->DMA_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MDMA_Private.h"
#include"MDMA_Interface.h"

/*Call Back*/
void (*CALLBACK[7])(void);
void MDMA_VidSet_ConfigChannel(MDMA_Channels copy_channel,MDMA_Configuration *copy_Configuration)
{
	/*disable channel and reset Register at first*/
	DMA->Channel[copy_channel].CCR=0;
	/*Set priority*/
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->P_Level<<DMA_PL0);
	switch(copy_Configuration->Transfer_Mode)
	{
	case MEMORY_TO_MEMORY:
	{
		/*Enable Memory to memory*/
		SET_BIT(DMA->Channel[copy_channel].CCR,DMA_MEM2MEM);
		/*Make peripheral register source*/
		CLR_BIT(DMA->Channel[copy_channel].CCR,DMA_DIR);
		break;
	}
	case PREIPHERAL_TO_MEMORY:
	{
		/*Preipheral register as source*/
		CLR_BIT(DMA->Channel[copy_channel].CCR,DMA_DIR);
		break;
	}
	case MEMORY_TO_PREIPHERAL:
	{
		/*Memory As Source*/
		SET_BIT(DMA->Channel[copy_channel].CCR,DMA_DIR);
		break;
	}
	case PREIPHERAL_TO_PREIPHERAL:
	{
		/*Preipheral register as source*/
		CLR_BIT(DMA->Channel[copy_channel].CCR,DMA_DIR);
		break;
	}
	default:
		break;
	}
	/*Memory Element Size */
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->Memory_Size<<DMA_MSIZE0);
	/*Preipheral Element Size */
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->Peripheral_Size<<DMA_PSIZE0);
	/*Memory address Increment */
	DMA->Channel[copy_channel].CCR |=(copy_Configuration->Memory_Increment<<DMA_MINC);
	/*Peripheral address Increment */
	DMA->Channel[copy_channel].CCR |=(copy_Configuration->Peripheral_Increment<<DMA_PINC);
	/*Circular mode*/
	DMA->Channel[copy_channel].CCR |=(copy_Configuration->Circular_Mode<<DMA_CIRC);
	/* 3 Interrupt handler*/
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->Transfer_Interrupt<<DMA_TCIE);
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->HalfTransfer_Interrupt<<DMA_HTIE);
	DMA->Channel[copy_channel].CCR |= (copy_Configuration->Error_Transfer_Interrupt<<DMA_TEIE);

}
void MDMA_VidTransfer(MDMA_Channels copy_channel,MDMA_TransferData *copy_trnsfer)
{
	/*Disable channel*/
	CLR_BIT(DMA->Channel[copy_channel].CCR,DMA_EN);
	/*Mangement of source and distination*/
	if(copy_trnsfer->Transfer_Mode== MEMORY_TO_PREIPHERAL)
	{
		/*Set memory as source*/
		DMA->Channel[copy_channel].CMAR=copy_trnsfer->Puint32SourceAddress;
		/*Set Peripheral as distination*/
		DMA->Channel[copy_channel].CPAR=copy_trnsfer->Puint32DistenationAddress;
	}
	else
	{
		/*Set memory as distination*/
		DMA->Channel[copy_channel].CMAR=copy_trnsfer->Puint32DistenationAddress;
		/*Set Peripheral as source*/
		DMA->Channel[copy_channel].CPAR=copy_trnsfer->Puint32SourceAddress;
	}
	/*Block Size No Of data to transfer 0:15*/
	DMA->Channel[copy_channel].CNDTR=copy_trnsfer->copy_uint16BlockSize;
	/*Enable Channel*/
	SET_BIT(DMA->Channel[copy_channel].CCR , DMA_EN);
}
uint8 MDMA_uint8Get_Status(MDMA_Channels copy_Channel)
{
	/*Local Variable */
	uint8 Loc_uint8TC,Loc_uint8TE,Loc_State;
	/*Tranfer Complete Flag*/
	Loc_uint8TC=DMA_TCIF1+(copy_Channel*4);
	/*Tranfer Error Flag*/
	Loc_uint8TE=DMA_TEIF1+(copy_Channel*4);
	if(GET_BIT(DMA->ISR,Loc_uint8TC))
	{
		Loc_State=DMA_TC;
	}
	else if(GET_BIT(DMA->ISR,Loc_uint8TE))
	{
		Loc_State=DMA_TE;
	}
	else
	{
		Loc_State=DMA_NT;
	}
	return Loc_State;
}
void MDMA_VidSetCALLBACK(MDMA_Channels copy_Channel,void(*PtrToFun)(void))
{
	CALLBACK[copy_Channel]=PtrToFun;
}

/*Channels IRQ*/
void MDMA1_Channel1_IRQ(void)
{
	CALLBACK[0]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF1);
}
void MDMA1_Channel2_IRQ(void)
{
	CALLBACK[1]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF2);
}
void MDMA1_Channel3_IRQ(void)
{
	CALLBACK[2]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF3);
}
void MDMA1_Channel4_IRQ(void)
{
	CALLBACK[3]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF4);
}
void MDMA1_Channel5_IRQ(void)
{
	CALLBACK[4]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF5);
}
void MDMA1_Channel6_IRQ(void)
{
	CALLBACK[5]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF6);
}
void MDMA1_Channel7_IRQ(void)
{
	CALLBACK[6]();
	/*Clear Channel Flag*/
	DMA->IFCR=(15<<DMA_GIF7);
}
