/*
 * MUART_Config.h
 *
 *  Created on: May 14, 2022 1:06:18 AM 
 *  Topic-->UART_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSUART_MSUART_CONFIG_H_
#define MCAL_MSUART_MSUART_CONFIG_H_

/*UART Configuration */
typedef enum
{
	UART_ENABLE,
	UART_DISABLE
}MUART_State;

typedef enum
{
	UART_8_BIT_DATA,
	UART_9_BIT_DATA
}MUART_Data_Length;

typedef enum
{
	EVEN_PARITY_CHECK,
	ODD_PARITY_CHECK,
	NO_PARITY_CHECK
}MUART_ParityCheck;

typedef enum
{
	ENABLE_RECEIVER,
	ENABLE_TRANSMITTER,
	ENABLE_REC_TR
}MUART_TR_Control;

/*UART Configuration Table to hold All configuration*/
typedef struct
{
	MUART_State Module_Enable;
	MUART_Data_Length Data_Length;
	MUART_ParityCheck Check_Mode;
	MUART_TR_Control Control_TR;
	uint32 copy_uint32BaudRate;
	uint32 copy_uint32Bus_Freq;
}MUART_Configuration;


#define APB1_CLOCK		8000000
#define APB2_CLOCK		8000000
#define ENABLE			1
#define DISABLE			0

/*Baudrate Configuration*/
/* 1-MHz*/
#define UART_BAUDRATE_1200_CLK_1M       0X0341
#define UART_BAUDRATE_2400_CLK_1M       0X01A0
#define UART_BAUDRATE_4800_CLK_1M       0X00D0
#define UART_BAUDRATE_9600_CLK_1M       0X0068
#define UART_BAUDRATE_19200_CLK_1M      0X0034
/* 8-MHz*/
#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
#define UART_BAUDRATE_2400_CLK_8M       0X0D05
#define UART_BAUDRATE_4800_CLK_8M       0X0683
#define UART_BAUDRATE_9600_CLK_8M       0X0341
#define UART_BAUDRATE_19200_CLK_8M      0X01A1

#define MUART_BAUDRATE                   UART_BAUDRATE_9600_CLK_1M
#endif /* MCAL_MSUART_MSUART_CONFIG_H_ */
