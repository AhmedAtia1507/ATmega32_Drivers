/**
 * @file TWI_Program.c
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

#include "TWI_Config.h"
#include "TWI_Interface.h"
#include "TWI_Private.h"

/**
 * @brief: Function to initialize the TWI peripheral in Master node
 * 
 */
void TWI_InitMaster(void)
{
    //freq = 400KHz //Set Prescalar = 1
    CLEAR_BIT(TWSR, 0);
    CLEAR_BIT(TWSR, 1);
    TWBR = 12;

    //Enable Acknowledge Bit
    SET_BIT(TWCR, 6);

    //Enable TWI
    SET_BIT(TWCR,2);
}
//void TWI_InitSlave(void);
/**
 * @brief: Function to send the start condition in TWI frame
 * 
 */
void TWI_SendStartCondition(void)
{
    //Send Start Condition
    SET_BIT(TWCR,5);

    //Clear flag to start current operation
    SET_BIT(TWCR, TWINT);

    //Blocking until the operation is done 
    //"Flag is set automatically when operation is done"
    while(0 == GET_BIT(TWCR, TWINT));

    //check acknowledge = start condition positive acknowledge  
    //"Block at negative acknowledge"
    while((TWSR & 0xF8) != TWI_START_COND_POSITIVE_ACK);
    ///Try using error states instead of blocking the entire system
}
/**
 * @brief: Function to send the repeated start condition in TWI frame
 * 
 */
void TWI_SendRepeatedStartCondition(void)
{
    //Send Start Condition
    SET_BIT(TWCR,5);

    //Clear flag to start current operation
    SET_BIT(TWCR, TWINT);

    //Blocking until the operation is done 
    //"Flag is set automatically when operation is done"
    while(0 == GET_BIT(TWCR, TWINT));

    //check acknowledge = Repeated start condition positive acknowledge  
    //"Block at negative acknowledge"
    while((TWSR & 0xF8) != TWI_REPEATED_START_COND_POSITIVE_ACK);
    ///Try using error states instead of blocking the entire system  
}
/**
 * @brief: Function to send the stop condition in TWI frame
 * 
 */
void TWI_SendStopCondition(void)
{
    //Send Stop Condition
    SET_BIT(TWCR, 4);

    //Clear flag to start current operation
    SET_BIT(TWCR, TWINT);
}
/**
 * @brief: Function to send the slave address with write operation
 * 
 * @param Copy_u8SlaveAddress: Slave address
 */
void TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    //We send the slave address by putting the address in the data register not the slave address register
    if(Copy_u8SlaveAddress >= 0 && Copy_u8SlaveAddress <= TWI_MAX_SLAVE_ADDRESS)
    {
        //Send Slave Address
        TWDR = Copy_u8SlaveAddress << 1;

        //Send Write Operation
        CLEAR_BIT(TWDR, 0);

        //Clear Start Condition Bit
        CLEAR_BIT(TWCR, TWSTA);

        //Clear flag to start current operation
        SET_BIT(TWCR, TWINT);

        //Blocking until the operation is done 
        //"Flag is set automatically when operation is done"
        while(0 == GET_BIT(TWCR, TWINT));

        //check acknowledge = Slave address with write operation positive acknowledge  
        //"Block at negative acknowledge"
        while((TWSR & 0xF8) != TWI_SLAVE_ADDRESS_WITH_WRITE_POSITIVE_ACK);
        ///Try using error states instead of blocking the entire system     
    }
    else
    {
        /*Do nothing*/
    }
}
/**
 * @brief: Function to send the slave address with read operation
 * 
 * @param Copy_u8SlaveAddress: Slave address
 */
void TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
    //We send the slave address by putting the address in the data register not the slave address register
    if(Copy_u8SlaveAddress >= 0 && Copy_u8SlaveAddress <= TWI_MAX_SLAVE_ADDRESS)
    {
        //Send Slave Address
        TWDR = Copy_u8SlaveAddress << 1;

        //Send Read Operation
        SET_BIT(TWDR, 0);

        //Clear Start Condition Bit
        CLEAR_BIT(TWCR, TWSTA);

        //Clear flag to start current operation
        SET_BIT(TWCR, TWINT);

        //Blocking until the operation is done 
        //"Flag is set automatically when operation is done"
        while(0 == GET_BIT(TWCR, TWINT));

        //check acknowledge = Slave address with read operation positive acknowledge  
        //"Block at negative acknowledge"
        while((TWSR & 0xF8) != TWI_SLAVE_ADDRESS_WITH_READ_POSITIVE_ACK);
        ///Try using error states instead of blocking the entire system     
    }
    else
    {
        /*Do nothing*/
    }
}
/**
 * @brief: Function to send a byte of data
 * 
 * @param Copy_u8DataByte: Data byte to be sent
 */
void TWI_SendMasterDataByte(u8 Copy_u8DataByte)
{
    //Write Data in the data register
    TWDR = Copy_u8DataByte;

    //Clear flag to start current operation
    SET_BIT(TWCR, TWINT);

    //Blocking until the operation is done 
    //"Flag is set automatically when operation is done"
    while(0 == GET_BIT(TWCR, TWINT));

    //check acknowledge = send data byte positive acknowledge  
    //"Block at negative acknowledge"
    while((TWSR & 0xF8) != TWI_SEND_MASTER_DATA_BYTE_POSITIVE_ACK);
    ///Try using error states instead of blocking the entire system
}
/**
 * @brief: Function to receive a byte from a slave
 * 
 * @param P_u8ReturnedData: Received data
 */
void TWI_ReceiveMasterDataByte(u8* P_u8ReturnedData)
{
    if(P_u8ReturnedData != NULL)
    {
        //Clear flag to start current operation
        SET_BIT(TWCR, TWINT);

        //Blocking until the operation is done 
        //"Flag is set automatically when operation is done"
        while(0 == GET_BIT(TWCR, TWINT));

        //check acknowledge = Receive data byte positive acknowledge  
        //"Block at negative acknowledge"
        while((TWSR & 0xF8) != TWI_RECEIVE_MASTER_DATA_BYTE_POSITIVE_ACK);
        ///Try using error states instead of blocking the entire system

        *P_u8ReturnedData = TWDR;    
    }
    else
    {
        /*Do nothing*/
    }
}