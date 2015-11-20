/******************************************************************************

SCPI implementation for CubeSat Kit using Jan Breuer's SCPI Parser

(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\SCPI\\PIC24\\src\\scpi_config.c,v $
$Author: aek $
$Revision: 3.0 $
$Date: 2014-06-01 16:22:37-07 $

******************************************************************************/
/** \file scpi_config.c
    \brief SCPI implementation for CubeSat Kit using Jan Breuer's SCPI Parser.
 */



#include "scpi_config.h"
#include "scpi/scpi.h"
#include "pic24_uart_msg_hhmmsstt.h"
#include "supmcu.h"
#include "supmcu_debug.h"
#include <stdio.h>


//BUFFER FOR PARSING
static char scpi_input_buffer[SCPI_CMD_BUFFER_LEN];

//SEE SCPI/TYPES.H
static scpi_reg_val_t scpi_regs[SCPI_REG_COUNT];

//TEMPORARY STRING BUFFER
char scpiTmpStr[SCPI_CMD_BUFFER_LEN];

//SCPI RESPONSE HANDLING
size_t SCPI_Write(scpi_t * context, const char * data, size_t len) {
    if(supmcu_debug_terminal_output()) {    
        sprintf(scpiTmpStr, "**Write:\t%s", data);
        uart1_msg_hhmmsstt(scpiTmpStr); 
    }  
    return 0;
}

//ERROR MESSAGE HANDLING
int SCPI_Error(scpi_t * context, int_fast16_t err) {
	(void) context;
    if(supmcu_debug_terminal_output()) {         
        sprintf(scpiTmpStr, "**ERROR: %ld, \"%s\"\r\n", (int32_t) err, SCPI_ErrorTranslate(err));
        uart1_msg_hhmmsstt(scpiTmpStr); 
    }    
    return 0;
}

scpi_result_t SCPI_Flush(scpi_t * context) {
	(void) context;   
    return SCPI_RES_OK;
}

scpi_result_t SCPI_Test(scpi_t * context) {
	(void) context;
        if(supmcu_debug_terminal_output()) {          
        uart1_msg_hhmmsstt("**Test\r\n");
    }
    return SCPI_RES_OK;
}

scpi_result_t SCPI_Reset(scpi_t * context) {
	(void) context;
        if(supmcu_debug_terminal_output()) {          
        uart1_msg_hhmmsstt("**Reset\r\n");
    }  
    return SCPI_RES_OK;
}

//INTERFACE CALLBACKS
static scpi_interface_t scpi_interface = {
	.write 	= 	SCPI_Write,
	.error 	= 	SCPI_Error,
	.reset 	= 	SCPI_Reset,
	.test 	= 	SCPI_Test,
    .flush	= 	SCPI_Flush,
};

//SCPI STATUS STRUCTURE
scpi_t scpi_context = {
	.cmdlist = scpi_commands,
	.buffer = {
		.length = SCPI_CMD_BUFFER_LEN,
		.data = scpi_input_buffer,
	},
	.interface = &scpi_interface,
	.registers = scpi_regs,
	.units = scpi_units_def,
	.special_numbers = scpi_special_numbers_def,
};
