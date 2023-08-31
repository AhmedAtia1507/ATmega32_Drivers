/**
 * @file SPI_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * @version 1.0
 * @date 2022-12-13
 * 
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"

Ptr_to_func_t SPI_PCallback = NULL;

/**
 * @brief: Function to initialize the SPI Peripheral
 * 
 */
void SPI_Init(void)
{
    #if SPI_ROLE == SPI_MASTER
        //Master Mode Select
        SET_BIT(SPCR, MSTR);
    #elif SPI_ROLE == SPI_SLAVE
        //Slave Mode Select
        CLEAR_BIT(SPCR, MSTR);
    #endif

    #if SPI_INTERRUPT_STATUS == SPI_INTERRUPT_ENABLED
        //SPI Interrupt Enabled
        SET_BIT(SPCR, SPIE);
    #elif SPI_INTERRUPT_STATUS == SPI_INTERRUPT_DISABLED
        //SPI Interrupt Disabled
        CLEAR_BIT(SPCR, SPIE);
    #endif

    #if SPI_DATA_SENT_ORDER == SPI_DATA_LSB_FIRST
        //Data Least-Significant bit is sent first
        SET_BIT(SPCR, DORD);
    #elif SPI_DATA_SENT_ORDER == SPI_DATA_MSB_FIRST
        //Data Most-Significant bit is sent first
        CLEAR_BIT(SPCR, DORD);
    #endif

    #if SPI_CLOCK_POLARITY == SPI_CLOCK_RISING_EDGE_LEADING_FALLING_EDGE_TRAILING
        CLEAR_BIT(SPCR, CPOL);
    #elif SPI_CLOCK_POLARITY == SPI_CLOCK_FALLING_EDGE_LEADING_RISING_EDGE_TRAILING
        SET_BIT(SPCR, CPOL);
    #endif

    #if SPI_CLOCK_PHASE == SPI_SAMPLE_AT_LEADING_EDGE_SETUP_AT_TRAILING_EDGE
        CLEAR_BIT(SPCR, CPHA);
    #elif SPI_CLOCK_PHASE == SPI_SAMPLE_AT_TRAILING_EDGE_SETUP_AT_LEADING_EDGE
        SET_BIT(SPCR, CPHA);
    #endif

    #if SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_2
        CLEAR_BIT(SPCR, SPR0);
        CLEAR_BIT(SPCR, SPR1);
        SET_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_4
        CLEAR_BIT(SPCR, SPR0);
        CLEAR_BIT(SPCR, SPR1);
        CLEAR_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_8
        SET_BIT(SPCR, SPR0);
        CLEAR_BIT(SPCR, SPR1);
        SET_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_16
        SET_BIT(SPCR, SPR0);
        CLEAR_BIT(SPCR, SPR1);
        CLEAR_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_32
        CLEAR_BIT(SPCR, SPR0);
        SET_BIT(SPCR, SPR1);
        SET_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_64
        SET_BIT(SPCR, SPR0);
        SET_BIT(SPCR, SPR1);
        SET_BIT(SPCR, SPI2X);
    #elif SPI_CLOCK_PRESCALAR == SPI_PRESCALAR_DIVIDE_BY_128
        SET_BIT(SPCR, SPR0);
        SET_BIT(SPCR, SPR1);
        CLEAR_BIT(SPCR, SPI2X);
    #endif
    //SPI Enable
    SET_BIT(SPCR, SPE);
}

/**
 * @brief: Function to transmit/receive a value
 * 
 * @param Copy_u8TransmittedValue: The value to be transmitted
 * @param P_u8ReceivedValue: Received value
 */
void SPI_Transciever(u8 Copy_u8TransmittedValue, u8* P_u8ReceivedValue)
{
    if(P_u8ReceivedValue != NULL)
    {
        SPDR = Copy_u8TransmittedValue;
        while(GET_BIT(SPSR,SPIF) == 0);
        *P_u8ReceivedValue = SPDR; 
    }
    else
    {
        /*Do nothing*/
    }
}
/**
 * @brief: Function to set the interrupt function of SPI Peripheral
 * 
 * @param P_funcSPICallback: The interrupt function
 */
void SPI_SetCallback(Ptr_to_func_t P_funcSPICallback)
{
    if(P_funcSPICallback != NULL)
    {
        SPI_PCallback = P_funcSPICallback;
    }
    else
    {
        /*Do nothing*/
    }
}

//ISR Function prototype for SPI
void __vector_12(void) __attribute__ ((signal));
void __vector_12(void)
{
    if (SPI_PCallback != NULL)
    {
        SPI_PCallback();
    }
    else
    {
        /*Do nothing*/
    }
}