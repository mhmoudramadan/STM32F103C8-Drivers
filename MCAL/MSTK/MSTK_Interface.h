/*
 * MSTK_Interface.h
 *
 *  Created on: May 15, 2022 4:58:45 AM 
 *  Topic-->STK_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSTK_MSTK_INTERFACE_H_
#define MCAL_MSTK_MSTK_INTERFACE_H_

typedef enum
{
	TIME_MS,
	TIME_US
}MSTK_Time_Options;
/*ProtoTypes*/
void MSTK_VidInit(void);
void MSTK_VidSet_BusyWait(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint);
void MSTK_VidSet_Interval_Periodic(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint,void(*PtrToFun)(void));
void MSTK_VidSet_Interval_Single(uint32 copy_uint32Time,MSTK_Time_Options copy_TimeUint,void(*PtrToFun)(void));
void MSTK_Vid_StopSTK(void);
void MSTK_Vid_ResumeSTK(void);
void MSTK_Vid_StartSTK(void);
uint32 MSTK_uint32Get_ElapsedTime(MSTK_Time_Options copy_TimeUint);
uint32 MSTK_uint32Get_RemainingTime(MSTK_Time_Options copy_TimeUint);


#endif /* MCAL_MSTK_MSTK_INTERFACE_H_ */
