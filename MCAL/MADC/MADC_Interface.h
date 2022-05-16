/*
 * MADC_Interface.h
 *
 *  Created on: May 16, 2022 3:20:28 AM 
 *  Topic-->ADC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MADC_MADC_INTERFACE_H_
#define MCAL_MADC_MADC_INTERFACE_H_

typedef enum
{
	ADC1,
	ADC2,
	ADC3,
	NUM_OF_ADC_PERIPHERALON_MC
}MADC_Peripheral;
typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	CH_8,
	CH_9,
	CH_10,
	CH_11,
	CH_12,
	CH_13,
	CH_14,
	CH_15,
	CH_16,
	CH_17
}MADC_Channel;

typedef enum
{
	ADC_SINGLE_CONVERSION,
	ADC_CONTINOUS_CONVERSION,
	ADC_SCAN_SINGLE_CONVERSION,
	ADC_SCAN_CONTINOUS_CONVERSION,
	ADC_DIS_COUNTINOUS_CONVERSION
}MADC_Conversion;

typedef enum
{
	ADC_1_ORDER=0,
	ADC_2_ORDER=5,
	ADC_3_ORDER=10,
	ADC_4_ORDER=15,
	ADC_5_ORDER=20,
	ADC_6_ORDER=25,
	ADC_7_ORDER=0,
	ADC_8_ORDER=5,
	ADC_9_ORDER=10,
	ADC_TEN_ORDER=15,
	ADC_11_ORDER=20,
	ADC_12_ORDER=25,
	ADC_13_ORDER=0,
	ADC_14_ORDER=5,
	ADC_15_ORDER=10,
	ADC_16_ORDER=15
}MADC_Channel_ORDER;

typedef enum
{
	CONVERSION_1,
	CONVERSION_2,
	CONVERSION_3,
	CONVERSION_4,
	CONVERSION_5,
	CONVERSION_6,
	CONVERSION_7,
	CONVERSION_8,
	CONVERSION_9,
	CONVERSION_10,
	CONVERSION_11,
	CONVERSION_12,
	CONVERSION_13,
	CONVERSION_14,
	CONVERSION_15,
	CONVERSION_16
}MADC_Channel_Length;

typedef enum
{
	ADC_1_5_CYCLE,
	ADC_7_5_CYCLE,
	ADC_13_5_CYCLE,
	ADC_28_5_CYCLE,
	ADC_41_5_CYCLE,
	ADC_55_5_CYCLE,
	ADC_71_5_CYCLE,
	ADC_239_5_CYCLE
}MADC_SampleTime;
/*ProtoTypes*/
void MADC_VidInit(void);
void MADC_VidSet_ConversionMode(MADC_Peripheral copy_PreNum,MADC_Conversion copy_Mode,uint8 copy_uint8ConversionNum);
void MADC_VidSet_RegularTime(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_ORDER copy_ChOrder);
void MADC_VidSet_SampleTime(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_SampleTime copy_SampleTime);
void MADC_uint16Read_ResultBlock(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_Length copy_ChLength,uint16 *Puint16Result);
void MADC_uint16Read_ResultNonBlock(MADC_Peripheral copy_PreNum,MADC_Channel copy_Ch,MADC_Channel_Length copy_ChLength,uint16 *Puint16Result);
void MADC_VidRead_Result_Asynchrouns(MADC_Peripheral copy_PreNum,void(*PtrToFun)(void));
#endif /* MCAL_MADC_MADC_INTERFACE_H_ */
