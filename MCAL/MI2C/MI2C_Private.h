/*
 * MI2C_Private.h
 *
 *  Created on: May 26, 2022 1:15:47 PM 
 *  Topic-->I2C_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MI2C_MI2C_PRIVATE_H_
#define MCAL_MI2C_MI2C_PRIVATE_H_

/*I2C Register mapping*/
typedef struct
{
	volatile uint16 CR1;
	uint16 RESERVED1;
	volatile uint16 CR2;
	uint16 RESERVED2;
	volatile uint16 OAR1;
	uint16 RESERVED3;
	volatile uint16 OAR2;
	uint16 RESERVED4;
	volatile uint16 DR;
	uint16 RESERVED5;
	volatile uint16 SR1;
	uint16 RESERVED6;
	volatile uint16 SR2;
	uint16 RESERVED7;
	volatile uint16 CCR;
	uint16 RESERVED8;
	volatile uint16 TRISE;
	uint16 RESERVED9;
}MI2C_Register;
/*I2C Base Address*/
#define I2C1  ((volatile MI2C_Register)0x40005400)
#define I2C2  ((volatile MI2C_Register)0x40005800)
/*Register Bit Definition*/
/*CR1*/
#define PE			0
#define SMBUS		1
#define SMBTYPE		3
#define ENARP		4
#define ENPEC		5
#define ENGC		6
#define NOSTRETCH	7
#define START		8
#define STOP		9
#define ACK			10
#define POS			11
#define PEC			12
#define ALERT		13
#define SWRST		15
/*CR2*/
#define FREQ		0
#define ITERREN		8
#define ITEVTEN		9
#define ITBUFEN		10
#define DMAEN		11
#define LAST		12
/*OAR2*/
#define ENDUAL		0
#define ADD2  		1
/*SR1*/
#define SB			0
#define ADDR		1
#define BTF			2
#define ADD10		3
#define STOPF		4
#define RXNE		6
#define TXE			7
#define BERR		8
#define ARLO		9
#define AF			10
#define OVR			11
#define PECERR		12
#define TIMEOUT		14
#define SMBALERT	15
/*SR2*/
#define MSL			0
#define BUSY		1
#define TRA			2
#define GENCALL		4
#define SMBDEFAULT	5
#define SMBHOST		6
#define DUALF		7
/*regitser offest*/
#define  REG_CR1                	((uint8)0x00)
#define  REG_CR2               		((uint8)0x04)
#define  REG_OAR1               	((uint8)0x08)
#define  REG_OAR2               	((uint8)0x0C)
#define  REG_DR               		((uint8)0x10)
#define  REG_SR1                	((uint8)0x14)
#define  REG_SR2                	((uint8)0x18)
#define  REG_CCR                	((uint8)0x1C)
#define  REG_TRISE              	((uint8)0x20)

/* I2C duty cycle configuration parameters */
	/* No configuration for standard mode */
#define MI2C_SM_NO_DUTY_CYCLE_CNFG				0
/* I2C fast mode Tlow/Thigh = 16/9 	*/
#define MI2C_DUTY_CYCLE_16_9          		    ((uint16)0x4000)
/* I2C fast mode Tlow/Thigh = 2 	*/
#define MI2C_DUTY_CYCLE_2						((uint16)0xBFFF)

/* I2C modes configuration parameters */
#define MI2C_MODE_I2C                   		((uint16)0x0000)
#define MI2C_MODE_SM_BUS_DEVICE            		((uint16)0x0002)
#define MI2C_MODE_SM_BUS_HOST              		((uint16)0x000A)
/*Speed*/
#define MI2C_STANDARD_SM_MAX					100000
#define MI2C_STANDARD_FM_MAX					400000
#define MI2C_MINALLOWED_CCR_SM					0x04
#define MI2C_MINALLOWED_CCR_FM					0x01
/*Acknowledge option*/
#define MI2C_ACK_ENABLE                  		((uint16)0x0400)
#define MI2C_ACK_DISABLE                	 	((uint16)0xFBFF)
/*Address option*/
#define MI2C_ADDRESS_7BIT    					((uint16)0x4000)
#define MI2C_ADDRESS_10BIT   					((uint16)0xC000)
/*Dual address*/
#define MI2C_DUAL_ADDRESS_DISABLE        		((uint16)0x0000)
#define MI2C_DUAL_ADDRESS_ENABLE         		((uint16)0x0001)
/*Direction option*/
#define MI2C_DIRECTION_TRANSMITTER      		((uint8)0x00)
#define MI2C_DIRECTION_RECEIVER         		((uint8)0x01)

#define DISABLE	0
#define ENABLE	1

/*Private Function*/
static ErrorState MI2C_SetClkSetting(MI2C_Register* MI2Cx,uint32 copy_ClkSpeed,uint16 copy_DutyCycle);
static void MI2C_SetMode(MI2C_Register* MI2Cx,uint16 copy_Mode);
static void MI2C_SetAdd1(MI2C_Register* MI2Cx,uint16 copy_add1,uint16 copy_addLength);
static void MI2C_SetAdd2(MI2C_Register* MI2Cx,uint16 copy_add2,uint16 copy_dulaMode);
static ErrorState MI2C_ConfigDMA(MI2C_Register* MI2Cx,uint8 copy_DMA_State);
#endif /* MCAL_MI2C_MI2C_PRIVATE_H_ */
