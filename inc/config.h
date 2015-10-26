/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\PIC24\\PIC24FJ256GA110\\CubeSat_Kit_Dev_Board\\Test\\Test1\\config.h,v $
$Author: aek $
$Revision: 3.0 $
$Date: 2010-02-13 13:40:21-08 $

******************************************************************************/
#ifndef __CONFIG_H
#define __CONFIG_H


#include <p24fxxxx.h>         			              // For the entire PIC24 family.

#define MAIN_XTAL_FREQ                    8000000L    // 8.000MHz main xtal
#define SCND_XTAL_FREQ                    32768       // 32.768kHz secondary xtal

#define GETCHAR_PUTCHAR_RETURN_ZERO       1           // For this project, these functions return 0
                                                      //  on error

#define RX1_BUFF_SIZE                     256         // 
#define TX1_BUFF_SIZE                     256         // 
#define RX2_BUFF_SIZE                     256         // 
#define TX2_BUFF_SIZE                     256         // 
#define RX3_BUFF_SIZE                     256         // 
#define TX3_BUFF_SIZE                     256         // 
#define RX4_BUFF_SIZE                     256         // 
#define TX4_BUFF_SIZE                     256         // 


#endif /* __CONFIG_H */

