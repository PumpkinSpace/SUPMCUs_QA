/******************************************************************************

(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\SCPI\\PIC24\\inc\\scpi_I2C_slave.h,v $
$Author: aek $
$Revision: 3.0 $
$Date: 2014-06-01 16:22:49-07 $

******************************************************************************/

#ifndef __scpi_i2c_slave_h
#define	__scpi_i2c_slave_h


//SET EQUAL TO THE SCPI PARSING BUFFER LENGTH
#define I2C1_BUF_LEN	SCPI_CMD_BUFFER_LEN
#define I2C1_NUM_BUFS	8

//NUMBER OF MESSAGE BUFFERS WAITING TO BE PARSED
extern int 	I2C1_Msgs_Pending;

//TOTAL NUMBER OF I2C MESSAGES RECOGNIZED
extern long  I2C1_Msgs_Received;

extern void i2c1_init(void);
extern unsigned char i2c1_addr(void);
extern void i2c1_read_buffer(char*); 
void __attribute__((interrupt,no_auto_psv)) _SI2C1Interrupt(void);

#endif /* __scpi_i2c_slave_h */
