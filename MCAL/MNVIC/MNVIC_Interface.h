/*
 * MNVIC_Interface.h
 *
 *  Created on: May 11, 2022 5:48:51 AM NVIC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_

/*Eternal Interrupt 0:59*/
typedef enum
{
	WWDG_IRQ=0,
	PVD_IRQ,
	TAMPER_IRQ,
	RTC_IRQ,
	FLASH_IRQ,
	RCC_IRQ,
	EXTI0_IRQ,
	EXTI1_IRQ,
	EXTI2_IRQ,
	EXTI3_IRQ,
	EXTI4_IRQ,
	DMA1_CH1_IRQ,
	DMA1_CH2_IRQ,
	DMA1_CH3_IRQ,
	DMA1_CH4_IRQ,
	DMA1_CH5_IRQ,
	DMA1_CH6_IRQ,
	DMA1_CH7_IRQ,
	ADC1_2_IRQ,
	USB_HPCAN_TX_IRQ,
	USB_LPCAN_TX_IRQ,
	CAN_RX1_IRQ,
	CAN_SCE_IRQ,
	EXTI9_5_IRQ,
	TIM1_BRK_TIM9_IRQ,
	TIM1_UP_TIM10_IRQ,
	TIM1_TRG_COM_TIM11_IRQ,
	TIM1_CC_IRQ,
	TIM2_IRQ,
	TIM3_IRQ,
	TIM4_IRQ,
	I2C1_EV_IRQ,
	I2C1_ER_IRQ,
	I2C2_EV_IRQ,
	I2C2_ER_IRQ,
	SPI1_IRQ,
	SPI2_IRQ,
	USART1_IRQ,
	USART2_IRQ,
	USART3_IRQ,
	EXTI15_10_IRQ,
	RTC_ALARM_IRQ,
	USB_WKUP_IRQ,
	TIM8_BRK_TIM12_IRQ,
	TIM8_UP_TIM13_IRQ,
	TIM8TRG_COM_TIM14_IRQ,
	TIM8_CC_IRQ,
	ADC3_IRQ,
	FSMC_IRQ,
	SDIO_IRQ,
	TIM5_IRQ,
	SPI3_IRQ,
	UART4_IRQ,
	UART5_IRQ,
	TIM6_IRQ,
	TIM7_IRQ,
	DMA2_CH1_IRQ,
	DMA2_CH2_IRQ,
	DMA2_CH3_IRQ,
	DMA2_CH4_5_IRQ,

}MNVIC_IRQn;

/*NVIC APIS*/
/*Initialize*/
void MNVIC_VidInit(void);
/*Set Enable Specific external interrupt*/
void MNVIC_VidSetEnableIRQ(MNVIC_IRQn copy_IRQn);
/*Clear Enable Specific external interrupt*/
void MNVIC_VidDisableEnableIRQ(MNVIC_IRQn copy_IRQn);
/*Set Pending*/
void MNVIC_VidSetPending(MNVIC_IRQn copy_IRQn);
/*Get Pending*/
uint8 MNVIC_uint8GetPending(MNVIC_IRQn copy_IRQn);
/*Clear Pending*/
void MNVIC_VidClearPending(MNVIC_IRQn copy_IRQn);
/*Get Active*/
uint8 MNVIC_uint8GetActive(MNVIC_IRQn copy_IRQn);
/*Set Priority*/
void MNVIC_VidSetPriority(MNVIC_IRQn copy_IRQn,uint8 copy_uint8Priority);


#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
