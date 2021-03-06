/*
 * MRCC_Config.h
 *
 *  Created on: May 10, 2022 3:59:11 AM RCC_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_

/*Clock System option
 * 1-RCC_HSE_CRYSTAL
 * 2-RCC_HSE_RC
 * 3-RCC_HSI
 * 4-RCC_PLL
 * */
#define SYSTEM_CLOCK  RCC_HSE_CRYSTAL

/*Clock security option
 * 1-ENABLE
 * 2-DISABLE*/
#define CSS_ON  DISABLE

/*option for PLL source
 * 1-RCC_PLL_HSI_SOURCE_BY2
 * 2-RCC_PLL_HSE_SOURCE
 * 3-RCC_PLL_HSE_SOURCE_BY2
 */
#define RCC_PLL_SOURCE  RCC_PLL_HSE_SOURCE

/*Option for PLL MULTIPLEIER
 * *2:*16
 * */
#define RCC_PLL_MUL  2

/*HSI STEP CORRECTION
 * -16:15*/
#define RCC_HSI_CORRECTION   0

/*option for MCO PIN source
 * 1-NO_SOUCRE
 * 2-HSE_SOURCE
 * 3-HSI_SOURCE
 * 4-PLL_SOURCE
 * 5-SYSTME_SOURCE*/
#define RCC_MCO_PIN  NO_SOUCRE

/*RCC_ADC PRESCALER Option
 * 1-RCC_PRESCALER_2
 * 2-RCC_PRESCALER_4
 * 3-RCC_PRESCALER_6
 * 4-RCC_PRESCALER_8
 * */
#define RCC_ADC_PRESCALER  RCC_PRESCALER_2

/*RCC_APB1 PRESCALER Option
 * 1-RCC_PPRE1_PRESCALER_0
 * 2-RCC_PPRE1_PRESCALER_2
 * 3-RCC_PPRE1_PRESCALER_4
 * 4-RCC_PPRE1_PRESCALER_8
 * 5-RCC_PPRE1_PRESCALER_16*/
#define RCC_APB1_PRESCALER  RCC_PPRE1_PRESCALER_0

/*RCC_APB2 PRESCALER Option
 * 1-RCC_PPRE2_PRESCALER_0
 * 2-RCC_PPRE2_PRESCALER_2
 * 3-RCC_PPRE2_PRESCALER_4
 * 4-RCC_PPRE2_PRESCALER_8
 * 5-RCC_PPRE2_PRESCALER_16
 * APB1 Must Not Exceed 36MHZ*/
#define RCC_APB2_PRESCALER  RCC_PPRE2_PRESCALER_0

/*RCC_AHB PRESCALER Option
 * 1-RCC_HPRE_PRESCALER_0
 * 2-RCC_HPRE_PRESCALER_2
 * 3-RCC_HPRE_PRESCALER_4
 * 4-RCC_HPRE_PRESCALER_8
 * 5-RCC_HPRE_PRESCALER_16
 * 5-RCC_HPRE_PRESCALER_64
 * 5-RCC_HPRE_PRESCALER_128
 * 5-RCC_HPRE_PRESCALER_256
 * 5-RCC_HPRE_PRESCALER_512
 * */
#define RCC_AHB_PRESCALER  RCC_HPRE_PRESCALER_0

#define SYS_FREQ		8000000
#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
