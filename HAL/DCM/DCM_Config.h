/**
 * @file DCM_Config.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef DCM_CONFIG_H_
#define DCM_CONFIG_H_

#include "DCM_Private.h"

#define DCM_ONE_EN_PORT_ID              DIO_PORTD
#define DCM_ONE_EN_PIN_ID               DIO_PIN4

#define DCM_ONE_A1_PORT_ID              DIO_PORTC
#define DCM_ONE_A1_PIN_ID               DIO_PIN3

#define DCM_ONE_A2_PORT_ID              DIO_PORTC
#define DCM_ONE_A2_PIN_ID               DIO_PIN4

#define DCM_TWO_EN_PORT_ID              DIO_PORTD
#define DCM_TWO_EN_PIN_ID               DIO_PIN5

#define DCM_TWO_A3_PORT_ID              DIO_PORTC
#define DCM_TWO_A3_PIN_ID               DIO_PIN5

#define DCM_TWO_A4_PORT_ID              DIO_PORTC
#define DCM_TWO_A4_PIN_ID               DIO_PIN6

/*
        DCM Control timer
1) DCM_TIMER0
2) DCM_TIMER1
3) DCM_TIMER2
*/
#define DCM_CONTOL_SPEED_TIMER          DCM_TIMER0
#endif /*DCM_CONFIG_H_*/