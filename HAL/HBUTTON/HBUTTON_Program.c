/*
 * HBUTTON_Program.c
 *
 *  Created on: May 12, 2022 12:16:35 PM PUSH_BUTTON_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"../../MCAL/MGPIO/MGPIO_Interface.h"
#include"../../MCAL/MRCC/MRCC_Interface.h"
#include"HBUTTON_Interface.h"
void HBUTTON_VidInit(Button_t* copy_Button)
{
	MRCC_VidEnableSystemClock(RCC_APB2,(copy_Button->Button_PortID+IOPBEN_PERIPHERAL));
/*initilize Pins as input*/
	if(copy_Button->Button_Active_State==INTERNAL_PULL_UP)
	{
		MGPIO_ErrorStateSetPinMode(copy_Button->Button_PortID,copy_Button->Button_PinNum,MGPIO_INPUT_PULL_UP_DOWN_MODE);
		MGPIO_ErrorStateSetPinValue(copy_Button->Button_PortID,copy_Button->Button_PinNum,MGPIO_PULL_UP);
	}
	else if(copy_Button->Button_Active_State==INTERNAL_PULL_DOWN)
	{
		MGPIO_ErrorStateSetPinMode(copy_Button->Button_PortID,copy_Button->Button_PinNum,MGPIO_INPUT_PULL_UP_DOWN_MODE);
		MGPIO_ErrorStateSetPinValue(copy_Button->Button_PortID,copy_Button->Button_PinNum,MGPIO_PULL_DOWN);
	}
	else if((copy_Button->Button_Active_State==EXTERNAL_PULL_UP)||((copy_Button->Button_Active_State==EXTERNAL_PULL_DOWN)))
	{
		MGPIO_ErrorStateSetPinMode(copy_Button->Button_PortID,copy_Button->Button_PinNum,MGPIO_INPUT_FLOATING_MODE);
	}
	else
	{
		/*Do Nothing*/
	}
}
ErrorState HBUTTON_ErrorState_Button_Pressed(Button_t* copy_Button)
{

	uint8 Loc_Button_State;
	if(copy_Button->Button_Active_State==INTERNAL_PULL_UP)
	{
		Loc_Button_State=MGPIO_uint8GetPinValue(copy_Button->Button_PortID,copy_Button->Button_PinNum);

	}
	else if(copy_Button->Button_Active_State==INTERNAL_PULL_DOWN)
	{
		Loc_Button_State=MGPIO_uint8GetPinValue(copy_Button->Button_PortID,copy_Button->Button_PinNum);
	}
	else if((copy_Button->Button_Active_State==EXTERNAL_PULL_UP)||((copy_Button->Button_Active_State==EXTERNAL_PULL_DOWN)))
	{
		Loc_Button_State=MGPIO_uint8GetPinValue(copy_Button->Button_PortID,copy_Button->Button_PinNum);

	}
	else
	{
		/*Error handle*/
	}
	return Loc_Button_State;
}

