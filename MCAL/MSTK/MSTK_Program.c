/*
 * MSTK_Program.c
 *
 *  Created on: May 15, 2022 4:59:14 AM 
 *  Topic-->STK_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MSTK_Private.h"
#include"MSTK_Config.h"
#include"MSTK_Interface.h"

uint32 Global_uint32Clock=0;

void(*CALLBACK)(void);

void MSTK_VidInit(void)
{
	/*Reset Register first */
	STK->CTRL=0x00000000;
	/*Choose Clock*/
#if STK_CLOCK_SOURCE==AHP_SOURCE
		SET_BIT(STK->CTRL,CTRL_CLKSOURCE);
		Global_uint32Clock=STK_AHP_CLOCK;
#elif STK_CLOCK_SOURCE==AHB_BY_8_SOURCE
		CLR_BIT(STK->CTRL,CTRL_CLKSOURCE);
		Global_uint32Clock=STK_AHP_CLOCK/8;
#else
#error"Option of Clock Is Not Valid"
#endif
}
void MSTK_VidSet_BusyWait(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint)
{
	uint32 Loc_Value=0;
	switch(copy_TimeUint)
	{
	case TIME_MS:
	{
		Loc_Value=copy_uint32Time*(Global_uint32Clock/1000);
		STK->LOAD=Loc_Value;
		break;
	}
	case TIME_US:
	{
		Loc_Value=copy_uint32Time*(Global_uint32Clock/1000000);
		STK->LOAD=Loc_Value;
		break;
	}
	default:
		break;
	}
	/*Timer Initialize */
	SET_BIT(STK->CTRL,CTRL_ENABLE);
	/*Wait for flag to not equal last time*/
	while(!(GET_BIT(STK->CTRL,CTRL_COUNTFLAG)));
	/*Stop Timer*/
	CLR_BIT(STK->CTRL,CTRL_ENABLE);
}
void MSTK_VidSet_Interval_Periodic(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint,void(*PtrToFun)(void))
{
	uint32 Loc_Load=0;
	switch(copy_TimeUint)
	{
	case TIME_MS:
	{
		Loc_Load=copy_uint32Time*(Global_uint32Clock/1000);
		STK->LOAD=Loc_Load;
		break;
	}
	case TIME_US:
	{
		Loc_Load=copy_uint32Time*(Global_uint32Clock/1000000);
		STK->LOAD=Loc_Load;
		break;
	}
	default:
		break;
	}
	CALLBACK=PtrToFun;
	/*Timer Initialize */
	SET_BIT(STK->CTRL,CTRL_ENABLE);
	/*Enable interrupt*/
	SET_BIT(STK->CTRL,CTRL_TICKINT);
}
void MSTK_VidSet_Interval_Single(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint,void(*PtrToFun)(void))
{
	uint32 Loc_Load=0;
	CLR_BIT(STK->CTRL,CTRL_ENABLE);
	STK->VAL=0x00000000;
	switch(copy_TimeUint)
	{
	case TIME_MS:
	{
		Loc_Load=copy_uint32Time*(Global_uint32Clock/1000);
		STK->LOAD=Loc_Load;
		break;
	}
	case TIME_US:
	{
		Loc_Load=copy_uint32Time*(Global_uint32Clock/1000000);
		STK->LOAD=Loc_Load;
		break;
	}
	default:
		break;
	}
	CALLBACK=PtrToFun;
	/*Timer Initialize */
	SET_BIT(STK->CTRL,CTRL_ENABLE);
	/*Enable interrupt*/
	SET_BIT(STK->CTRL,CTRL_TICKINT);

}
void MSTK_Vid_StopSTK(void)
{
	/*Stop Timer*/
	CLR_BIT(STK->CTRL,CTRL_ENABLE);
	/*Disable Time*/
	CLR_BIT(STK->CTRL,CTRL_TICKINT);
}
void MSTK_Vid_ResumeSTK(void)
{
	/*Timer Initialize */
	SET_BIT(STK->CTRL,CTRL_ENABLE);
	/*Enable interrupt*/
	SET_BIT(STK->CTRL,CTRL_TICKINT);
}
void MSTK_Vid_StartSTK(void)
{
	STK->VAL=0x00000000;
	/*Load Value With Maximum*/
	STK->LOAD=0xFFFFFFFF;
	/*Timer Initialize */
	SET_BIT(STK->CTRL,CTRL_ENABLE);

}
uint32 MSTK_uint32Get_ElapsedTime(MSTK_Time_Options copy_TimeUint)
{
	uint32 Loc_Val=0,Loc_ElaspesedTime=0;
	Loc_Val=STK->LOAD -STK->VAL;
	switch(copy_TimeUint)
	{
	case TIME_MS:
	{
		Loc_ElaspesedTime=Loc_Val*(Global_uint32Clock/1000);
		break;
	}
	case TIME_US:
	{
		Loc_ElaspesedTime=Loc_Val*(Global_uint32Clock/1000000);
		break;
	}
	default:
		break;
	}
	return Loc_ElaspesedTime;
}
uint32 MSTK_uint32Get_RemainingTime(MSTK_Time_Options copy_TimeUint)
{
	uint32 Loc_Val=0,Loc_RemainingTime=0;
		Loc_Val=STK->VAL;
		switch(copy_TimeUint)
		{
		case TIME_MS:
		{
			Loc_RemainingTime=Loc_Val*(Global_uint32Clock/1000);
			break;
		}
		case TIME_US:
		{
			Loc_RemainingTime=Loc_Val*(Global_uint32Clock/1000000);
			break;
		}
		default:
			break;
		}
		return Loc_RemainingTime;
}

/*ISR*/
void MSTK_Vid_IRQHandler_SingleInterval(void)
{
	CLR_BIT(STK->CTRL,CTRL_ENABLE);
	CLR_BIT(STK->CTRL,CTRL_TICKINT);
	CALLBACK();
}
void MSTK_Vid_IRQHandler_PeriodicInterval(void)
{
	CALLBACK();
}
