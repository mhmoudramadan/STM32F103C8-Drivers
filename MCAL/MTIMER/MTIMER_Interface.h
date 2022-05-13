/*
 * MTIMER_Interface.h
 *
 *  Created on: May 13, 2022 3:58:16 AM 
 *  Topic-->TIMER_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MTIMER_MTIMER_INTERFACE_H_
#define MCAL_MTIMER_MTIMER_INTERFACE_H_

/*Timer ID*/
#define TIMER1		1
#define TIMER2		2
#define TIMER3		3
#define TIMER4		4
#define TIMER5		5
#define TIMER6		6
#define TIMER7		7
#define TIMER8		8
#define TIMER9		9
#define TIMER10		10
#define TIMER10		10
#define TIMER10		10
#define TIMER11		11
#define TIMER12		12
#define TIMER13		13
#define TIMER14		14
/*Timer Direction*/
#define TIMER_UP_Direction 		0
#define TIMER_DOWN_DIRECTION	1
/*Timer Objects*/
typedef struct
{
	uint16 copy_uint16Reload_Value;
	uint8 copy_uint8Timer_ID;
	uint8 copy_uint8Count_Direction;
	uint8 copy_uint8Interrupt;
	void (*PtrToFun)(void);
}MTimer_Configuration;

/*ProtoTypes*/
void MTIMER_VidInit(MTimer_Configuration *copy_config);
void MTIMER_VidSet_ReloadValue(uint8 copy_uint8TimerID,uint16 copy_uint16Value);
void MTIMER_VidTimer_Enable(uint8 copy_uint8TimerID);
void MTIMER_VidTimer_Disable(uint8 copy_uint8TimerID);
void MTIMER_VidEnable_Timer_Interrupt(uint8 copy_uint8TimerID,uint8 copy_uint8InterruptID);
void MTIMER_Vid_SetCallBack(uint8 copy_uint8TimerID,void(*PtrToFun)(void));
#endif /* MCAL_MTIMER_MTIMER_INTERFACE_H_ */
