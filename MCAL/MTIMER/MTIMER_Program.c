/*
 * MTIMER_Program.c
 *
 *  Created on: May 13, 2022 3:58:43 AM 
 *  Topic-->TIMER_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"MTIMER_Private.h"
#include"MTIMER_Interface.h"

void (*CALLBACK[14])(void);
void MTIMER_VidInit(MTimer_Configuration *copy_config)
{
	/*create variable from struct timer*/
	 GPT_Timer GPT;
	 Advanced_Timer Advanced;
	 Basic_Timer Basic;
	/*Disable Timer at first*/
	MTIMER_VidTimer_Disable(copy_config->copy_uint8Timer_ID);
	/*Set Reload value*/
	MTIMER_VidSet_ReloadValue(copy_config->copy_uint8Timer_ID,copy_config->copy_uint16Reload_Value);
	/*Set counter options*/
	switch(copy_config->copy_uint8Count_Direction)
	{
	case TIMER_UP_Direction:
	{
		CLR_BIT(GPT.CR1,4);
		CLR_BIT(Advanced.CR1,4);
		CLR_BIT(Basic.CR1,4);
	}
	case TIMER_DOWN_DIRECTION:
	{
		SET_BIT(GPT.CR1,4);
		SET_BIT(Advanced.CR1,4);
		SET_BIT(Basic.CR1,4);
		break;
	}
	default:
		break;
	}
	/*Set Interrupt update*/
	SET_BIT(GPT.DIER,0);
	SET_BIT(Advanced.DIER,0);
	SET_BIT(Basic.DIER,0);
	MTIMER_Vid_SetCallBack(copy_config->copy_uint8Timer_ID,copy_config->PtrToFun);
	MTIMER_VidEnable_Timer_Interrupt(copy_config->copy_uint8Timer_ID,copy_config->copy_uint8Interrupt);
	/*Enable Timer*/
	MTIMER_VidTimer_Enable(copy_config->copy_uint8Timer_ID);
}
void MTIMER_VidSet_ReloadValue(uint8 copy_uint8TimerID,uint16 copy_uint16Value)
{
	switch(copy_uint8TimerID)
	{
	case TIMER1:
	{
		TIM1->ARR=copy_uint16Value;
		break;
	}
	case TIMER2:
	{
		TIM2->ARR=copy_uint16Value;
		break;
	}
	case TIMER3:
	{
		TIM3->ARR=copy_uint16Value;
		break;
	}
	case TIMER4:
	{
		TIM4->ARR=copy_uint16Value;
		break;
	}
	case TIMER5:
	{
		TIM5->ARR=copy_uint16Value;
		break;
	}
	case TIMER6:
	{
		TIM6->ARR=copy_uint16Value;
		break;
	}
	case TIMER7:
	{
		TIM7->ARR=copy_uint16Value;
		break;
	}
	case TIMER8:
	{
		TIM8->ARR=copy_uint16Value;
		break;
	}
	case TIMER9:
	{
		TIM9->ARR=copy_uint16Value;
		break;
	}
	case TIMER10:
	{
		TIM10->ARR=copy_uint16Value;
		break;
	}
	case TIMER11:
	{
		TIM11->ARR=copy_uint16Value;
		break;
	}
	case TIMER12:
	{
		TIM12->ARR=copy_uint16Value;
		break;
	}
	case TIMER13:
	{
		TIM13->ARR=copy_uint16Value;
		break;
	}
	case TIMER14:
	{
		TIM14->ARR=copy_uint16Value;
		break;
	}
	default:
		break;
	}
}
void MTIMER_VidTimer_Enable(uint8 copy_uint8TimerID)
{
	switch(copy_uint8TimerID)
	{
	case TIMER1:
	{
		SET_BIT(TIM1->CR1,0);
		break;
	}
	case TIMER2:
	{
		SET_BIT(TIM2->CR1,0);
		break;
	}
	case TIMER3:
	{
		SET_BIT(TIM3->CR1,0);
		break;
	}
	case TIMER4:
	{
		SET_BIT(TIM4->CR1,0);
		break;
	}
	case TIMER5:
	{
		SET_BIT(TIM5->CR1,0);
		break;
	}
	case TIMER6:
	{
		SET_BIT(TIM6->CR1,0);
		break;
	}
	case TIMER7:
	{
		SET_BIT(TIM7->CR1,0);
		break;
	}
	case TIMER8:
	{
		SET_BIT(TIM8->CR1,0);
		break;
	}
	case TIMER9:
	{
		SET_BIT(TIM9->CR1,0);
		break;
	}
	case TIMER10:
	{
		SET_BIT(TIM10->CR1,0);
		break;
	}
	case TIMER11:
	{
		SET_BIT(TIM11->CR1,0);
		break;
	}
	case TIMER12:
	{
		SET_BIT(TIM12->CR1,0);
		break;
	}
	case TIMER13:
	{
		SET_BIT(TIM13->CR1,0);
		break;
	}
	case TIMER14:
	{
		SET_BIT(TIM14->CR1,0);
		break;
	}
	default:
		break;
	}
}
void MTIMER_VidTimer_Disable(uint8 copy_uint8TimerID)
{
	switch(copy_uint8TimerID)
	{
	case TIMER1:
	{
		CLR_BIT(TIM1->CR1,0);
		break;
	}
	case TIMER2:
	{
		CLR_BIT(TIM2->CR1,0);
		break;
	}
	case TIMER3:
	{
		CLR_BIT(TIM3->CR1,0);
		break;
	}
	case TIMER4:
	{
		CLR_BIT(TIM4->CR1,0);
		break;
	}
	case TIMER5:
	{
		CLR_BIT(TIM5->CR1,0);
		break;
	}
	case TIMER6:
	{
		CLR_BIT(TIM6->CR1,0);
		break;
	}
	case TIMER7:
	{
		CLR_BIT(TIM7->CR1,0);
		break;
	}
	case TIMER8:
	{
		CLR_BIT(TIM8->CR1,0);
		break;
	}
	case TIMER9:
	{
		CLR_BIT(TIM9->CR1,0);
		break;
	}
	case TIMER10:
	{
		CLR_BIT(TIM10->CR1,0);
		break;
	}
	case TIMER11:
	{
		CLR_BIT(TIM11->CR1,0);
		break;
	}
	case TIMER12:
	{
		CLR_BIT(TIM12->CR1,0);
		break;
	}
	case TIMER13:
	{
		CLR_BIT(TIM13->CR1,0);
		break;
	}
	case TIMER14:
	{
		CLR_BIT(TIM14->CR1,0);
		break;
	}
	default:
		break;
	}
}
void MTIMER_VidEnable_Timer_Interrupt(uint8 copy_uint8TimerID,uint8 copy_uint8InterruptID)
{
	switch(copy_uint8TimerID)
	{
	case TIMER1:
	{
		TIM1->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER2:
	{
		TIM2->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER3:
	{
		TIM3->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER4:
	{
		TIM4->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER5:
	{
		TIM5->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER6:
	{
		TIM6->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER7:
	{
		TIM7->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER8:
	{
		TIM8->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER9:
	{
		TIM9->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER10:
	{
		TIM10->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER11:
	{
		TIM11->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER12:
	{
		TIM12->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER13:
	{
		TIM13->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	case TIMER14:
	{
		TIM14->DIER |=(1<<copy_uint8InterruptID);
		break;
	}
	default:
		break;
	}
}
void MTIMER_Vid_SetCallBack(uint8 copy_uint8TimerID,void(*PtrToFun)(void))
{
	CALLBACK[copy_uint8TimerID]=PtrToFun;
}
void MTIMER1_VidIRQ_Handler(void)
{
	CALLBACK[0]();
}
void MTIMER2_VidIRQ_Handler(void)
{
	CALLBACK[1]();
}
void MTIMER3_VidIRQ_Handler(void)
{
	CALLBACK[2]();
}
void MTIMER4_VidIRQ_Handler(void)
{
	CALLBACK[3]();
}void MTIMER5_VidIRQ_Handler(void)
{
	CALLBACK[4]();
}
void MTIMER6_VidIRQ_Handler(void)
{
	CALLBACK[5]();
}void MTIMER7_VidIRQ_Handler(void)
{
	CALLBACK[6]();
}
void MTIMER8_VidIRQ_Handler(void)
{
	CALLBACK[7]();
}void MTIMER9_VidIRQ_Handler(void)
{
	CALLBACK[8]();
}
void MTIMER10_VidIRQ_Handler(void)
{
	CALLBACK[9]();
}void MTIMER11_VidIRQ_Handler(void)
{
	CALLBACK[10]();
}
void MTIMER12_VidIRQ_Handler(void)
{
	CALLBACK[11]();
}void MTIMER13_VidIRQ_Handler(void)
{
	CALLBACK[12]();
}
void MTIMER14_VidIRQ_Handler(void)
{
	CALLBACK[13]();
}

