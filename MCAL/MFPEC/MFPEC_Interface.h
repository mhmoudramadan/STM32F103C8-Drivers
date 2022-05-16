/*
 * MFPEC_Interface.h
 *
 *  Created on: May 16, 2022 1:12:42 AM 
 *  Topic-->FPEC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MFPEC_MFPEC_INTERFACE_H_
#define MCAL_MFPEC_MFPEC_INTERFACE_H_

void MFPEC_VidProgrammFlash(uint32 copy_uint32Address,uint16 *Puint16_code,uint8 copy_uint8Length);
uint8 MFPEC_VidProgram_HalfWord_Flash(uint32 copy_uint32Address,uint16 copy_uint16Code);
void MFPEC_VidErase_Page(uint16 copy_uint16Page);
void MFPEC_VidErase_Area(void);
void MFPEC_VidErase_Mass(void );


#endif /* MCAL_MFPEC_MFPEC_INTERFACE_H_ */
