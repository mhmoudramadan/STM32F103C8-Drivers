/*
 * HBUTTON_Interface.h
 *
 *  Created on: May 12, 2022 12:16:11 PM PUSH_BUTTON_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef HAL_HBUTTON_HBUTTON_INTERFACE_H_
#define HAL_HBUTTON_HBUTTON_INTERFACE_H_

/*struct to handle Push buttons*/
typedef struct
{
	MGPIO_PortID Button_PortID;
	MGPIO_PinNum Button_PinNum;
	uint8 Button_Active_State;
}Button_t;
/*Button Pull options*/
#define INTERNAL_PULL_UP     0
#define EXTERNAL_PULL_UP     1
#define INTERNAL_PULL_DOWN   2
#define EXTERNAL_PULL_DOWN   3

void HBUTTON_VidInit(Button_t* copy_Button);
ErrorState HBUTTON_ErrorState_Button_Pressed(Button_t* copy_Button);


#endif /* HAL_HBUTTON_HBUTTON_INTERFACE_H_ */
