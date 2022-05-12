/*
 * HLED_Interface.h
 *
 *  Created on: May 12, 2022 11:06:10 AM LED_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef HAL_HLED_HLED_INTERFACE_H_
#define HAL_HLED_HLED_INTERFACE_H_
/*Struct to Hold led Port*/
typedef struct
{
	MGPIO_PortID Led_PortID;
	MGPIO_PinNum Led_PinNum;
}LED_t;
/*Led state*/
typedef enum
{
	ON,
	OFF
}LED_State;
/*Led options*/
#define ACTIVE_HIGH  1
#define ACTIVE_LOW   0
/*initialize Led*/
void HLED_VidInit(LED_t copy_LedConfig);
/*Set State*/
void HLED_VidSet_State(LED_t copy_LedConfig,LED_State copy_LedState);
/*Toggle Led*/
void HLED_VidToggleLed(LED_t copy_LedConfig);

#endif /* HAL_HLED_HLED_INTERFACE_H_ */
