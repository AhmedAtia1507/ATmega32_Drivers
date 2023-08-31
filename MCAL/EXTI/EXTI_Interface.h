/**
 * @file EXTI_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Enum for interrupt sources*/
typedef enum
{
    EXTI_INT0, //Port D Pin 2 
    EXTI_INT1, //Port D Pin 3
    EXTI_INT2 // Port B Pin 2
}EXTI_Source_t;

/*Enum for Interrupt Trigger Edge*/
typedef enum
{
    EXTI_RISING_EDGE,
    EXTI_FALLING_EDGE,
    EXTI_LOW_LEVEL,
    EXTI_ANY_LOGICAL_CHANGE
}EXTI_Trigger_t;

typedef void (*Ptr_to_func_t)(void);
/**
 * @brief: Function to enable the desired external interrupt
 * 
 * @param InterruptSource: The source of the external interrupt
 * @param InterruptTrigger: The mode of the external interrupt "The event which triggers the interrupt"
 */
void EXTI_Enable    (EXTI_Source_t InterruptSource, EXTI_Trigger_t InterruptTrigger);
/**
 * @brief: Function to disable the desired external interrupt
 * 
 * @param InterruptSource: External Interrupt to be disabled
 */
void EXTI_Disable   (EXTI_Source_t InterruptSource);
/**
 * @brief: Function to set the callback function of External Interrupt 0
 *
 * @param EXTI_INT0Callback: The callback function
 */
void EXTI_INT0_SetCallback(Ptr_to_func_t EXTI_INT0Callback);
/**
 * @brief: Function to set the callback function of External Interrupt 1
 *
 * @param EXTI_INT1Callback: The callback function
 */
void EXTI_INT1_SetCallback(Ptr_to_func_t EXTI_INT1Callback);
/**
 * @brief: Function to set the callback function of External Interrupt 2
 *
 * @param EXTI_INT2Callback: The callback function
 */
void EXTI_INT2_SetCallback(Ptr_to_func_t EXTI_INT2Callback);
#endif /*EXTI_INTERFACE_H_*/