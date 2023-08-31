/**
 * @file SSD_Interface.h
 * @author Ahmed Atia (atiaa6501@gmail.com)
 * 
 * @version 1.0
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_ONE         1
#define SSD_TWO         2

void SSD_Init               (void);
void SSD_DisplayNumber      (u8 Copy_u8ssdID, u8 Copy_u8Number);
void SSD_DisplayMultiNumber (u8 Copy_u8Number);

#endif /*SSD_INTERFACE_H_*/