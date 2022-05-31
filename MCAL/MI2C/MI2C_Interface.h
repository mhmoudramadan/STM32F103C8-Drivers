/*
 * MI2C_Interface.h
 *
 *  Created on: May 26, 2022 1:15:27 PM 
 *  Topic-->I2C_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MI2C_MI2C_INTERFACE_H_
#define MCAL_MI2C_MI2C_INTERFACE_H_

#define MI2C_MASTER		1
#define MI2C_SLAVE		0
/*I2C Configuration*/
typedef struct
{
	/*Value Lower Than 400 KHz*/
	uint32 MI2C_ClockSpeed;
	/*Mode*/
	uint16 MI2C_Mode;
	/*FS Duty cycle*/
	uint16 MI2C_DutyCycle;
	/*7 | 10 address Bits*/
	uint16 MI2C_AddressLength;
	/*first device Own Address*/
	uint16 MI2C_OWN_Address1;
	/*second device Own Address*/
	uint16 MI2C_OWN_Address2;
	/*Dual Add Mode*/
	uint16 MI2C_Dual_AddressMode;
	/*Acknowledge En/Dis*/
	uint8 MI2C_Ack;
	/*General Call*/
	uint8 MI2C_Gen_Call;
	/*DMA Requset*/
	uint8 MI2C_DMA;
	/*I2C Interrupts*/
	uint8 MI2C_Interrupts;
	/*I2C inital State*/
	uint8 MI2C_Initial_State;
}MI2C_Confg;
/*Struct To Define interrupt State*/
typedef struct
{
	/*BERR,ARLO,AF,OVR,TIMEOUT,SMBALERT interrupt state*/
	uint8 MI2C_ErrorState;
	/*SB,ADDR,ADD10,STOPE,BTF,TXE,RXNE State*/
	uint8 MI2C_EventState;
	/*TXE or RXNE state*/
	uint8 MI2C_BuffState;
}MI2C_State;

						/*I2C ProtoTypes*/
ErrorState MI2C_errorstate_Init(MI2C_Register* MI2Cx,MI2C_Confg *PI2C_Config);
ErrorState MI2C_errorstate_SetState(MI2C_Register* MI2Cx,uint8 copy_uint8State);
ErrorState MI2C_errorstate_Start_Condition(MI2C_Register* MI2Cx,uint8 copy_uint8startstate);
ErrorState MI2C_errorstate_ReadReg(MI2C_Register* MI2Cx,uint8 copy_Reg,uint16 *PRegVal);
ErrorState MI2C_errorstate_Set_ACK(MI2C_Register* MI2Cx,uint8 copy_uint8AckState);
ErrorState MI2C_errorstate_Confg_Clk_Stretch(MI2C_Register* MI2Cx,uint8 copy_uint8Clkstate);
ErrorState MI2C_errorstate_Set_GenCall(MI2C_Register* MI2Cx,uint8 copy_uint8GENstate);
void MI2C_VidConfguration(MI2C_Confg *PI2C_Confg,uint8 copy_uint8Mode,uint16 copy_uint16NodeAdd);
void MI2C_errorstate_Stop_Condition(MI2C_Register* MI2Cx,uint8 copy_uint8stopstate);
void MI2C_VidTransmitData(MI2C_Register* MI2Cx,uint8 copy_uint8Data);
uint8 MI2C_uint8_ReceiveData(MI2C_Register* MI2Cx);
ErrorState MI2C_errorstate_Confg_Interrupts(MI2C_Register* MI2Cx,MI2C_State *copy_State);
void MI2C_VidSend_7BIT_Address(MI2C_Register* MI2Cx,uint8 copy_address,uint8 copy_direction);
void MI2C_VidSalve_Read(MI2C_Register* MI2Cx,uint8 *Pdata,uint8 copy_size);
void MI2C_VidSalve_Transmit(MI2C_Register* MI2Cx,uint8 *Pdata,uint8 copy_size);
void MI2C_VidMaster_Transmit(MI2C_Register* MI2Cx,uint16 copy_slvadd,uint8 *Pdata,uint8 copy_size);
void MI2C_VidMaster_Read(MI2C_Register* MI2Cx,uint16 copy_slvadd,uint8 *Pdata,uint8 copy_size);
#endif /* MCAL_MI2C_MI2C_INTERFACE_H_ */
