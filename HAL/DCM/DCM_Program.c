/**
 * @file DCM_Program.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Interface.h"
#include "TMR_Interface.h"

#include "DCM_Interface.h"
#include "DCM_Config.h"
#include "DCM_Private.h"
/**
 * @brief: Function to initialize the DC motor peripheral by using H-Bridge
 * 
 * @param Copy_u8MotorSelection: variable to choose which DC motor to initialize
 */
void DCM_Init(u8 Copy_u8MotorSelection)
{
    switch(Copy_u8MotorSelection)
    {
        case DCM_ONE:
        {
            DIO_SetPinDirection(DCM_ONE_EN_PORT_ID, DCM_ONE_EN_PIN_ID, DIO_PIN_OUTPUT);
            DIO_SetPinDirection(DCM_ONE_A1_PORT_ID, DCM_ONE_A1_PIN_ID, DIO_PIN_OUTPUT);
            DIO_SetPinDirection(DCM_ONE_A2_PORT_ID, DCM_ONE_A2_PIN_ID, DIO_PIN_OUTPUT);

            DIO_SetPinValue(DCM_ONE_EN_PORT_ID, DCM_ONE_EN_PIN_ID, DIO_PIN_HIGH);
            
            break;
        }
        case DCM_TWO:
        {
            DIO_SetPinDirection(DCM_TWO_EN_PORT_ID, DCM_TWO_EN_PIN_ID, DIO_PIN_OUTPUT);
            DIO_SetPinDirection(DCM_TWO_A3_PORT_ID, DCM_TWO_A3_PIN_ID, DIO_PIN_OUTPUT);
            DIO_SetPinDirection(DCM_TWO_A4_PORT_ID, DCM_TWO_A4_PIN_ID, DIO_PIN_OUTPUT);

            DIO_SetPinValue(DCM_TWO_EN_PORT_ID, DCM_TWO_EN_PIN_ID, DIO_PIN_HIGH);
            break;
        }
        default:
        {
            /*Do nothing*/
        }
    }
}

/**
 * @brief: Function to start the DC motor in the designated direction
 * 
 * @param Copy_u8MotorSelection: DC motor Select
 * @param Copy_u8MotorDirection: DC motor movement direction
 */
void DCM_On(u8 Copy_u8MotorSelection, u8 Copy_u8MotorDirection)
{
    switch(Copy_u8MotorSelection)
    {
        case DCM_ONE:
        {
            if(DCM_MOVE_CLOCKWISE_DIRECTION == Copy_u8MotorDirection)
            {
                DIO_SetPinValue(DCM_ONE_A1_PORT_ID, DCM_ONE_A1_PIN_ID, DIO_PIN_HIGH);
                DIO_SetPinValue(DCM_ONE_A2_PORT_ID, DCM_ONE_A2_PIN_ID, DIO_PIN_LOW);               
            }
            else if(DCM_MOVE_ANTI_CLOCKWISE_DIRECTION == Copy_u8MotorDirection)
            {
                DIO_SetPinValue(DCM_ONE_A1_PORT_ID, DCM_ONE_A1_PIN_ID, DIO_PIN_LOW);
                DIO_SetPinValue(DCM_ONE_A2_PORT_ID, DCM_ONE_A2_PIN_ID, DIO_PIN_HIGH);
            }
            else
            {
                /*Do nothing*/
            }
            break;
        }
        case DCM_TWO:
        {
            if(DCM_MOVE_CLOCKWISE_DIRECTION == Copy_u8MotorDirection)
            {
                DIO_SetPinValue(DCM_TWO_A3_PORT_ID, DCM_TWO_A3_PIN_ID, DIO_PIN_HIGH);
                DIO_SetPinValue(DCM_TWO_A4_PORT_ID, DCM_TWO_A4_PIN_ID, DIO_PIN_LOW);
            }
            else if(DCM_MOVE_ANTI_CLOCKWISE_DIRECTION == Copy_u8MotorDirection)
            {

                DIO_SetPinValue(DCM_TWO_A3_PORT_ID, DCM_TWO_A3_PIN_ID, DIO_PIN_LOW);
                DIO_SetPinValue(DCM_TWO_A4_PORT_ID, DCM_TWO_A4_PIN_ID, DIO_PIN_HIGH);
            }
            else
            {
                /*Do nothing*/
            }
            break;
        }
        default:
        {
            /*Do nothing*/
        }
    }
}
/**
 * @brief: Function to stop the DC motor
 * 
 * @param Copy_u8MotorSelection: DC motor Select
 */
void DCM_Off(u8 Copy_u8MotorSelection)
{
    switch(Copy_u8MotorSelection)
    {
        case DCM_ONE:
        {
            DIO_SetPinValue(DCM_ONE_A1_PORT_ID, DCM_ONE_A1_PIN_ID, DIO_PIN_LOW);
            DIO_SetPinValue(DCM_ONE_A2_PORT_ID, DCM_ONE_A2_PIN_ID, DIO_PIN_LOW);
            break;
        }
        case DCM_TWO:
        {
            DIO_SetPinValue(DCM_TWO_A3_PORT_ID, DCM_TWO_A3_PIN_ID, DIO_PIN_LOW);
            DIO_SetPinValue(DCM_TWO_A4_PORT_ID, DCM_TWO_A4_PIN_ID, DIO_PIN_LOW);
            break;
        }
        default:
        {
            /*Do nothing*/
        }
    }
}
/**
 * @brief: Function to control the speed of DC motor
 * @warning: You have to initialize the timer peripheral before calling this function and connect the OC pin of the
 *      timer to the VCC Pin of the H-Bridge
 * @param Copy_u8MotorSelection: DC motor Select
 * @param Copy_u8MotorSpeedPercentage: Speed of DC motor as a percentage of the total speed 
 */
void DCM_ControlSpeed(u8 Copy_u8MotorSelection, u8 Copy_u8MotorSpeedPercentage)
{
    switch(Copy_u8MotorSelection)
    {
        case DCM_ONE:
        {
            #if DCM_TIMER0 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer0Set_PWM_DutyCycle(Copy_u8MotorSpeedPercentage);
            #elif DCM_TIMER1 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer1SetPWMDutyCycle(Copy_u8MotorSpeedPercentage);
            #elif DCM_TIMER2 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer2Set_PWM_DutyCycle(Copy_u8MotorSpeedPercentage);
            #else
                /*Do nothing*/
            #endif
            break;
        }
        case DCM_TWO:
        {
            #if DCM_TIMER0 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer0Set_PWM_DutyCycle(Copy_u8MotorSpeedPercentage);
            #elif DCM_TIMER1 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer1SetPWMDutyCycle(Copy_u8MotorSpeedPercentage);
            #elif DCM_TIMER2 == DCM_CONTOL_SPEED_TIMER
                TMR_Timer2Set_PWM_DutyCycle(Copy_u8MotorSpeedPercentage);
            #else
                /*Do nothing*/
            #endif
            break;
        }
        default:
        {
            /*Do nothing*/
        }
    }
}