/*
 * MSTK_Private.h
 *
 *  Created on: May 15, 2022 4:59:02 AM 
 *  Topic-->STK_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSTK_MSTK_PRIVATE_H_
#define MCAL_MSTK_MSTK_PRIVATE_H_

/*STK Register Mapping*/
typedef struct
{
	/*STK Control & status Register*/
	volatile uint32 CTRL;
	/*STK Reload ValueRegister*/
	volatile uint32	LOAD;
	/*STK Current Value Register*/
	volatile uint32 VAL;
	/*STK calibration valueRegister*/
	volatile uint32 CALIB;
}MSTK;
/*Base Address*/
#define STK ((volatile MSTK*)0xE000E010)

/*Register Bit definitions*/
#define CTRL_ENABLE			0
#define CTRL_TICKINT		1
#define CTRL_CLKSOURCE		2
#define CTRL_COUNTFLAG		16
/*Clock Source*/
#define AHP_SOURCE			0
#define AHB_BY_8_SOURCE		1
#define ENABLE		1
#define DISABLE		0
#endif /* MCAL_MSTK_MSTK_PRIVATE_H_ */
