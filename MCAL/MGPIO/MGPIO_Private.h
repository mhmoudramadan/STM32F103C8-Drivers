/*
 * MGPIO_Private.h
 *
 *  Created on: May 11, 2022 12:36:41 AM GPIO_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_
/*Base Address for Ports
 * 1-PORTA--> 0x40010800
 * 2-PORTB--> 0x40010C00
 * 3-PORTC--> 0x40011000  */
/*GPIO Register offest
 * 1-GPIOx_CRL  -->0x00
 * 2-GPIOx_CRH  -->0x04
 * 3-GPIOx_IDR  -->0x08
 * 4-GPIOx_ODR  -->0x0C
 * 5-GPIOx_BSRR  -->0x10
 * 6-GPIOx__BRR  -->0x14
 * 7-GPIOx_LCKR  -->0x18 */
	/*Port Register address*/
#define GPIOA_CRL		*((volatile uint32*)0x40010800)
#define GPIOA_CRH		*((volatile uint32*)0x40010804)
#define GPIOA_IDR		*((volatile uint32*)0x40010808)
#define GPIOA_ODR		*((volatile uint32*)0x4001080C)
#define GPIOA_BSRR		*((volatile uint32*)0x40010810)
#define GPIOA_BRR		*((volatile uint32*)0x40010814)
#define GPIOA_LCKR		*((volatile uint32*)0x40010818)

#define GPIOB_CRL		*((volatile uint32*)0x40010C00)
#define GPIOB_CRH		*((volatile uint32*)0x40010C04)
#define GPIOB_IDR		*((volatile uint32*)0x40010C08)
#define GPIOB_ODR		*((volatile uint32*)0x40010C0C)
#define GPIOB_BSRR		*((volatile uint32*)0x40010C10)
#define GPIOB_BRR		*((volatile uint32*)0x40010C14)
#define GPIOB_LCKR		*((volatile uint32*)0x40010C18)

#define GPIOC_CRL		*((volatile uint32*)0x40011000)
#define GPIOC_CRH		*((volatile uint32*)0x40011004)
#define GPIOC_IDR		*((volatile uint32*)0x40011008)
#define GPIOC_ODR		*((volatile uint32*)0x4001100C)
#define GPIOC_BSRR		*((volatile uint32*)0x40011010)
#define GPIOC_BRR		*((volatile uint32*)0x40011014)
#define GPIOC_LCKR		*((volatile uint32*)0x40011018)

#define CLR_VAL  15
#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
