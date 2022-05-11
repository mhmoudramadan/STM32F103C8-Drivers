/*
 * MGPIO_Interface.h
 *
 *  Created on: May 11, 2022 12:36:17 AM GPIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_

/*GPIO PORT ID*/
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC
}MGPIO_PortID;
/*GPIO PINS*/
typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}MGPIO_PinNum;
/*Pins to write*/
typedef enum
{
	PINS_2=0x03,
	PINS_3=0x07,
	PINS_4=0x0F,
	PINS_5=0x1F,
	PINS_6=0X3F,
	PINS_7=0x7F,
	PINS_8=0xFF
}MGPIO_PinsToWrite;
/*GPIO MODES*/
typedef enum
{
	/*Input Modes*/
	MGPIO_INPUT_ANALOG_MODE =0b0000,
	MGPIO_INPUT_FLOATING_MODE=0b0100,
	MGPIO_INPUT_PULL_UP_DOWN_MODE=0b1000,
	/*Output Modes for Speed*/
	MGPIO_OUTPUT_10MHZ_PULL_UP_DOWN=0b0001,
	MGPIO_OUTPUT_10MHZ_OPEN_DRAIN=0b0101,
	MGPIO_OUTPUT_10MHZ_AF_PULL_UP_DOWN=0b1001,
	MGPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN=0b1101,

	MGPIO_OUTPUT_2MHZ_PULL_UP_DOWN=0b0010,
	MGPIO_OUTPUT_2MHZ_OPEN_DRAIN=0b0110,
	MGPIO_OUTPUT_2MHZ_AF_PULL_UP_DOWN=0b1010,
	MGPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN=0b1110,

	MGPIO_OUTPUT_50MHZ_PULL_UP_DOWN=0b0011,
	MGPIO_OUTPUT_50MHZ_OPEN_DRAIN=0b0111,
	MGPIO_OUTPUT_50MHZ_AF_PULL_UP_DOWN=0b1011,
	MGPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN=0b1111,
}MGPIO_Modes;
	/*Pin Value*/
#define HIGH    1
#define LOW     0
	/*Pull up _ down*/
#define MGPIO_PULL_UP			1
#define MGPIO_PULL_DOWN			0
	/*GPIO APIS*/
ErrorState MGPIO_ErrorStateSetPinMode(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum, MGPIO_Modes copy_Mode);
ErrorState MGPIO_ErrorStateSetPinValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum, uint8 copy_uint8Value);
ErrorState MGPIO_ErrorStateSetPortMode(MGPIO_PortID copy_PortID, MGPIO_Modes copy_Mode);
ErrorState MGPIO_ErrorStateSetPortValue(MGPIO_PortID copy_PortID, uint16 copy_uint16Value);
uint8 MGPIO_uint8GetPinValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum);
ErrorState MGPIO_ErrorStateWritePinsValue(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum,MGPIO_PinsToWrite copy_Pins,uint8 copy_uint8Value);
ErrorState MGPIO_ErrorStateLockPin(MGPIO_PortID copy_PortID,MGPIO_PinNum copy_PinNum);
#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
