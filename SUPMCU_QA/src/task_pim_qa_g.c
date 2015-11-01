/* 
 * File:   task_pim_qa.c
 * Author: Sonja
 *
 * Created on October 29, 2015, 3:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "events.h"
#include "task_pim_qa.h"
#include "task_supmcu_qa.h"

// Pumpkin CubeSat Kit headers
//#include "csk_hw.h"
//#include "csk_serial.h"
#include "csk_uart.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"
#include "tasks.h"




unsigned char STR_PORT4_ON[]    =   {"PIM:PORT:POW 4,ON\n"};

unsigned char STR_PORT4_OFF[]    =   {"PIM:PORT:POW 4,OFF\n"};

void pim_port4_en(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_PORT4_ON, sizeof(STR_PORT4_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT4 is turned ON.");
  }
} 

void pim_port4_dis(unsigned int show) {
  i2c1_write(I2C_ADDR, STR_PORT4_OFF, sizeof(STR_PORT4_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT4 is turned OFF.");
  }
} 

void task_pim_qa(void) {
    
  user_debug_msg(STR_TASK_PIM_QA "Stopped.");
  OS_Stop();
  user_debug_msg(STR_TASK_PIM_QA  "Starting.");

#if 1
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  pim_port4_dis(FALSE);
  pim_port4_en(TRUE);
  pim_port4_dis(TRUE);
#endif
 
}