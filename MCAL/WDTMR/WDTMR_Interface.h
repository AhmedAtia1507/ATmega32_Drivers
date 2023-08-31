/**
 * @file WDTMR_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WDTMR_INTERFACE_H_
#define WDTMR_INTERFACE_H_

/**
 * @brief: Function to start the watchdog timer
 * 
 */
void WDTMR_Start(void);
/**
 * @brief: Function to stop the watchdog timer
 * 
 */
void WDTMR_Stop(void);
#endif /*WDTMR_INTERFACE_H_*/