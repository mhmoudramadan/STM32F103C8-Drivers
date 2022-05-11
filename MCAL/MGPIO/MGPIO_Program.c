/*
 * MGPIO_Program.c
 *
 *  Created on: May 11, 2022 12:36:52 AM GPIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MGPIO_Private.h"
#include"MGPIO_Interface.h"

ErrorState MGPIO_ErrorStateSetPinMode(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum, MGPIO_Modes copy_Mode)
{
	uint8 Loc_error=OK;
	switch(copy_PortID)
	{
	case PORTA:
	{
		if(copy_PinNum<=7)
		{
			/*Reset 4 bits first*/
			GPIOA_CRL &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOA_CRL |= (copy_Mode<<copy_PinNum*4);
		}
		else if(copy_PinNum<=15)
		{
			copy_PinNum=copy_PinNum-8;
			/*Reset 4 bits first*/
			GPIOA_CRH &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOA_CRH |= (copy_Mode<<copy_PinNum*4);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	case PORTB:
	{
		if(copy_PinNum<=7)
		{
			/*Reset 4 bits first*/
			GPIOB_CRL &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOB_CRL |= (copy_Mode<<copy_PinNum*4);
		}
		else if(copy_PinNum<=15)
		{
			copy_PinNum=copy_PinNum-8;
			/*Reset 4 bits first*/
			GPIOB_CRH &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOB_CRH |= (copy_Mode<<copy_PinNum*4);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	case PORTC:
	{
		if(copy_PinNum<=7)
		{
			/*Reset 4 bits first*/
			GPIOC_CRL &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOC_CRL |= (copy_Mode<<copy_PinNum*4);
		}
		else if(copy_PinNum<=15)
		{
			copy_PinNum=copy_PinNum-8;
			/*Reset 4 bits first*/
			GPIOC_CRH &= ~(CLR_VAL<<copy_PinNum*4);
			/*update with mode*/
			GPIOC_CRH |= (copy_Mode<<copy_PinNum*4);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	default :
		break;
	}
	return Loc_error;
}
ErrorState MGPIO_ErrorStateSetPinValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum, uint8 copy_uint8Value)
{
	uint8 Loc_error=OK;
	switch(copy_PortID)
	{
	case PORTA:
	{
		if(copy_uint8Value==HIGH)
		{
			GPIOA_BSRR=(1<<copy_PinNum);
		}
		else if(copy_uint8Value==LOW)
		{
			GPIOA_BRR=(1<<copy_PinNum);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	case PORTB:
	{
		if(copy_uint8Value==HIGH)
		{
			GPIOB_BSRR=(1<<copy_PinNum);
		}
		else if(copy_uint8Value==LOW)
		{
			GPIOB_BRR=(1<<copy_PinNum);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	case PORTC:
	{
		if(copy_uint8Value==HIGH)
		{
			GPIOC_BSRR=(1<<copy_PinNum);
		}
		else if(copy_uint8Value==LOW)
		{
			GPIOC_BRR=(1<<copy_PinNum);
		}
		else
		{
			Loc_error=NOK;
		}
		break;
	}
	default:
		break;
	}
			return Loc_error;
}
ErrorState MGPIO_ErrorStateSetPortMode(MGPIO_PortID copy_PortID, MGPIO_Modes copy_Mode)
{
	uint8 Loc_error=OK;
	for(MGPIO_PinNum Pins=PIN0;Pins<=15;Pins++)
	{
		MGPIO_ErrorStateSetPinMode(copy_PortID,Pins,copy_Mode);
	}
	return Loc_error;
}
ErrorState MGPIO_ErrorStateSetPortValue(MGPIO_PortID copy_PortID, uint16 copy_uint16Value)
{
	uint8 Loc_error=OK;
	switch(copy_PortID)
	{
	case PORTA:
	{
		GPIOA_ODR |= copy_uint16Value;
		break;
	}
	case PORTB:
	{
		GPIOB_ODR |= copy_uint16Value;
		break;
	}
	case PORTC:
	{
		GPIOC_ODR |= copy_uint16Value;
		break;
	}
	default:
		break;
	}
	return Loc_error;
}

uint8 MGPIO_uint8GetPinValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum)
{
	uint8 Loc_PinState=0;
	switch(copy_PortID)
	{
	case PORTA:
	{
		Loc_PinState=GET_BIT(GPIOA_IDR,copy_PinNum);
		break;
	}
	case PORTB:
	{
		Loc_PinState=GET_BIT(GPIOB_IDR,copy_PinNum);
		break;
	}
	case PORTC:
	{
		Loc_PinState=GET_BIT(GPIOC_IDR,copy_PinNum);
		break;
	}
	default:
		break;
	}
	return Loc_PinState;
}
ErrorState MGPIO_ErrorStateWritePinsValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum,MGPIO_PinsToWrite copy_Pins,uint8 copy_uint8Value)
{
	uint8 Loc_error=OK;
	switch(copy_PortID)
	{
		case PORTA:
		{
			GPIOA_ODR &=~(copy_Pins<<copy_PinNum);
			GPIOA_ODR |=(copy_uint8Value <<copy_PinNum);
			break;
		}
		case PORTB:
		{
			GPIOB_ODR &=~(copy_Pins<<copy_PinNum);
			GPIOB_ODR |=(copy_uint8Value <<copy_PinNum);
			break;
		}
		case PORTC:
		{
			GPIOC_ODR &=~(copy_Pins<<copy_PinNum);
			GPIOC_ODR |=(copy_uint8Value <<copy_PinNum);
			break;
		}

	default:
	break;
	}
	return Loc_error;
}
ErrorState MGPIO_ErrorStateLockPin(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum)
{
	uint8 Loc_error=OK;
	uint32 Loc_Temp=0x0001000;
	switch(copy_PortID)
	{
	case PORTA:
	{
		Loc_Temp |=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOA_LCKR=Loc_Temp;
		/*Reset LCKK bit*/
		GPIOA_LCKR=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOA_LCKR=Loc_Temp;
		/*Read Lock bit*/
		Loc_Temp=GPIOA_LCKR;
		/*Read Lock bit*/
		Loc_Temp=GPIOA_LCKR;
		break;
	}
	case PORTB:
	{
		Loc_Temp |=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOB_LCKR=Loc_Temp;
		/*Reset LCKK bit*/
		GPIOB_LCKR=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOB_LCKR=Loc_Temp;
		/*Read Lock bit*/
		Loc_Temp=GPIOB_LCKR;
		/*Read Lock bit*/
		Loc_Temp=GPIOB_LCKR;
		break;
	}
	case PORTC:
	{
		Loc_Temp |=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOC_LCKR=Loc_Temp;
		/*Reset LCKK bit*/
		GPIOC_LCKR=(1<<copy_PinNum);
		/*Set LCKK bit*/
		GPIOC_LCKR=Loc_Temp;
		/*Read Lock bit*/
		Loc_Temp=GPIOC_LCKR;
		/*Read Lock bit*/
		Loc_Temp=GPIOC_LCKR;
		break;
	}
	default:
		break;
	}
	return Loc_error;
}
