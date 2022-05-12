/*
 * MEXTI_Program.c
 *
 *  Created on: May 12, 2022 5:26:28 AM MEXTI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MEXTI_Private.h"
#include"MEXTI_Interface.h"

void (*CALLBACK)(void);
/*Initialize EXTI*/
void MEXTI_VidInitEXTI(uint8 copy_uint8Line , MEXTI_Trigger_Sense_Control copy_TriggerEvent)
{
/*unmask interrupt line */
	CLR_BIT(EXTI->IMR,copy_uint8Line);
	/*Select Trigger option*/
	switch(copy_TriggerEvent)
	{
	case EXTI_RISING_EDGE:
	{
		SET_BIT(EXTI->RTSR,copy_uint8Line);
		CLR_BIT(EXTI->FTSR,copy_uint8Line);
		break;
	}
	case EXTI_FALLING_EDGE:
	{
		CLR_BIT(EXTI->RTSR,copy_uint8Line);
		SET_BIT(EXTI->FTSR,copy_uint8Line);
		break;
	}
	case EXTI_BOTH_ON_CHANGE:
	{
		SET_BIT(EXTI->RTSR,copy_uint8Line);
		SET_BIT(EXTI->FTSR,copy_uint8Line);
		break;
	}
	default:
		break;
	}
}
/*Enable Line Interrupt*/
void MEXTI_VidEnableEXTI_Line(uint8 copy_uint8Line)
{
	SET_BIT(EXTI->IMR,copy_uint8Line);
}
/*Disable Line Interrupt*/
void MEXTI_VidDisableEXTI_Line(uint8 copy_uint8Line)
{
	CLR_BIT(EXTI->IMR,copy_uint8Line);
}
/*Trigger Software for EXTI Line*/
void MEXTI_VidSw_Trigger_Interrupt(uint8 copy_uint8Line)
{
	SET_BIT(EXTI->SWIER,copy_uint8Line);
}
/*EXTI Pending Flag*/
void MEXTI_VidClearPendingFlag(uint8 copy_uint8Line)
{
	SET_BIT(EXTI->PR,copy_uint8Line);
}
/*EXTI call back*/
void MEXTI_VidSetCallBack(MEXTI_Interrupt_ID copy_InterruptID,void(*PtrToFun)(void))
{
	switch(copy_InterruptID)
	{
	case EXTI0_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI1_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI2_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI3_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI4_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI5_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI6_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI7_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI8_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI9_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI10_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI11_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI12_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI13_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI14_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	case EXTI15_ID:
	{
		CALLBACK=PtrToFun;
		break;
	}
	default:
		break;
	}
}
/*IRQ Handler for Interrupts*/
void MXTIO_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI0_ID);
}
void MXTI1_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI1_ID);
}
void MXTI2_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI2_ID);
}
void MXTI3_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI3_ID);
}
void MXTI4_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI4_ID);
}
void MXTI5_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI5_ID);
}
void MXTI6_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI6_ID);
}
void MXTI7_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI7_ID);
}
void MXTI8_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI8_ID);
}
void MXTI9_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI9_ID);
}
void MXTI1O_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI10_ID);
}
void MXTI11_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI11_ID);
}
void MXTI12_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI12_ID);
}
void MXTI13_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI13_ID);
}
void MXTI14_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI14_ID);
}
void MXTI15_VidIRQ_Handler(void)
{
	CALLBACK();
	SET_BIT(EXTI->PR,EXTI15_ID);
}
