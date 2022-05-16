/*
 * MADC_Program.c
 *
 *  Created on: May 16, 2022 3:21:00 AM 
 *  Topic-->ADC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MADC_Private.h"
#include"MADC_Config.h"
#include"MADC_Interface.h"

void (*CALLBACK[3])(void);
void MADC_VidInit(void)
{
				/*Check for peripheral enable by looping */
	for(uint8 Loc_Counter=ADC1;Loc_Counter<NUM_OF_ADC_PERIPHERALON_MC;Loc_Counter++)
	{
		if(Static_ADC_Configuration[Loc_Counter].ADC_State==ENABLE_ADC)
		{
			/*Reset Registers*/
			MADC_Channels[Loc_Counter]->CR1=0x00000000;
			MADC_Channels[Loc_Counter]->CR2=0x00000000;
			MADC_Channels[Loc_Counter]->SMPR1=0x00000000;;
			MADC_Channels[Loc_Counter]->SMPR2=0x00000000;
			MADC_Channels[Loc_Counter]->SQR1=0x00000000;
			MADC_Channels[Loc_Counter]->SQR2=0x00000000;
			MADC_Channels[Loc_Counter]->SQR3=0x00000000;
			/*Set Data alignemnet*/
			MADC_Channels[Loc_Counter]->CR2|=(Static_ADC_Configuration[Loc_Counter].Data_Align<<ALIGN);
			/*Set calibration*/
			MADC_Channels[Loc_Counter]->CR2 |=(Static_ADC_Configuration[Loc_Counter].Calibration_State<<CAL);
			/*Enable ADC*/
			SET_BIT(MADC_Channels[Loc_Counter]->CR2,ADON);
		}
	}
}
void MADC_VidSet_ConversionMode(MADC_Peripheral copy_PreNum,MADC_Conversion copy_Mode,uint8 copy_uint8ConversionNum)
{
	switch(copy_Mode)
	{
	case ADC_SINGLE_CONVERSION:
	{
		CLR_BIT(MADC_Channels[copy_PreNum]->CR2,CONT);
		break;
	}
	case ADC_CONTINOUS_CONVERSION:
	{
		SET_BIT(MADC_Channels[copy_PreNum]->CR2,CONT);
		break;
	}
	case ADC_SCAN_SINGLE_CONVERSION:
	{
		/*First Set Single Conversion*/
		CLR_BIT(MADC_Channels[copy_PreNum]->CR2,CONT);
	    /*Enable Scan Mode*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR1,SCAN);
		/*Enable DMA Only For ADC1&3*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR2,DMA);
		break;
	}
	case ADC_SCAN_CONTINOUS_CONVERSION:
	{
		/*First Set Continous Conversion*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR2,CONT);
		/*Enable Scan Mode*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR1,SCAN);
		/*Enable DMA Only For ADC1&3*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR2,DMA);
		break;
	}
	case ADC_DIS_COUNTINOUS_CONVERSION:
	{
		/*Enable Scan Discontinous Mode*/
		SET_BIT(MADC_Channels[copy_PreNum]->CR1,DISCEN);
		/*Set Channel count from 0_To_8 -->Channel_1_TO_8*/
		MADC_Channels[copy_PreNum]->CR1 |= (copy_uint8ConversionNum<<DISCNUM);
		break;
	}
	default:
		break;
	}
}
void MADC_VidSet_RegularTime(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_ORDER copy_ChOrder)
{
	if(copy_Ch<=6)
	{
		MADC_Channels[copy_PreNum]->SQR3 |=(copy_Ch<<copy_ChOrder);
	}
	else if(copy_Ch<=12)
	{
		MADC_Channels[copy_PreNum]->SQR2 |=(copy_Ch<<copy_ChOrder);
	}
	else if(copy_Ch<=16)
	{
		MADC_Channels[copy_PreNum]->SQR1 |=(copy_Ch<<copy_ChOrder);
	}
	else
	{
		/*Do Nothing*/
	}
}
void MADC_VidSet_SampleTime(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_SampleTime copy_SampleTime)
{
	if(copy_Ch<=9)
	{
		MADC_Channels[copy_PreNum]->SMPR2 |=copy_SampleTime << (copy_Ch*3);
		/*(3) is the offest*/
	}
	else if(copy_Ch<=17)
	{
		MADC_Channels[copy_PreNum]->SMPR1 |=copy_SampleTime << (copy_Ch*3);
	}
	else
	{
		/*Do Nothing*/
	}
}
void MADC_uint16Read_ResultBlock(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_Length copy_ChLength,uint16 *Puint16Result)
{
	/*Clear Register*/
	MADC_Channels[copy_PreNum]->SQR3=0x00000000;
	/*Set Channel Length Sequence*/
	MADC_Channels[copy_PreNum]->SQR3 |=copy_ChLength<<L0;
	MADC_Channels[copy_PreNum]->SQR3 |=copy_Ch<<ADC_1_ORDER;
	/*Start conversion*/
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,ADON);
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,SWSTART);
	/*Wait until conversion end*/
	while(GET_BIT(MADC_Channels[copy_PreNum]->SR,EOC)==0);
	*Puint16Result=((MADC_Channels[copy_PreNum]->DR)&0x0FFF);
	/*Right align --> 0x0fff*/
	/*Clear Flags*/
	CLR_BIT(MADC_Channels[copy_PreNum]->SR,EOC);
	CLR_BIT(MADC_Channels[copy_PreNum]->SR,STRT);

}
void MADC_uint16Read_ResultNonBlock(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_Length copy_ChLength,uint16 *Puint16Result)
{
	/*Clear Register*/
	MADC_Channels[copy_PreNum]->SQR3=0x00000000;
	/*Set Channel Length Sequence*/
	MADC_Channels[copy_PreNum]->SQR3 |=copy_ChLength<<L0;
	MADC_Channels[copy_PreNum]->SQR3 |=copy_Ch<<ADC_1_ORDER;
	/*Start conversion*/
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,ADON);
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,SWSTART);
	if(GET_BIT(MADC_Channels[copy_PreNum]->SR,EOC)==1)
	{
		*Puint16Result=((MADC_Channels[copy_PreNum]->DR)&0x0FFF);
		/*Clear Flags*/
		CLR_BIT(MADC_Channels[copy_PreNum]->SR,EOC);
		CLR_BIT(MADC_Channels[copy_PreNum]->SR,STRT);
	}
}
void MADC_VidRead_Result_Asynchrouns(MADC_Peripheral copy_PreNum,void(*PtrToFun)(void))
{
	CALLBACK[copy_PreNum]=PtrToFun;
	SET_BIT(MADC_Channels[copy_PreNum]->CR1,EOCIE);
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,ADON);
	SET_BIT(MADC_Channels[copy_PreNum]->CR2,SWSTART);
}

void MADC1_IRQ_Handler(void)
{
	CALLBACK[0]();
	CLR_BIT(MADC_Channels[0]->SR,EOC);
	CLR_BIT(MADC_Channels[0]->SR,STRT);
}
void MADC2_IRQ_Handler(void)
{
	CALLBACK[1]();
	CLR_BIT(MADC_Channels[1]->SR,EOC);
	CLR_BIT(MADC_Channels[1]->SR,STRT);
}
void MADC3_IRQ_Handler(void)
{
	CALLBACK[2]();
	CLR_BIT(MADC_Channels[2]->SR,EOC);
	CLR_BIT(MADC_Channels[2]->SR,STRT);
}
