/*
 * MADC_Config.h
 *
 *  Created on: May 16, 2022 3:20:36 AM 
 *  Topic-->ADC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

typedef enum
{
	ENABLE_ADC,
	DISABLE_ADC
}MADC_State;
typedef enum
{
	RIGHT_ALIGNEMENT,
	LEFT_ALIGNEMENT
}MADC_Alignement;
typedef enum
{
	ENABLE_CALIBRATION,

}MADC_Calibration;
typedef struct
{
	MADC_State ADC_State;
	MADC_Alignement Data_Align;
	MADC_Calibration Calibration_State;
}MADC_Configurations;


static MADC_Configurations Static_ADC_Configuration[3]=
{
		{ENABLE_ADC,RIGHT_ALIGNEMENT,ENABLE_CALIBRATION},
		{DISABLE_ADC,RIGHT_ALIGNEMENT,ENABLE_CALIBRATION},
		{DISABLE_ADC,LEFT_ALIGNEMENT,ENABLE_CALIBRATION}
};

#endif /* MCAL_MADC_MADC_CONFIG_H_ */
