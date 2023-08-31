/**
 * @file EEPROM_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TWI_Interface.h"

#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"

#define F_CPU       16000000
#include <util/delay.h>

/**
 * @brief: Function to write a byte in the designated address in EEPROM
 * 
 * @param Copy_u16ByteAddress: Address in which the data will be written 
 * @param Copy_u8DataByte: Data byte to be written
 */
void EEPROM_WriteByte(u16 Copy_u16ByteAddress, u8 Copy_u8DataByte)
{
    if(Copy_u16ByteAddress >= 0 && Copy_u16ByteAddress <= 2047)
    {
        u8 Loc_u8Address = (u8)(EEPROM_FIXED_ADDRESS | (u8)(Copy_u16ByteAddress >> 8));

        //Send Start Condition
        TWI_SendStartCondition();

        //Send Slave Address With write operation
        TWI_SendSlaveAddressWithWrite(Loc_u8Address);

        //Send Byte Address
        TWI_SendMasterDataByte((u8)Copy_u16ByteAddress);

        //Send byte data
        TWI_SendMasterDataByte(Copy_u8DataByte);

        //Send Stop Condition
        TWI_SendStopCondition();

        //Delay until write cycle finishes
        _delay_ms(5);
    }
    else
    {
        /*Do nothing*/
    }
}

/**
 * @brief: Function to read a byte in the designated address in EEPROM
 * 
 * @param Copy_u16ByteAddress: Address in which the data is stored
 * @param P_u8DataByte: Data Byte to be read 
 */
void EEPROM_ReadByte(u16 Copy_u16ByteAddress, u8* P_u8DataByte)
{
    if(P_u8DataByte != NULL)
    {
        if(Copy_u16ByteAddress >= 0 && Copy_u16ByteAddress <= 2047)
        {
            u8 Loc_u8Address = (u8)(EEPROM_FIXED_ADDRESS | (u8)(Copy_u16ByteAddress >> 8));

            //Send Start Condition
            TWI_SendStartCondition();

            //Send Slave Address With write operation
            TWI_SendSlaveAddressWithWrite(Loc_u8Address);

            //Send Byte Address
            TWI_SendMasterDataByte((u8)Copy_u16ByteAddress);

            //Send Repeated Start Condition
            TWI_SendRepeatedStartCondition();

            //Send Slave Address With read operation
            TWI_SendSlaveAddressWithRead(Loc_u8Address);

            //Read Data Byte
            TWI_ReceiveMasterDataByte(P_u8DataByte);

            //Send Stop Condition
            TWI_SendStopCondition();

            _delay_ms(5);                
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }    
}