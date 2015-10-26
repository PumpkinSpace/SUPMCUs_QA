/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\all\\all\\CubeSatKit_Dev_Board\\Test\\Test1\\main.c,v $
$Author: aek $
$Revision: 3.2 $
$Date: 2010-03-28 19:40:15-08 $

******************************************************************************/
#include "events.h"
#include "init.h"
#include "main.h"
#include "task_5sec.h"
#include "task_cmd.h"
#include "task_monitor.h"
#include "task_new.h"
#include "task_test.h"
#include "tasks.h"

// Pumpkin Salvo headers
#include "salvo.h"



csk_status_t csk_status;
char strTmp[200];                  // usable to anyone who wants it ...


/******************************************************************************
****                                                                       ****
**                                                                           **
main()

Conventional Salvo main(), with peripheral initialization, Salvo 
initialization, and the Salvo scheduler.

**                                                                           **
****                                                                       ****
******************************************************************************/
int main() {

  // Do target-specific (e.g., clocks, UARTs) and general 
  //  (e.g., CSK IO) initialization.
  init();
                              
  // Initialize Salvo RTOS.
  OSInit();

  // Create tasks.
  OSCreateTask(task_cmd_do,    TASK_CMD_DO_P,    1);
  OSCreateTask(task_5sec,      TASK_5SEC_P,      4);
  OSCreateTask(task_test,      TASK_TEST_P,      7);
  OSCreateTask(task_monitor,   TASK_MONITOR_P,   2);
  OSCreateTask(task_new,       TASK_NEW_P,       3); // test task   
 
  // Create events.
  OSCreateSem(SEM_CMD_CHAR_P,       0);    // No chars received yet

  // Enable interrupts (enables UART tx & rx).
  __enable_interrupt();

  // Multitask.
  while (1) {
    OSSched();
  } /* while */
  
} /* main() */