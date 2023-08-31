/**
 * @file EEPROM_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

/**
 * @brief: Function to write a byte in the designated address in EEPROM
 * 
 * @param Copy_u16ByteAddress: Address in which the data will be written 
 * @param Copy_u8DataByte: Data byte to be written
 */
void EEPROM_WriteByte(u16 Copy_u16ByteAddress, u8 Copy_u8DataByte);
/**
 * @brief: Function to read a byte in the designated address in EEPROM
 * 
 * @param Copy_u16ByteAddress: Address in which the data is stored
 * @param P_u8DataByte: Data Byte to be read 
 */
void EEPROM_ReadByte(u16 Copy_u16ByteAddress, u8* P_u8DataByte);
#endif /*EEPROM_INTERFACE_H_*/