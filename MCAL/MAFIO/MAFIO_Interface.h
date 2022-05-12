/*
 * MAFIO_Interface.h
 *
 *  Created on: May 12, 2022 9:49:30 AM AFIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MAFIO_MAFIO_INTERFACE_H_
#define MCAL_MAFIO_MAFIO_INTERFACE_H_

#define LINE_4BIT   4
/*To get offest*/
#define EXTI_LSH_BIT 4
/*Clear Line Bits 8*/
#define EXTI_CLEAR_LINE  0xf
/*Alternate Function I/O*/
void MAFIO_VidSelectPort_Line_Configuration(uint8 copy_uint8Line,uint8 copy_uint8PortID);

#endif /* MCAL_MAFIO_MAFIO_INTERFACE_H_ */
