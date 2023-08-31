/**
 * @file EXTI_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*UTILES LIB*/
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/*EXTI*/
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static Ptr_to_func_t EXTI_INT0_PCallback = NULL;
static Ptr_to_func_t EXTI_INT1_PCallback = NULL;
static Ptr_to_func_t EXTI_INT2_PCallback = NULL;
/**
 * @brief: Function to enable the desired external interrupt
 * 
 * @param InterruptSource: The source of the external interrupt
 * @param InterruptTrigger: The mode of the external interrupt "The event which triggers the interrupt"
 */
void EXTI_Enable    (EXTI_Source_t InterruptSource, EXTI_Trigger_t InterruptTrigger)
{
    if(InterruptSource >= EXTI_INT0 && InterruptSource <= EXTI_INT2)
    {
        if(InterruptTrigger >= EXTI_RISING_EDGE && InterruptTrigger <= EXTI_ANY_LOGICAL_CHANGE)
        {
            switch(InterruptSource)
            {
                case EXTI_INT0:
                {
                    if(EXTI_RISING_EDGE == InterruptTrigger)
                    {
                        SET_BIT(MCUCR, ISC00);
                        SET_BIT(MCUCR, ISC01);
                    }
                    else if(EXTI_FALLING_EDGE == InterruptTrigger)
                    {
                        CLEAR_BIT(MCUCR, ISC00);
                        SET_BIT(MCUCR, ISC01);
                    }
                    else if(EXTI_LOW_LEVEL == InterruptTrigger)
                    {
                        CLEAR_BIT(MCUCR, ISC00);
                        CLEAR_BIT(MCUCR, ISC00);
                    }
                    else if(EXTI_ANY_LOGICAL_CHANGE == InterruptTrigger)
                    {
                        SET_BIT(MCUCR, ISC00);
                        CLEAR_BIT(MCUCR, ISC01);
                    }
                    SET_BIT(GICR, INT0); //Last step
                    break;
                }
                case EXTI_INT1:
                {
                    if(EXTI_RISING_EDGE == InterruptTrigger)
                    {
                        SET_BIT(MCUCR, ISC10);
                        SET_BIT(MCUCR, ISC11);
                    }
                    else if(EXTI_FALLING_EDGE == InterruptTrigger)
                    {
                        CLEAR_BIT(MCUCR, ISC10);
                        SET_BIT(MCUCR, ISC11);
                    }
                    else if(EXTI_LOW_LEVEL == InterruptTrigger)
                    {
                        CLEAR_BIT(MCUCR, ISC10);
                        CLEAR_BIT(MCUCR, ISC11);
                    }
                    else if(EXTI_ANY_LOGICAL_CHANGE == InterruptTrigger)
                    {
                        SET_BIT(MCUCR, ISC10);
                        CLEAR_BIT(MCUCR, ISC11);
                    }
                    SET_BIT(GICR, INT1); //Last step
                    break;
                }
                case EXTI_INT2:
                {
                    if(EXTI_RISING_EDGE == InterruptTrigger)
                    {
                        SET_BIT(MCUCSR, ISC2);
                    }
                    else if(EXTI_FALLING_EDGE == InterruptTrigger)
                    {
                        CLEAR_BIT(MCUCR, ISC2);
                    }
                    SET_BIT(GICR, INT2); //Last step
                    break;
                }
                default:
                {
                    break;
                }                                
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
/**
 * @brief: Function to disable the desired external interrupt
 * 
 * @param InterruptSource: External Interrupt to be disabled
 */
void EXTI_Disable   (EXTI_Source_t InterruptSource)
{
    if(InterruptSource >= EXTI_INT0 && InterruptSource <= EXTI_INT2)
    {
        switch(InterruptSource)
        {
            case EXTI_INT0:
            {
                CLEAR_BIT(GICR, INT0);
                break;
            }
            case EXTI_INT1:
            {
                CLEAR_BIT(GICR, INT1);
                break;
            }
            case EXTI_INT2:
            {
                CLEAR_BIT(GICR, INT2);
                break;
            }
            default:
            {
                /*Do nothing*/
                break;
            }
        }
    }
    else
    {
        /*Do nothing*/
    }
}

/**
 * @brief: Function to set the callback function of External Interrupt 0
 *
 * @param EXTI_INT0Callback: The callback function
 */
void EXTI_INT0_SetCallback(Ptr_to_func_t EXTI_INT0Callback)
{
    if(EXTI_INT0Callback != NULL)
    {
        EXTI_INT0_PCallback = EXTI_INT0Callback;
    }
    else
    {
        /*Do nothing*/
    }
}
/**
 * @brief: Function to set the callback function of External Interrupt 1
 *
 * @param EXTI_INT1Callback: The callback function
 */
void EXTI_INT1_SetCallback(Ptr_to_func_t EXTI_INT1Callback)
{
    if(EXTI_INT1Callback != NULL)
    {
        EXTI_INT1_PCallback = EXTI_INT1Callback;
    }
    else
    {
        /*Do nothing*/
    }
}
/**
 * @brief: Function to set the callback function of External Interrupt 2
 *
 * @param EXTI_INT2Callback: The callback function
 */
void EXTI_INT2_SetCallback(Ptr_to_func_t EXTI_INT2Callback)
{
    if(EXTI_INT2Callback != NULL)
    {
        EXTI_INT2_PCallback = EXTI_INT2Callback;
    }
    else
    {
        /*Do nothing*/
    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void) //(vector number of the external interrupt 0) - 1
{
    if(EXTI_INT0_PCallback != NULL)
    {
	    EXTI_INT0_PCallback();
    }
    else
    {
        /*Do nothing*/
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void) //(vector number of the external interrupt 1) - 1
{
    if(EXTI_INT1_PCallback != NULL)
    {
	    EXTI_INT1_PCallback();
    }
    else
    {
        /*Do nothing*/
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void) //(vector number of the external interrupt 2) - 1
{
    if(EXTI_INT2_PCallback != NULL)
    {
	    EXTI_INT2_PCallback();
    }
    else
    {
        /*Do nothing*/
    }
}