/*
 * MUART_Program.c
 *
 *  Created on: May 14, 2022 1:06:41 AM 
 *  Topic-->UART_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include <MCAL/MSUART/MSUART_Config.h>
#include <MCAL/MSUART/MSUART_Interface.h>
#include <MCAL/MSUART/MSUART_Private.h>
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"


void (*CALLBACK[5])(uint8);
void MUART_VidInit(MUART_Channel copy_Channel)
{
	MUART_CHANNEL[copy_Channel]->CR1=CLEAR_REGITSER;
	MUART_CHANNEL[copy_Channel]->CR2=CLEAR_REGITSER;
	MUART_CHANNEL[copy_Channel]->CR3=CLEAR_REGITSER;
	MUART_CHANNEL[copy_Channel]->SR=CLEAR_REGITSER;
	/*Configuration of Control Register */
	MUART_CHANNEL[copy_Channel]->CR3 |=((DISABLE<<IREN) |(DISABLE<<IRLP) |(DISABLE<<HDSEL)
			|(DISABLE<<NACK) | (DISABLE<<SCEN) |(DISABLE<<DMAR) |(DISABLE<<DMAT) |(DISABLE<<RTSE));
	MUART_CHANNEL[copy_Channel]->CR2 |= ((DISABLE<<ADD) | (DISABLE<<LBDL) |(DISABLE<<LBDIE)
			|(DISABLE<<LBCL) |(ENABLE<<CPHA) |(DISABLE<<CPOL) |(DISABLE<<CLKEN) |(DISABLE<<STOP)|(DISABLE<<LINEN));
	MUART_CHANNEL[copy_Channel]->CR1 |=((DISABLE<<SBK)|(DISABLE<<RWU)|(DISABLE<<RE)|(DISABLE<<PS)|(DISABLE<<TE)
			|(DISABLE<<PCE)|(DISABLE<<M)|(DISABLE<<WAKE));
	/*Set BAUDRATE*/
	MUART_CHANNEL[copy_Channel]->BRR=MUART_BAUDRATE;
	/*Enable peripheral */
	MUART_CHANNEL[copy_Channel]->CR1|=(ENABLE<<UE);
}
void MUART_VidTransmit_Data_Synchronous(MUART_Channel copy_Channel , uint8 *Puint8_data)
{
	uint8 Loc_counter=0;
	while(Puint8_data[Loc_counter]!='\0')
	{
		/*Get Data into DR register*/
		MUART_CHANNEL[copy_Channel]->DR=Puint8_data[Loc_counter];
		/*Wait to transmit finished*/
		while(GET_BIT(MUART_CHANNEL[copy_Channel]->SR,TC)==0);
		Loc_counter++;
	}
}
uint8 MUART_VidReceive_Data_Synchronous(MUART_Channel copy_Channel , uint8 *Puint8_data)
{
	uint8 Loc_Data_State=1;
	if(GET_BIT(MUART_CHANNEL[copy_Channel]->SR,RXNE)==1)
	{
		*Puint8_data=(ONE_BYTE)&(MUART_CHANNEL[copy_Channel]->DR);
	}
	else
	{
		Loc_Data_State=0;
	}
	return Loc_Data_State;
}
uint8 MUART_VidReceive_Byte_Synchronous(MUART_Channel copy_Channel)
{
	uint8 Loc_Data;
	/*wait until check of Receive finish*/
	while(GET_BIT(MUART_CHANNEL[copy_Channel]->SR,RXNE)==0);
	Loc_Data= (ONE_BYTE)&(MUART_CHANNEL[copy_Channel]->DR);
	return Loc_Data;
}
void MUART_VidReceive_Data_Asynchronous(MUART_Channel copy_Channel ,void (*PtrToFun)(uint8))
{
	CALLBACK[copy_Channel]=PtrToFun;
	/*Enable Receive interrupt */
	SET_BIT(MUART_CHANNEL[copy_Channel]->CR1,RXNEIE);
}
/*ISR*/
void MUART_1_IRQ_Handler(void)
{
	/*Check for interrupt */
	if(GET_BIT(MUART_CHANNEL[UART1]->SR,RXNE))
	{
		/*Clear Interrupt Flag*/
		CLR_BIT(MUART_CHANNEL[UART1]->SR,RXNE);
		CALLBACK[0](MUART_CHANNEL[UART1]->DR & ONE_BYTE);
	}
}
void MUART_2_IRQ_Handler(void)
{
	/*Check for interrupt */
		if(GET_BIT(MUART_CHANNEL[UART2]->SR,RXNE))
		{
			/*Clear Interrupt Flag*/
			CLR_BIT(MUART_CHANNEL[UART2]->SR,RXNE);
			CALLBACK[1](MUART_CHANNEL[UART2]->DR & ONE_BYTE);
		}

}
void MUART_3_IRQ_Handler(void)
{
	/*Check for interrupt */
		if(GET_BIT(MUART_CHANNEL[UART3]->SR,RXNE))
		{
			/*Clear Interrupt Flag*/
			CLR_BIT(MUART_CHANNEL[UART3]->SR,RXNE);
			CALLBACK[2](MUART_CHANNEL[UART3]->DR & ONE_BYTE);
		}
}
void MUART_4_IRQ_Handler(void)
{
	/*Check for interrupt */
		if(GET_BIT(MUART_CHANNEL[UART4]->SR,RXNE))
		{
			/*Clear Interrupt Flag*/
			CLR_BIT(MUART_CHANNEL[UART4]->SR,RXNE);
			CALLBACK[3](MUART_CHANNEL[UART4]->DR & ONE_BYTE);
		}
}
void MUART_5_IRQ_Handler(void)
{
	/*Check for interrupt */
		if(GET_BIT(MUART_CHANNEL[UART5]->SR,RXNE))
		{
			/*Clear Interrupt Flag*/
			CLR_BIT(MUART_CHANNEL[UART5]->SR,RXNE);
			CALLBACK[4](MUART_CHANNEL[UART5]->DR & ONE_BYTE);
		}
}
