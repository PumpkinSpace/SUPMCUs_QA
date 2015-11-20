/******************************************************************************

SCPI implementation for CubeSat Kit using Jan Breuer's SCPI Parser

(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: 
$Author: aek $
$Revision: 3.0 $
$Date: 2014-06-01 16:22:49-07 $

******************************************************************************/

#ifndef __scpi_config_h
#define	__scpi_config_h

#include "types.h"

//SHOULD BE LONGER THAN LONGEST POSSIBLE SCPI STRING
#define SCPI_CMD_BUFFER_LEN 256

//TEMPORARY STRING BUFFER
extern char scpiTmpStr[];

//SCPI STATUS STRUCTURE
extern scpi_t scpi_context;

//COMMAND LIST
extern scpi_command_t scpi_commands[];

//INTERFACE CALLBACKS
size_t SCPI_Write(scpi_t * context, const char * data, size_t len);
int SCPI_Error(scpi_t * context, int_fast16_t err);
scpi_result_t SCPI_Flush(scpi_t * context);
scpi_result_t SCPI_Test(scpi_t * context);
scpi_result_t SCPI_Reset(scpi_t * context);

#endif	/* __scpi_config_h */
