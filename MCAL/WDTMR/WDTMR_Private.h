/**
 * @file WDTMR_Private.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 *  
 * @version 1.0
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef WDTMR_PRIVATE_H_
#define WDTMR_PRIVATE_H_

/*WDTCR bit names*/
/*Watchdog Timer Prescaler 0*/
#define WDP0                        0
/*Watchdog Timer Prescaler 1*/
#define WDP1                        1
/*Watchdog Timer Prescaler 2*/
#define WDP2                        2   
/*Watchdog Enable*/
#define WDE                         3
/*Watchdog Turn-off Enable*/
#define WDTOE                       4

/*Watchdog Timer time choices*/
#define WDTMR_16K_PRESCALE          1 //time = 16.3ms
#define WDTMR_32K_PRESCALE          2 //time = 32.5ms
#define WDTMR_64K_PRESCALE          3 //time = 65ms
#define WDTMR_128K_PRESCALE         4 //time = 0.13s
#define WDTMR_256K_PRESCALE         5 //time = 0.26s
#define WDTMR_512K_PRESCALE         6 //time = 0.52s
#define WDTMR_1024K_PRESCALE        7 //time = 1s
#define WDTMR_2048K_PRESCALE        8 //time = 2.1s

#endif /*WDTMR_PRIVATE_H_*/