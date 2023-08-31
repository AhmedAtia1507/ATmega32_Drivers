/**
 * @file WDTMR_Config.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WDTMR_CONFIG_H_
#define WDTMR_CONFIG_H_

#include "WDTMR_Private.h"
/*
        Watchdog Timer time choices
1) WDTMR_16K_PRESCALE           //time = 16.3ms
2) WDTMR_32K_PRESCALE           //time = 32.5ms
3) WDTMR_64K_PRESCALE           //time = 65ms
4) WDTMR_128K_PRESCALE          //time = 0.13s
5) WDTMR_256K_PRESCALE          //time = 0.26s
6) WDTMR_512K_PRESCALE          //time = 0.52s
7) WDTMR_1024K_PRESCALE         //time = 1s
8) WDTMR_2048K_PRESCALE         //time = 2.1s
*/
#define WDTMR_PRESCALAR_SELECT          WDTMR_1024K_PRESCALE    
#endif /*WDTMR_CONFIG_H_*/