/**
 * @file TWI_Private.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/*TWCR Register*/
#define TWIE                                        0
#define TWEN                                        2
#define TWWC                                        3
#define TWSTO                                       4
#define TWSTA                                       5
#define TWEA                                        6
#define TWINT                                       7

#define TWI_MAX_SLAVE_ADDRESS                       127

#define TWI_START_COND_POSITIVE_ACK                 0x08
#define TWI_REPEATED_START_COND_POSITIVE_ACK        0x10
#define TWI_SLAVE_ADDRESS_WITH_WRITE_POSITIVE_ACK   0x18
#define TWI_SLAVE_ADDRESS_WITH_READ_POSITIVE_ACK    0x40
#define TWI_SEND_MASTER_DATA_BYTE_POSITIVE_ACK      0x28
#define TWI_RECEIVE_MASTER_DATA_BYTE_POSITIVE_ACK   0x50




#endif /*TWI_PRIVATE_H_*/