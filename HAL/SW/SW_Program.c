/**
 * @file SW_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2023-02-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"

#include "SW_Interface.h"

/**
 * @brief: Function for checking for the status of a switch
 * @warning: You have to set the direction of the pin the switch is connected to as input first
 * 
 * @param Copy_u8PortID: The ID of the port the switch is connected to 
 * @param Copy_u8PinID: The ID of the pin the switch is connected to
 * @param P_u8SWStatus: The status of the switch (pressed or not pressed)
 */
void SW_GetStatus       (u8 Copy_u8PortID, u8 Copy_u8PinID, u8* P_u8SWStatus)
{
    if(P_u8SWStatus != NULL)
    {
        if(Copy_u8PortID >= DIO_PORTA && Copy_u8PortID <= DIO_PORTD)
        {
            if(Copy_u8PinID >= DIO_PIN0 && Copy_u8PinID <= DIO_PIN7)
            {
                u8 Loc_u8SWStatus = 7;
                DIO_ReadPinValue(Copy_u8PortID, Copy_u8PinID, &Loc_u8SWStatus);
                if(SW_PRESSED == Loc_u8SWStatus || SW_NOT_PRESSED == Loc_u8SWStatus)
                {
                    *P_u8SWStatus = Loc_u8SWStatus;
                } 
                else
                {
                    *P_u8SWStatus = SW_NOT_PRESSED;
                }
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
    else
    {
        /*Do nothing*/
    }
}