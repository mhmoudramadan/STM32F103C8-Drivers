/*
 * MSPI_Config.h
 *
 *  Created on: May 16, 2022 6:00:05 AM 
 *  Topic-->SPI_DRIVER_PRO
 *      Author: mahmoud ramadan
 */

#ifndef MCAL_MSPI_MSPI_CONFIG_H_
#define MCAL_MSPI_MSPI_CONFIG_H_

#define SPI_MAC_CHANNEL_ON_MC		2
#define SPI_MASTER_MODE		1
#define SPI_SALVE_MODE		0
/*Option For MC peripheral
 * 1-SPI1_MODE
 * -SPI_MASTER_MODE
 * -SPI_SLAVE_MODE
 *
 * 2-SPI2_MODE
 * -SPI_MASTER_MODE
 * -SPI_SLAVE_MODE*/
#define SPI1_MODE	SPI_MASTER_MODE
#define SPI2_MODE	SPI_SLAVE_MODE
#endif /* MCAL_MSPI_MSPI_CONFIG_H_ */
