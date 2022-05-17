/*
 * MUART_Interface.h
 *
 *  Created on: May 14, 2022 1:06:07 AM 
 *  Topic-->UART_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSUART_MSUART_INTERFACE_H_
#define MCAL_MSUART_MSUART_INTERFACE_H_

/*UART Channel*/
typedef enum
{
	UART1,
	UART2,
	UART3,
	UART4,
	UART5
}MUART_Channel;
/*ProtoTypes*/
void MUART_VidInit(MUART_Channel copy_Channel);
void MUART_VidTransmit_Data_Synchronous(MUART_Channel copy_Channel , uint8 *Puint8_data);
uint8 MUART_VidReceive_Data_Synchronous(MUART_Channel copy_Channel , uint8 *Puint8_data);
uint8 MUART_VidReceive_Byte_Synchronous(MUART_Channel copy_Channel);
void MUART_VidReceive_Data_Asynchronous(MUART_Channel copy_Channel ,void (*PtrToFun)(uint8));

#endif /* MCAL_MSUART_MSUART_INTERFACE_H_ */
