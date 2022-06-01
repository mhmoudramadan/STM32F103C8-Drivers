/*
 * MI2C_Program.c
 *
 *  Created on: May 26, 2022 1:15:57 PM 
 *  Topic-->I2C_DRIVER_PRO
 *      Author: mahmoud ramadan
 */
#include"../../LIB/LSTD_TYPES.h"
#include"../../LIB/LBIT_MATH.h"
#include"../../MCAL/MGPIO/MGPIO_Interface.h"
#include"../../MCAL/MRCC/MRCC_Interface.h"
#include"MI2C_Private.h"
#include"MI2C_Config.h"
#include"MI2C_Interface.h"

ErrorState MI2C_errorstate_Init(MI2C_Register* MI2Cx,MI2C_Confg *PI2C_Config)
{
	ErrorState Loc_Error=OK;
	/*Init SCL & SDA*/
	MGPIO_ErrorStateSetPinMode(MI2C_Pins[MI2C_SCL].MI2C_Port,MI2C_Pins[MI2C_SCL].MI2C_Pin,MGPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN);
	MGPIO_ErrorStateSetPinMode(MI2C_Pins[MI2C_SDA].MI2C_Port,MI2C_Pins[MI2C_SDA].MI2C_Pin,MGPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN);
	/*Disable I2C*/
	MI2C_errorstate_SetState(MI2Cx,DISABLE);
	/*I2C CLK*/
	MI2C_SetClkSetting(MI2Cx,PI2C_Config->MI2C_ClockSpeed,PI2C_Config->MI2C_DutyCycle);
	/*DMA*/
	MI2C_ConfigDMA(MI2Cx,PI2C_Config->MI2C_DMA);
	/*Set address1*/
	MI2C_SetAdd1(MI2Cx,PI2C_Config->MI2C_OWN_Address1,PI2C_Config->MI2C_AddressLength);
	/*Set I2C Mode*/
	MI2C_SetMode(MI2Cx,PI2C_Config->MI2C_Mode);
	/*Set ACK*/
	MI2C_errorstate_Set_ACK(MI2Cx,PI2C_Config->MI2C_Ack);
	/*Set address2*/
	MI2C_SetAdd2(MI2Cx,PI2C_Config->MI2C_OWN_Address2,PI2C_Config->MI2C_AddressLength);
	/*Set General Call*/
	MI2C_errorstate_Set_GenCall(MI2Cx,PI2C_Config->MI2C_Gen_Call);
	/*confg interrupts*/
	MI2C_errorstate_Confg_Interrupts(MI2Cx,&(PI2C_Config->MI2C_Interrupts));
	/*Enable I2C*/
	MI2C_errorstate_SetState(MI2Cx,PI2C_Config->MI2C_Initial_State);
	return Loc_Error;
}
ErrorState MI2C_errorstate_SetState(MI2C_Register* MI2Cx,uint8 copy_uint8State)
{
	ErrorState Loc_error=OK;
	/*Enable / Diasble peripheral*/
	switch (copy_uint8State)
	{
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR1,PE);
		break;
	}
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR1,PE);
		break;
	}

	default:
		break;
	}
	return Loc_error;
}
ErrorState MI2C_errorstate_Start_Condition(MI2C_Register* MI2Cx,uint8 copy_uint8startstate)
{
	uint16 Loc_StatusRegister=0;
	ErrorState Loc_error=OK;
	/*enable or disable start condition */
	switch (copy_uint8startstate)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR1,START);
		/*Wait until Start Flag is set*/
		while(GET_BIT(MI2Cx->SR1,SB)==1);
		/*Read status reg start flag*/
		MI2C_errorstate_ReadReg(MI2Cx,REG_SR1,&Loc_StatusRegister);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR1,START);
		break;
	}
	default:
	Loc_error=NOK;
		break;
	}
	return Loc_error;
}
uint16 MI2C_errorstate_ReadReg(MI2C_Register* MI2Cx,uint8 copy_Reg,uint16 *PRegVal)
{

	volatile uint32 Loc_regVal=0;
	Loc_regVal=(uint32) MI2Cx;
	Loc_regVal+=copy_Reg;
	*PRegVal=(*(volatile uint16*)Loc_regVal);
	return *PRegVal;
}
void MI2C_errorstate_Stop_Condition(MI2C_Register* MI2Cx,uint8 copy_uint8stopstate)
{
	switch(copy_uint8stopstate)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR1,STOP);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR1,STOP);
		break;
	}
	default:
		break;
	}
}
ErrorState MI2C_errorstate_Set_ACK(MI2C_Register* MI2Cx,uint8 copy_uint8AckState)
{
	ErrorState Loc_error=OK;
	switch(copy_uint8AckState)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR1,ACK);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR1,ACK);
		break;
	}
	default:
		break;
	}
	return Loc_error;
}

