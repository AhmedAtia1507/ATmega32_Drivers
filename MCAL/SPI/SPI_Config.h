/**
 * @file SPI_Config.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * @version 1.0
 * @date 2022-12-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "SPI_Private.h"
/*
    SPI Roles
1) SPI_MASTER                                         
2) SPI_SLAVE
*/
#define SPI_ROLE                        SPI_MASTER
/*
   SPI Interrupt Status                                          
1) SPI_INTERRUPT_ENABLED                              
2) SPI_INTERRUPT_DISABLED
*/
#define SPI_INTERRUPT_STATUS            SPI_INTERRUPT_ENABLED
/*
    SPI Data Order
1) SPI_DATA_LSB_FIRST                                 
2) SPI_DATA_MSB_FIRST
*/
#define SPI_DATA_SENT_ORDER             SPI_DATA_LSB_FIRST

/*
    SPI Clock Polarity                              
1) SPI_CLOCK_RISING_EDGE_LEADING_FALLING_EDGE_TRAILING
2) SPI_CLOCK_FALLING_EDGE_LEADING_RISING_EDGE_TRAILING
*/
#define SPI_CLOCK_POLARITY              SPI_CLOCK_RISING_EDGE_LEADING_FALLING_EDGE_TRAILING

/*
    SPI Clock Phase
1) SPI_SAMPLE_AT_LEADING_EDGE_SETUP_AT_TRAILING_EDGE                         
2) SPI_SAMPLE_AT_TRAILING_EDGE_SETUP_AT_LEADING_EDGE
*/
#define SPI_CLOCK_PHASE                 SPI_SAMPLE_AT_LEADING_EDGE_SETUP_AT_TRAILING_EDGE                        

/*
    SPI Prescalars
1) SPI_PRESCALAR_DIVIDE_BY_2  
2) SPI_PRESCALAR_DIVIDE_BY_4  
3) SPI_PRESCALAR_DIVIDE_BY_8  
4) SPI_PRESCALAR_DIVIDE_BY_16 
5) SPI_PRESCALAR_DIVIDE_BY_32 
6) SPI_PRESCALAR_DIVIDE_BY_64 
7) SPI_PRESCALAR_DIVIDE_BY_128
*/
#define SPI_CLOCK_PRESCALAR             SPI_PRESCALAR_DIVIDE_BY_64
#endif /*SPI_CONFIG_H_*/