/**
 * @file TWI_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

/**
 * @brief: Function to initialize the TWI peripheral in Master node
 * 
 */
void TWI_InitMaster                     (void);
//void TWI_InitSlave(void);
/**
 * @brief: Function to send the start condition in TWI frame
 * 
 */
void TWI_SendStartCondition             (void);
/**
 * @brief: Function to send the repeated start condition in TWI frame
 * 
 */
void TWI_SendRepeatedStartCondition     (void);
/**
 * @brief: Function to send the stop condition in TWI frame
 * 
 */
void TWI_SendStopCondition              (void);
/**
 * @brief: Function to send the slave address with write operation
 * 
 * @param Copy_u8SlaveAddress: Slave address
 */
void TWI_SendSlaveAddressWithWrite      (u8 Copy_u8SlaveAddress);
/**
 * @brief: Function to send the slave address with read operation
 * 
 * @param Copy_u8SlaveAddress: Slave address
 */
void TWI_SendSlaveAddressWithRead       (u8 Copy_u8SlaveAddress);
/**
 * @brief: Function to send a byte of data
 * 
 * @param Copy_u8DataByte: Data byte to be sent
 */
void TWI_SendMasterDataByte             (u8 Copy_u8DataByte);
/**
 * @brief: Function to receive a byte from a slave
 * 
 * @param P_u8ReturnedData: Received data
 */
void TWI_ReceiveMasterDataByte          (u8* P_u8ReturnedData);

#endif /*TWI_INTERFACE_H_*/