/*
 * MFPEC_Program.c
 *
 *  Created on: May 16, 2022 1:13:28 AM 
 *  Topic-->FPEC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MFPEC_Private.h"
#include"MFPEC_Config.h"
#include"MFPEC_Interface.h"

void MFPEC_VidProgrammFlash(uint32 copy_uint32Address,uint16 *Puint16_code,uint8 copy_uint8Length)
{
	/*check fo main memory operation*/
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	/*Check for flash Lock*/
	if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
	{
	/*Sequence for Unlock*/
	FPEC->FLASH_KEYR=MFPEC_KEY1;
	FPEC->FLASH_KEYR=MFPEC_KEY2;
	}
	for(uint8 Loc_Counter=0;Loc_Counter<copy_uint8Length;Loc_Counter++)
	{
	/*Write on flash*/
		SET_BIT(FPEC->FLASH_CR,PG);
		/*Half Word Write*/
		*((uint16 *)copy_uint32Address)=Puint16_code[Loc_Counter];
		copy_uint32Address=copy_uint32Address+2;
		while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
		SET_BIT(FPEC->FLASH_SR,EOP);
		CLR_BIT(FPEC->FLASH_CR,PG);
	}
}
uint8 MFPEC_VidProgram_HalfWord_Flash(uint32 copy_uint32Address,uint16 copy_uint16Code)
{
	uint8 Loc_State=0;
	/*Check for flash Lock*/
	if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
	{
		/*Sequence for Unlock*/
		FPEC->FLASH_KEYR=MFPEC_KEY1;
		FPEC->FLASH_KEYR=MFPEC_KEY2;
	}
	/*check fo main memory operation*/
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
		SET_BIT(FPEC->FLASH_CR,PG);
		/*Write On Flash*/
		*((uint16 *)copy_uint32Address)=copy_uint16Code;
		while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
		CLR_BIT(FPEC->FLASH_CR,PG);
		/*Chechk on data*/
		if(*((uint16 *)copy_uint32Address)==copy_uint16Code)
		{
			Loc_State=1;
		}
		else
		{
			Loc_State=0;
		}
		SET_BIT(FPEC->FLASH_SR,EOP);
		return Loc_State;
}
uint8 MFPEC_Vid_OneByteOption_Program_HalfWord_FLash(uint32 copy_uint32Address,uint16 copy_uint16Code)
{
	uint8 Loc_State=0;
		/*Check for flash Lock*/
		if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
		{
			/*Sequence for Unlock*/
			FPEC->FLASH_OPTKEYR=RDPRT_KEY;
		}
		/*unlock one byte programming*/
		SET_BIT(FPEC->FLASH_CR,OPTWRE);
		SET_BIT(FPEC->FLASH_CR,OPTPG);
		/*Write On Flash*/
		*((uint16 *)copy_uint32Address)=copy_uint16Code;
		while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
		CLR_BIT(FPEC->FLASH_CR,PG);
		if(*((uint16 *)copy_uint32Address)==copy_uint16Code)
		{
			Loc_State=1;
		}
		else
		{
			Loc_State=0;
		}
		SET_BIT(FPEC->FLASH_SR,EOP);
		return Loc_State;
}
void MFPEC_Vid_Erase_OneByteOption(uint16 copy_uint16Page)
{
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	/*Check for flash Lock*/
	if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
	{
		/*Sequence for Unlock*/
		FPEC->FLASH_OPTKEYR=RDPRT_KEY;
	}
	/*unlock one byte Erase */
	SET_BIT(FPEC->FLASH_CR,OPTWRE);
	SET_BIT(FPEC->FLASH_CR,OPTER);
	FPEC->FLASH_AR=FLASH_FIRST_ADDRESS+(uint32)copy_uint16Page;
	/**Start Erase*/
	SET_BIT(FPEC->FLASH_CR,STRT);
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	SET_BIT(FPEC->FLASH_SR,EOP);
	CLR_BIT(FPEC->FLASH_CR,PG);
}
void MFPEC_VidErase_Page(uint16 copy_uint16Page)
{
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
	{
		/*Sequence for Unlock*/
		FPEC->FLASH_KEYR=MFPEC_KEY1;
		FPEC->FLASH_KEYR=MFPEC_KEY2;
	}
	SET_BIT(FPEC->FLASH_CR,PER);
	/*program Flash address Register*/
	FPEC->FLASH_AR=FLASH_FIRST_ADDRESS+(uint32)(copy_uint16Page);
	/**Start Erase*/
	SET_BIT(FPEC->FLASH_CR,STRT);
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	/*Disable Erase Page*/
	CLR_BIT(FPEC->FLASH_CR,PER);
	SET_BIT(FPEC->FLASH_SR,EOP);
	CLR_BIT(FPEC->FLASH_CR,PG);
}
void MFPEC_VidErase_Area(void)
{
	for(uint8 Loc_Page=FIRSTPAGE_INAREA;Loc_Page<LASTPAGE_INAREA;Loc_Page++)
	{
		MFPEC_VidErase_Page(Loc_Page);
	}
}
void MFPEC_VidErase_Mass(void )
{
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	if(GET_BIT(FPEC->FLASH_CR,LOCK)==1)
	{
		/*Sequence for Unlock*/
		FPEC->FLASH_KEYR=MFPEC_KEY1;
		FPEC->FLASH_KEYR=MFPEC_KEY2;
	}
	SET_BIT(FPEC->FLASH_CR,MER);
	/**Start Erase*/
	SET_BIT(FPEC->FLASH_CR,STRT);
	while(GET_BIT(FPEC->FLASH_SR,BSY)==1);
	SET_BIT(FPEC->FLASH_SR,EOP);
	CLR_BIT(FPEC->FLASH_CR,PG);
}