ErrorState MI2C_errorstate_Confg_Clk_Stretch(MI2C_Register* MI2Cx,uint8 copy_uint8Clkstate)
{
	ErrorState Loc_error=OK;
	switch(copy_uint8Clkstate)
	{
	case ENABLE:
	{
		CLR_BIT(MI2Cx->CR1,NOSTRETCH);
		break;
	}
	case DISABLE:
	{
		SET_BIT(MI2Cx->CR1,NOSTRETCH);
		break;
	}
	default:
		Loc_error=NOK;
		break;
	}
	return Loc_error;
}
ErrorState MI2C_errorstate_Set_GenCall(MI2C_Register* MI2Cx,uint8 copy_uint8GENstate)
{
	ErrorState Loc_error=OK;
	switch(copy_uint8GENstate)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR1,ENGC);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR1,ENGC);
		break;
	}
	default:
		Loc_error=NOK;
		break;
	}
	return Loc_error;
}

void MI2C_VidConfguration(MI2C_Confg *PI2C_Confg,uint8 copy_uint8Mode,uint16 copy_uint16NodeAdd)
{
	/*Reset All Parameters*/
	PI2C_Confg->MI2C_ClockSpeed=10000;
	PI2C_Confg->MI2C_Mode=MI2C_MODE_I2C;
	PI2C_Confg->MI2C_DutyCycle=MI2C_DUTY_CYCLE_2;
	PI2C_Confg->MI2C_OWN_Address1=copy_uint16NodeAdd;
	/*Set ACK*/
	if(copy_uint8Mode==MI2C_SLAVE)
	{
		PI2C_Confg->MI2C_Ack=ENABLE;
		PI2C_Confg->MI2C_Interrupts=ENABLE;
	}
	else if(copy_uint8Mode==MI2C_MASTER)
	{
	PI2C_Confg->MI2C_Ack=DISABLE;
	}
	else
	{
		/*Do Nothing*/
	}
	PI2C_Confg->MI2C_AddressLength=MI2C_ADDRESS_7BIT;
	PI2C_Confg->MI2C_Gen_Call=DISABLE;
	PI2C_Confg->MI2C_Initial_State=ENABLE;
}

void MI2C_VidTransmitData(MI2C_Register* MI2Cx,uint8 copy_uint8Data)
{
	uint16 Loc_StatusRegVal=0;
	while(GET_BIT(MI2Cx->SR1,TXE)==0);
	MI2C_errorstate_ReadReg(MI2Cx,REG_SR1,&Loc_StatusRegVal);
	MI2Cx->DR=copy_uint8Data;
}
uint8 MI2C_uint8_ReceiveData(MI2C_Register* MI2Cx)
{
	uint16 Loc_StatusRegVal=0;
	uint8 Loc_ReceiveVal=0;
	while(GET_BIT(MI2Cx->SR1,RXNE)==0);
	Loc_ReceiveVal=(uint8)MI2Cx->DR;
	MI2C_errorstate_ReadReg(MI2Cx,REG_SR1,&Loc_StatusRegVal);
	return Loc_ReceiveVal;
}

