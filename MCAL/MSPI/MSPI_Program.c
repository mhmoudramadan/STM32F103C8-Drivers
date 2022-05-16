/*
 * MSPI_Program.c
 *
 *  Created on: May 16, 2022 6:00:39 AM 
 *  Topic-->SPI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include"../../MCAL/MGPIO/MGPIO_Interface.h"
#include"MSPI_Private.h"
#include"MSPI_Config.h"
#include"MSPI_Interface.h"

void (*CALLBACK[SPI_MAC_CHANNEL_ON_MC])(uint16);
void MSPI_VidInitPins(void)
{
#if SPI1_MODE == SPI_MASTER_MODE
/*Set MISO as Input
 * MOSI / CLK /NSS as output*/
	MGPIO_ErrorStateSetPinMode(PORTA,SPI1_MISO,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_ErrorStateSetPinMode(PORTA,SPI1_MOSI,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);
	MGPIO_ErrorStateSetPinMode(PORTA,SPI1_CLK,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);
	MGPIO_ErrorStateSetPinMode(PORTA,SPI1_NSS,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);

#elif SPI1_MODE == SPI_SLAVE_MODE
	/*Set MISO as output
	 * MOSI / CLK /NSS as intput*/
	MGPIO_ErrorStateSetPinMode(PORTA,SPI1_MISO,MGPIO_OUTPUT_50MHZ_PULL_UP_DOWN);
	MGPIO_MGPIO_ErrorStateSetPinMode(PORTA,SPI1_MOSI,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_MGPIO_ErrorStateSetPinMode(PORTA,SPI1_CLK,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_MGPIO_ErrorStateSetPinMode(PORTA,SPI1_NSS,MGPIO_INPUT_PULL_UP_DOWN_MODE);
#else
#error"confg Not Valid"
#endif
#if SPI2_MODE == SPI_MASTER_MODE
/*Set MISO as Input
 * MOSI / CLK /NSS as output*/
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_MISO,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_MOSI,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_CLK,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_NSS,MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN);

#elif SPI2_MODE == SPI_SLAVE_MODE
	/*Set MISO as output
	 * MOSI / CLK /NSS as intput*/
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_MISO,MGPIO_OUTPUT_50MHZ_PULL_UP_DOWN);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_MOSI,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_CLK,MGPIO_INPUT_FLOATING_MODE);
	MGPIO_ErrorStateSetPinMode(PORTB,SPI2_NSS,MGPIO_INPUT_PULL_UP_DOWN_MODE);
#else
#error"confg Not Valid"
#endif
}
ErrorState MSPI_ErrorState_Config_Channel(MSPI_Peripheral copy_Pre,MSPI_Configuraton *copy_Confg)
{
	ErrorState Loc_error=OK;
	/*Reset Register*/
	MSPI[copy_Pre]->CR1=0x00000000;
	MSPI[copy_Pre]->CR2=0x00000000;
	switch(copy_Confg->copy_Mode)
	{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,MSTR);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,MSTR);
			break;
		}
		default:
		Loc_error=NOK;
		break;
		}
	switch(copy_Confg->copy_CLK_POLARITY)
	{
		case 1:
		{
		SET_BIT(MSPI[copy_Pre]->CR1,CPOL);
			break;
		}
		case 0:
		{
		CLR_BIT(MSPI[copy_Pre]->CR1,CPOL);
		break;
		}
	default:
		Loc_error=NOK;
		break;
	}
	switch(copy_Confg->copy_CLK_PHASHE)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,CPHA);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,CPHA);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	switch(copy_Confg->copy_FrameFormat)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,LSBFIRST);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,LSBFIRST);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	switch(copy_Confg->copy_FrameSize)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,DFF);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,DFF);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	switch(copy_Confg->copy_SW_SLAVE_Management)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,SSM);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,SSM);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	switch(copy_Confg->copy_TransmissonMode)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,RXONLY);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,RXONLY);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	switch(copy_Confg->copy_InterruptState)
		{
		case 1:
		{
			SET_BIT(MSPI[copy_Pre]->CR1,RXNEIE);
			break;
		}
		case 0:
		{
			CLR_BIT(MSPI[copy_Pre]->CR1,RXNEIE);
			break;
		}
		default:
			Loc_error=NOK;
			break;
		}
	if(copy_Confg->copy_Prescaler<8)
	{
		MSPI[copy_Pre]->CR1 |=copy_Confg->copy_Prescaler<<BR0;
	}
	else
	{
		Loc_error=NOK;
	}
	return Loc_error;
}
uint16 MSPI_uint16_Send_Receive_Sync(MSPI_Peripheral copy_Pre,uint16 copu_uint16Data)
{
	/*Send Data */
	MSPI[copy_Pre]->DR=copu_uint16Data;
	/*Wait until operation Finish*/
	while(GET_BIT(MSPI[copy_Pre]->SR,BSY)==1);
	uint16 Loc_data=MSPI[copy_Pre]->DR;
	return Loc_data;
}

void MSPI_Vid_Send_Receive_Async(MSPI_Peripheral copy_Pre,uint16 copu_uint16Data,void (*PtrToFun)(uint16))
{
	CALLBACK[copy_Pre]=PtrToFun;
	/*Send Data*/
	MSPI[copy_Pre]->DR=copu_uint16Data;
}
/*ISR*/
void MSPI1_VidIRQ_Handler(void)
{
	/*Clear Flag*/
	CLR_BIT(MSPI[0]->SR,RXNE);
	/*Receive Data*/
	uint16 Loc_Data=MSPI[0]->DR;
	CALLBACK[0](Loc_Data);
}
void MSPI2_VidIRQ_Handler(void)
{
	/*Clear Flag*/
	CLR_BIT(MSPI[1]->SR,RXNE);
	/*Receive Data*/
	uint16 Loc_Data=MSPI[1]->DR;
	CALLBACK[1](Loc_Data);
}
