/**
 * @file DCM_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define DCM_ONE                             1
#define DCM_TWO                             2
/**
 * @brief: Function to initialize the DC motor peripheral by using H-Bridge
 * 
 * @param Copy_u8MotorSelection: variable to choose which DC motor to initialize
 */
void DCM_Init(u8 Copy_u8MotorSelection);

#define DCM_MOVE_CLOCKWISE_DIRECTION        1
#define DCM_MOVE_ANTI_CLOCKWISE_DIRECTION   2
/**
 * @brief: Function to start the DC motor in the designated direction
 * 
 * @param Copy_u8MotorSelection: DC motor Select
 * @param Copy_u8MotorDirection: DC motor movement direction
 */
void DCM_On(u8 Copy_u8MotorSelection, u8 Copy_u8MotorDirection);
/**
 * @brief: Function to stop the DC motor
 * 
 * @param Copy_u8MotorSelection: DC motor Select
 */
void DCM_Off(u8 Copy_u8MotorSelection);
/**
 * @brief: Function to control the speed of DC motor
 * 
 * @param Copy_u8MotorSelection: DC motor Select
 * @param Copy_u8MotorSpeedPercentage: Speed of DC motor as a percentage of the total speed 
 */
void DCM_ControlSpeed(u8 Copy_u8MotorSelection, u8 Copy_u8MotorSpeedPercentage);
#endif /*DCM_INTERFACE_H_*/