ErrorState MI2C_errorstate_Confg_Interrupts(MI2C_Register* MI2Cx,MI2C_State* copy_State)
{
	ErrorState Loc_error=0;
	switch(copy_State->MI2C_BuffState)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR2,ITBUFEN);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR2,ITBUFEN);
		break;
	}
	default:
		break;
	}
	switch(copy_State->MI2C_EventState)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR2,ITEVTEN);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR2,ITEVTEN);
		break;
	}
	default:
		break;
	}
	switch(copy_State->MI2C_ErrorState)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR2,ITERREN);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR2,ITERREN);
		break;
	}
	default:
		Loc_error=NOK;
		break;
	}
	return Loc_error;
}
static ErrorState MI2C_SetClkSetting(MI2C_Register* MI2Cx,uint32 copy_ClkSpeed,uint16 copy_DutyCycle)
{
	ErrorState Loc_error=OK;
	uint16 Loc_Freq=0,Loc_Result=0;
	uint32 Loc_APB1Freq=0;
	/*Set APB1 BUS*/
	/*Reset Freq Bit by mask other bits*/
	MI2Cx->CR2 &=0xFFC0;
	MRCC_VidGetAPB1_Freq(&Loc_APB1Freq);
	Loc_Freq=(uint16)Loc_APB1Freq/1000000;
	/*Config Freq bits*/
	MI2Cx->CR2 |=Loc_Freq;
	/*Disable peripheral*/
	CLR_BIT(MI2Cx->CR1,PE);
	if(copy_ClkSpeed<=MI2C_STANDARD_SM_MAX)
	{
		/*duty cycle un used*/
		copy_DutyCycle=0;
		/*configure TRISE with Max SCL Rasie*/
		MI2Cx->TRISE=Loc_Freq+1;
		/*Sm Calculation
		 * t high = Tlow = CCR * TPCLK1*/
		Loc_Result=(uint16)(Loc_APB1Freq/(copy_ClkSpeed));
		/*Check Result for Allowed CCR*/
		if(Loc_Result<MI2C_MINALLOWED_CCR_SM)
		{
			/*Minmum CCR Value */
			Loc_Result=MI2C_MINALLOWED_CCR_SM;
		}
	}
	else
	{
		/*config Max Raise Time for FM*/
		MI2Cx->TRISE=(uint16)((Loc_Freq*(uint16)300)/(uint16)1000+(uint16)1);
		if(copy_DutyCycle==MI2C_DUTY_CYCLE_2)
		{
			/*T(L)/T(H)=2*/
			Loc_Result=(uint16)(Loc_APB1Freq/(copy_ClkSpeed*3));
		}
		else if(copy_DutyCycle==MI2C_DUTY_CYCLE_16_9)
		{
			/*T(L)/T(H)=16/9*/
			Loc_Result=(uint16)(Loc_APB1Freq/(copy_ClkSpeed*25));
			Loc_Result |= MI2C_DUTY_CYCLE_16_9;
		}
		else
		{
			Loc_error=NOK;
		}
		if(Loc_Result<MI2C_MINALLOWED_CCR_FM)
		{
			Loc_Result |=MI2C_MINALLOWED_CCR_FM;
		}
		/*CCR F/S set*/
		Loc_Result |=(uint16)0x8000;
	}
	/*Set CCR Result*/
	MI2Cx->CCR=Loc_Result;
	return Loc_error;
}
static void MI2C_SetMode(MI2C_Register* MI2Cx,uint16 copy_Mode)
{
	MI2Cx->CR1 |=copy_Mode;
}
static void MI2C_SetAdd1(MI2C_Register* MI2Cx,uint16 copy_add1,uint16 copy_addLength)
{
	/*Mask Address mode*/
	MI2Cx->OAR1 &=0xFF01;
	switch(copy_add1)
	{
	case MI2C_ADDRESS_7BIT:
	{
		MI2Cx->OAR1 |=(copy_add1<<1) |copy_addLength;
		break;
	}
	case MI2C_ADDRESS_10BIT:
	{
		MI2Cx->OAR1 |= copy_add1 | copy_addLength;
		break;
	}
	default:
		break;
	}
}
static void MI2C_SetAdd2(MI2C_Register* MI2Cx,uint16 copy_add2,uint16 copy_dulaMode)
{
	if(copy_dulaMode==MI2C_DUAL_ADDRESS_ENABLE)
	{
		MI2Cx->OAR2 |= (copy_add2<<1)| copy_dulaMode;
	}
}
static ErrorState MI2C_ConfigDMA(MI2C_Register* MI2Cx,uint8 copy_DMA_State)
{
	ErrorState Loc_error=OK;
	switch(copy_DMA_State)
	{
	case ENABLE:
	{
		SET_BIT(MI2Cx->CR2,DMAEN);
		break;
	}
	case DISABLE:
	{
		CLR_BIT(MI2Cx->CR2,DMAEN);
	}
	default:
		Loc_error=NOK;
		break;
	}
	return Loc_error;
}

