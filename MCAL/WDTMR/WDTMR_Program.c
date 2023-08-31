/**
 * @file WDTMR_Program.c
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDTMR_Interface.h"
#include "WDTMR_Private.h"
#include "WDTMR_Config.h"

/**
 * @brief: Function to start the watchdog timer
 * 
 */
void WDTMR_Start(void)
{
    #if WDTMR_PRESCALAR_SELECT == WDTMR_16K_PRESCALE
        //Set time = 16.3 ms
        CLEAR_BIT(WDTCR, WDP0);
        CLEAR_BIT(WDTCR, WDP1);
        CLEAR_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_32K_PRESCALE
        //Set time = 32.5 ms
        SET_BIT(WDTCR, WDP0);
        CLEAR_BIT(WDTCR, WDP1);
        CLEAR_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_64K_PRESCALE
        //Set time = 65 ms
        CLEAR_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        CLEAR_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_128K_PRESCALE
        //Set time = 0.13 s
        SET_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        CLEAR_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_256K_PRESCALE
        //Set time = 0.26 s
        CLEAR_BIT(WDTCR, WDP0);
        CLEAR_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_512K_PRESCALE
        //Set time = 0.52 s
        SET_BIT(WDTCR, WDP0);
        CLEAR_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_1024K_PRESCALE
        //Set time = 1 s
        CLEAR_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
    #elif WDTMR_PRESCALAR_SELECT == WDTMR_2048K_PRESCALE
        //Set time = 2.1 s
        SET_BIT(WDTCR, WDP0);
        SET_BIT(WDTCR, WDP1);
        SET_BIT(WDTCR, WDP2);
    #endif

    //Enable Watchdog Timer
    SET_BIT(WDTCR, WDE);
}
/**
 * @brief: Function to stop the watchdog timer
 * 
 */
void WDTMR_Stop(void)
{
    //This line must be performed in one line
    //This line is used to allow me to stop the watchdog timer
    WDTCR = (1 << WDE) | (1 << WDTOE);
    /*Stop the watchdog timer*/
    WDTCR = 0x00;
}