/*
 * MEXTI_Interface.h
 *
 *  Created on: May 12, 2022 5:25:32 AM MEXTI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_
/*EXTI Line*/
typedef enum
{
	LINE0=0,
	LINE1,
	LINE2,
	LINE3,
	LINE4,
	LINE5,
	LINE6,
	LINE7,
	LINE8,
	LINE9,
	LINE10,
	LINE11,
	LINE12,
	LINE13,
	LINE14,
	LINE15
}EXTI_LINE;
/*External Interrupt ID*/
typedef enum
{
	EXTI0_ID=0,
	EXTI1_ID,
	EXTI2_ID,
	EXTI3_ID,
	EXTI4_ID,
	EXTI5_ID,
	EXTI6_ID,
	EXTI7_ID,
	EXTI8_ID,
	EXTI9_ID,
	EXTI10_ID,
	EXTI11_ID,
	EXTI12_ID,
	EXTI13_ID,
	EXTI14_ID,
	EXTI15_ID
}MEXTI_Interrupt_ID;
/*Trigger Event Options*/
typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_BOTH_ON_CHANGE
}MEXTI_Trigger_Sense_Control;
/*Initialize EXTI*/
void MEXTI_VidInitEXTI(uint8 copy_uint8Line , MEXTI_Trigger_Sense_Control copy_TriggerEvent);
/*Enable Line Interrupt*/
void MEXTI_VidEnableEXTI_Line(uint8 copy_uint8Line);
/*Disable Line Interrupt*/
void MEXTI_VidDisableEXTI_Line(uint8 copy_uint8Line);
/*Trigger Software for EXTI Line*/
void MEXTI_VidSw_Trigger_Interrupt(uint8 copy_uint8Line);
/*EXTI Pending Flag*/
void MEXTI_VidClearPendingFlag(uint8 copy_uint8Line);
/*EXTI call back*/
void MEXTI_VidSetCallBack(MEXTI_Interrupt_ID copy_InterruptID,void(*PtrToFun)(void));
#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
