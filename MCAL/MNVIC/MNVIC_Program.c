/*
 * MNVIC_Program.c
 *
 *  Created on: May 11, 2022 5:49:35 AM NVIC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MNVIC_Private.h"
#include"MNVIC_Config.h"
#include"MNVIC_Interface.h"

/*Initialize*/
void MNVIC_VidInit(void)
{
	/*Check Configuration*/
#if NVIC_GROUPING_PRIORITY==NVIC_GROUP_16
	SCB_AIRCR=(VECTKEY |(NVIC_GROUP_16<<GROUPING_BIT));
#elif NVIC_GROUPING_PRIORITY==NVIC_GROUP_8
	SCB_AIRCR=(VECTKEY |(NVIC_GROUP_8<<GROUPING_BIT));
#elif NVIC_GROUPING_PRIORITY==NVIC_GROUP_4
	SCB_AIRCR=(VECTKEY |(NVIC_GROUP_4<<GROUPING_BIT));
#elif NVIC_GROUPING_PRIORITY==NVIC_GROUP_2
	SCB_AIRCR=(VECTKEY |(NVIC_GROUP_0<<GROUPING_BIT));
#elif NVIC_GROUPING_PRIORITY==NVIC_GROUP_0
	SCB_AIRCR=(VECTKEY |(NVIC_GROUP_0<<GROUPING_BIT));
#else
#error"Configuration Not Valid"
#endif
}
/*Set Enable Specific external interrupt*/
void MNVIC_VidSetEnableIRQ(MNVIC_IRQn copy_IRQn)
{
	/*determine Register
	 * 1-Reg index-->copy_IRQn/32=Val
	 * 2-Val*32-->Value
	 * 3-copy_IRQn-Value-->Bit*/
	uint8 Loc_RegIndex=copy_IRQn/32;
	NVIC->ISER[Loc_RegIndex]=(1<<(copy_IRQn&31));
}
/*Clear Enable Specific external interrupt*/
void MNVIC_VidDisableEnableIRQ(MNVIC_IRQn copy_IRQn)
{
	/*determine Register
		 * 1-Reg index-->copy_IRQn/32=Val
		 * 2-Val*32-->Value
		 * 3-copy_IRQn-Value-->Bit*/
		uint8 Loc_RegIndex=copy_IRQn/32;
		NVIC->ICER[Loc_RegIndex]=(1<<(copy_IRQn&31));
}
/*Set Pending*/
void MNVIC_VidSetPending(MNVIC_IRQn copy_IRQn)
{
	uint8 Loc_RegIndex=copy_IRQn/32;
	NVIC->ISPR[Loc_RegIndex]=(1<<(copy_IRQn&31));
}
/*Get Pending*/
uint8 MNVIC_uint8GetPending(MNVIC_IRQn copy_IRQn)
{
	uint8 Loc_PendState=0;
	uint8 Loc_RegIndex=copy_IRQn/32;
	Loc_PendState=GET_BIT(NVIC->ISPR[Loc_RegIndex],(copy_IRQn&31));
	return Loc_PendState;
}
/*Clear Pending*/
void MNVIC_VidClearPending(MNVIC_IRQn copy_IRQn)
{
	uint8 Loc_RegIndex=copy_IRQn/32;
	NVIC->ICPR[Loc_RegIndex]=(1<<(copy_IRQn&31));
}
/*Get Active*/
uint8 MNVIC_uint8GetActive(MNVIC_IRQn copy_IRQn)
{
	uint8 Loc_ActiveState=0;
	uint8 Loc_RegIndex=copy_IRQn/32;
	Loc_ActiveState=GET_BIT(NVIC->IABR[Loc_RegIndex],(copy_IRQn&31));
	return Loc_ActiveState;
}
/*Set Priority*/
void MNVIC_VidSetPriority(MNVIC_IRQn copy_IRQn,uint8 copy_uint8Priority)
{
	NVIC->IPR[copy_IRQn]=(copy_uint8Priority<<4);
}

