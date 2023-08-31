/**
 * @file EXTI_Private.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*MCUCR bit names*/
#define ISC00       0  /*Interrupt Sense Control 0 bit 0*/
#define ISC01       1  /*Interrupt Sense Control 0 bit 1*/
#define ISC10       2  /*Interrupt Sense Control 1 bit 0*/
#define ISC11       3  /*Interrupt Sense Control 1 bit 1*/

/*MCUCSR bit names*/
#define ISC2        6  /*Interrupt Sense Control 2*/

/*GICR bit names*/
#define INT2        5  /*External Interrupt Request 2 Enable*/ 
#define INT0        6  /*External Interrupt Request 0 Enable*/
#define INT1        7  /*External Interrupt Request 1 Enable*/

/*GIFR bit names*/
#define INF2        5  /*External Interrupt Flag 2*/ 
#define INF0        6  /*External Interrupt Flag 0*/
#define INF1        7  /*External Interrupt Flag 1*/

#endif /*EXTI_PRIVATE_H_*/