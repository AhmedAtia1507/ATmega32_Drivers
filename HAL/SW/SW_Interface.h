/**
 * @file SW_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2023-02-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_PRESSED      DIO_PIN_HIGH
#define SW_NOT_PRESSED  DIO_PIN_LOW
/**
 * @brief: Function for checking for the status of a switch
 * @warning: You have to set the direction of the pin the switch is connected to as input first
 * 
 * @param Copy_u8PortID: The ID of the port the switch is connected to 
 * @param Copy_u8PinID: The ID of the pin the switch is connected to
 * @param P_u8SWStatus: The status of the switch (pressed or not pressed)
 */
void SW_GetStatus       (u8 Copy_u8PortID, u8 Copy_u8PinID, u8* P_u8SWStatus);
#endif /*SW_INTERFACE_H_*/