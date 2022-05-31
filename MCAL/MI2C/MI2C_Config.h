/*
 * MI2C_Config.h
 *
 *  Created on: May 26, 2022 1:15:36 PM 
 *  Topic-->I2C_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MI2C_MI2C_CONFIG_H_
#define MCAL_MI2C_MI2C_CONFIG_H_

/*I2C Pins Map*/
typedef struct
{
	MGPIO_PortID MI2C_Port;
	uint8 MI2C_Pin;
}MI2C_Pin;


#define MI2C_SCL		0
#define MI2C_SDA		1
#define MI2C_SCL_PORT	PORTB
#define MI2C_SCL_PIN   	PIN6
#define MI2C_SDA_PORT   PORTB
#define MI2C_SDA_PIN    PIN5
MI2C_Pin MI2C_Pins[2]=
{
		{MI2C_SCL_PORT,MI2C_SCL_PIN},
		{MI2C_SDA_PORT,MI2C_SDA_PIN}		};


#endif /* MCAL_MI2C_MI2C_CONFIG_H_ */
