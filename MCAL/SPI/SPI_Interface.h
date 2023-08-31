/**
 * @file SPI_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * @version 1.0
 * @date 2022-12-13
 * 
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/**
 * @brief: Function to initialize the SPI Peripheral
 * 
 */
void SPI_Init(void);

typedef void (*Ptr_to_func_t)(void);
/**
 * @brief: Function to set the interrupt function of SPI Peripheral
 * 
 * @param P_funcSPICallback: The interrupt function
 */
void SPI_SetCallback(Ptr_to_func_t P_funcSPICallback);
/**
 * @brief: Function to transmit/receive a value
 * 
 * @param Copy_u8TransmittedValue: The value to be transmitted
 * @param P_u8ReceivedValue: Received value
 */
void SPI_Transciever(u8 Copy_u8TransmittedValue, u8* P_u8ReceivedValue);
#endif /*SPI_INTERFACE_H_*/