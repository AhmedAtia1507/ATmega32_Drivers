/**
 * @file SPI_Private.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * @version 1.0
 * @date 2022-12-13
 * 
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*SPI Roles*/
#define SPI_MASTER                                              1
#define SPI_SLAVE                                               2

/*SPI Interrupt Status*/                        
#define SPI_INTERRUPT_ENABLED                                   1
#define SPI_INTERRUPT_DISABLED                                  2

/*SPI Data Order*/                      
#define SPI_DATA_LSB_FIRST                                      1
#define SPI_DATA_MSB_FIRST                                      2

/*SPI Clock Polarity*/
#define SPI_CLOCK_RISING_EDGE_LEADING_FALLING_EDGE_TRAILING     1
#define SPI_CLOCK_FALLING_EDGE_LEADING_RISING_EDGE_TRAILING     2  

/*SPI Clock Phase*/
#define SPI_SAMPLE_AT_LEADING_EDGE_SETUP_AT_TRAILING_EDGE       1
#define SPI_SAMPLE_AT_TRAILING_EDGE_SETUP_AT_LEADING_EDGE       2

/*SPI Clock Prescalars*/
#define SPI_PRESCALAR_DIVIDE_BY_2                               1
#define SPI_PRESCALAR_DIVIDE_BY_4                               2
#define SPI_PRESCALAR_DIVIDE_BY_8                               3
#define SPI_PRESCALAR_DIVIDE_BY_16                              4
#define SPI_PRESCALAR_DIVIDE_BY_32                              5
#define SPI_PRESCALAR_DIVIDE_BY_64                              6
#define SPI_PRESCALAR_DIVIDE_BY_128                             7                                          
/**************SPCR bit names**************/
/*SPI Clock Rate Select 0*/
#define SPR0                            0
/*SPI Clock Rate Select 1*/
#define SPR1                            1
/*Clock Phase*/
#define CPHA                            2
/*Clock Polarity*/
#define CPOL                            3
/*Master/Slave Select*/
#define MSTR                            4
/*Data Order*/
#define DORD                            5
/*SPI Enable*/
#define SPE                             6
/*SPI Interrupt Enable*/
#define SPIE                            7

/**************SPSR bit names**************/
/*Double SPI Speed Bit*/
#define SPI2X                           0
/*Write COLlision Flag*/
#define WCOL                            6
/*SPI Interrupt Flag*/
#define SPIF                            7
#endif /*SPI_PRIVATE_H_*/