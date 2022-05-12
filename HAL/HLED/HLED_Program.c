/*
 * HLED_Program.c
 *
 *  Created on: May 12, 2022 11:06:47 AM LED_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"../../MCAL/MGPIO/MGPIO_Interface.h"
#include"../../MCAL/MRCC/MRCC_Interface.h"
#include"HLED_Private.h"
#include"HLED_Config.h"
#include"HLED_Interface.h"

/*initialize Led*/
void HLED_VidInit(LED_t copy_LedConfig)
{
	/*Enable RCC clock for Port*/
	MRCC_VidEnableSystemClock(RCC_APB2,(copy_LedConfig.Led_PortID+IOPAEN_PERIPHERAL));
	/*set pin output*/
	MGPIO_ErrorStateSetPinMode(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,LED_MODE_OUTPUT);
	/*Initialize Led off*/
	MGPIO_ErrorStateSetPinValue(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,ACTIVE_LOW);
}
/*Set State*/
void HLED_VidSet_State(LED_t copy_LedConfig,LED_State copy_LedState)
{
	switch(copy_LedState)
	{
	case ON:
	{
		MGPIO_ErrorStateSetPinValue(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,ACTIVE_HIGH);
		break;
	}
	case OFF:
	{
		MGPIO_ErrorStateSetPinValue(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,ACTIVE_LOW);
		break;
	}
	default:
		break;
	}
}
/*Toggle Led*/
void HLED_VidToggleLed(LED_t copy_LedConfig)
{
	static uint8 Loc_Flag=0;
	if(Loc_Flag==0)
	{
		MGPIO_ErrorStateSetPinValue(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,ACTIVE_HIGH);
		Loc_Flag=1;
	}
	else if(Loc_Flag==1)
	{
		MGPIO_ErrorStateSetPinValue(copy_LedConfig.Led_PortID,copy_LedConfig.Led_PinNum,ACTIVE_LOW);
	}
	else
	{
		/*Do nothing*/
	}
}

