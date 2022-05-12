/*
 * MAFIO_Program.c
 *
 *  Created on: May 12, 2022 9:49:56 AM AFIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MAFIO_Private.h"
#include"MAFIO_Interface.h"

void MAFIO_VidSelectPort_Line_Configuration(uint8 copy_uint8Line,uint8 copy_uint8PortID)
{
	/*Local Varaible*/
	uint8 Loc_RegIndex=0,Loc_Offest=0;
	/*Register index*/
	Loc_RegIndex=copy_uint8Line/LINE_4BIT;
	/*Offest*/
	Loc_Offest=copy_uint8Line/LINE_4BIT;
	Loc_Offest=Loc_Offest*4;

	/*Clear 4 bits first */
	AFIO->EXTICR[Loc_RegIndex] &=~(EXTI_CLEAR_LINE <<Loc_Offest);
	/*Set 4 Bits*/
	AFIO->EXTICR[Loc_RegIndex]|= (copy_uint8PortID<<Loc_Offest);
}
