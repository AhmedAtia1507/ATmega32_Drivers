/**
 * @file SSD_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#define F_CPU   16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

#include "DIO_Interface.h"
#include "SSD_Interface.h"
#include "SSD_Config.h"

void SSD_Init(void)
{
    DIO_SetPinDirection(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_OUTPUT); //EN2
	DIO_SetPinDirection(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_OUTPUT); //EN1
	DIO_SetPinDirection(SSD_PID_PORT_ID, SSD_PID_PIN_ID, DIO_PIN_OUTPUT); //DIP
	DIO_SetPinDirection(SSD_DATA_PORT_ID, SSD_DATA_PIN1_ID, DIO_PIN_OUTPUT); //A
	DIO_SetPinDirection(SSD_DATA_PORT_ID, SSD_DATA_PIN2_ID, DIO_PIN_OUTPUT); //B
	DIO_SetPinDirection(SSD_DATA_PORT_ID, SSD_DATA_PIN3_ID, DIO_PIN_OUTPUT); //C
	DIO_SetPinDirection(SSD_DATA_PORT_ID, SSD_DATA_PIN4_ID, DIO_PIN_OUTPUT); //D
}

void SSD_DisplayNumber(u8 Copy_u8ssdID, u8 Copy_u8Number)
{
    if(Copy_u8Number >= 0 && Copy_u8Number <= 9)
    {
        switch(Copy_u8ssdID)
        {
            case SSD_ONE:
            {
                /*Enable SSD one*/
	    		DIO_SetPinValue(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_LOW);
                DIO_SetPinValue(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_HIGH);
                break;
            }
            case SSD_TWO:
            {
                /*Enable SSD two*/
	    		DIO_SetPinValue(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_LOW);			
                DIO_SetPinValue(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_HIGH);
                break;
            }
            default:
            {
                /*Do nothing*/
                break;
            }
        }

        DIO_WriteHalfPort(SSD_DATA_PORT_ID, SSD_DATA_PIN1_ID, Copy_u8Number);
    }
    else
    {
        /*Do nothing*/
    }
}

void SSD_DisplayMultiNumber (u8 Copy_u8Number)
{
    if(Copy_u8Number >= 0 && Copy_u8Number <= 99)
    {
        DIO_SetPinValue(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_LOW);
        DIO_SetPinValue(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_LOW);

        DIO_WriteHalfPort(SSD_DATA_PORT_ID, SSD_DATA_PIN1_ID, Copy_u8Number / 10);
        DIO_SetPinValue(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_HIGH);
        _delay_ms(10);

        DIO_SetPinValue(SSD_ENABLE1_PORT_ID, SSD_ENABLE1_PIN_ID, DIO_PIN_LOW);
        DIO_WriteHalfPort(SSD_DATA_PORT_ID, SSD_DATA_PIN1_ID, Copy_u8Number % 10);
        DIO_SetPinValue(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_HIGH);
        _delay_ms(10); 
        DIO_SetPinValue(SSD_ENABLE2_PORT_ID, SSD_ENABLE2_PIN_ID, DIO_PIN_LOW);              
    }
    else
    {

    }
}