void MI2C_VidSend_7BIT_Address(MI2C_Register* MI2Cx,uint8 copy_address,uint8 copy_direction)
{
	uint16 Loc_RegVal=0;
	if(copy_direction!=MI2C_DIRECTION_TRANSMITTER)
	{
		/*Set address for read*/
		copy_address |= (uint16)0x0001;
	}
	else
	{
		/*Reset*/
		copy_address &=(uint16)0xFFFE;
	}
	MI2Cx->DR=copy_address;
	while(GET_BIT(MI2Cx->SR1,ADDR)!=1);
	MI2C_errorstate_ReadReg(MI2Cx,REG_SR1,&Loc_RegVal);
	MI2C_errorstate_ReadReg(MI2Cx,REG_SR2,&Loc_RegVal);
}
void MI2C_VidSalve_Transmit(MI2C_Register* MI2Cx,uint8 *Pdata,uint8 copy_size)
{
	uint8 Loc_Index=0;
	MI2C_SetMode(MI2Cx,ENABLE);
	MI2C_errorstate_Start_Condition(MI2Cx,ENABLE);
	/*Send data*/
	for(Loc_Index=0;Loc_Index<copy_size;Loc_Index++)
	{
		MI2C_VidTransmitData(MI2Cx,Pdata[Loc_Index]);
	}
	/*stop bit*/
	MI2C_errorstate_Stop_Condition(MI2Cx,ENABLE);
}
void MI2C_VidSalve_Read(MI2C_Register* MI2Cx,uint8 *Pdata,uint8 copy_size)
{
	uint8 Loc_Index=0;
	MI2C_SetMode(MI2Cx,ENABLE);
	MI2C_errorstate_Start_Condition(MI2Cx,ENABLE);
	/*Send data*/
	for(Loc_Index=0;Loc_Index<copy_size;Loc_Index++)
	{
		Pdata[Loc_Index]=MI2C_uint8_ReceiveData(MI2Cx);
	}
	/*stop bit*/
	MI2C_errorstate_Stop_Condition(MI2Cx,ENABLE);
}
void MI2C_VidMaster_Transmit(MI2C_Register* MI2Cx,uint16 copy_slvadd,uint8 *Pdata,uint8 copy_size)
{
	uint8 Loc_Index=0;
	MI2C_SetMode(MI2Cx,ENABLE);
	MI2C_errorstate_Start_Condition(MI2Cx,ENABLE);
	MI2C_VidSend_7BIT_Address(MI2Cx,copy_slvadd,MI2C_DIRECTION_TRANSMITTER);
	/*Send data*/
	for(Loc_Index=0;Loc_Index<copy_size;Loc_Index++)
	{
		MI2C_VidTransmitData(MI2Cx,Pdata[Loc_Index]);
	}
	/*stop bit*/
	MI2C_errorstate_Stop_Condition(MI2Cx,ENABLE);
}
void MI2C_VidMaster_Read(MI2C_Register* MI2Cx,uint16 copy_slvadd,uint8 *Pdata,uint8 copy_size)
{
	{
		uint8 Loc_Index=0;
		MI2C_SetMode(MI2Cx,ENABLE);
		MI2C_errorstate_Start_Condition(MI2Cx,ENABLE);
		MI2C_VidSend_7BIT_Address(MI2Cx,copy_slvadd,MI2C_DIRECTION_TRANSMITTER);
		/*Send data*/
		for(Loc_Index=0;Loc_Index<copy_size;Loc_Index++)
		{
			Pdata[Loc_Index]=MI2C_uint8_ReceiveData(MI2Cx);
		}
		/*stop bit*/
		MI2C_errorstate_Stop_Condition(MI2Cx,ENABLE);
	}
}
