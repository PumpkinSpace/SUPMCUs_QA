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



unsigned char STR_PORT1_ON[]    =   {"PIM:PORT:POW ON,1\n"};
unsigned char STR_PORT1_OFF[]   =   {"PIM:PORT:POW OFF,1\n"};

unsigned char STR_PORT2_ON[]    =   {"PIM:PORT:POW ON,2\n"};
unsigned char STR_PORT2_OFF[]   =   {"PIM:PORT:POW OFF,2\n"};

unsigned char STR_PORT3_ON[]    =   {"PIM:PORT:POW ON,3\n"};
unsigned char STR_PORT3_OFF[]   =   {"PIM:PORT:POW OFF,3\n"};

unsigned char STR_PORT4_ON[]    =   {"PIM:PORT:POW ON,4\n"};
unsigned char STR_PORT4_OFF[]   =   {"PIM:PORT:POW OFF,4\n"};

void pim_port1_en(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT1_ON, sizeof(STR_PORT1_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT1 is turned ON.");
  }
} 

void pim_port1_dis(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT1_OFF, sizeof(STR_PORT1_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT1 is turned OFF.");
  }
} 

void pim_port2_en(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT2_ON, sizeof(STR_PORT2_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT2 is turned ON.");
  }
} 

void pim_port2_dis(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT2_OFF, sizeof(STR_PORT2_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT2 is turned OFF.");
  }
} 

void pim_port3_en(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT3_ON, sizeof(STR_PORT3_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT3 is turned ON.");
  }
} 

void pim_port3_dis(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT3_OFF, sizeof(STR_PORT3_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT3 is turned OFF.");
  }
} 

void pim_port4_en(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT4_ON, sizeof(STR_PORT4_ON)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT4 is turned ON.");
  }
} 

void pim_port4_dis(unsigned int show) {
  i2c1_write(I2C_ADDR.p, STR_PORT4_OFF, sizeof(STR_PORT4_OFF)-1);  
  if(show) { 
    user_debug_msg(STR_TASK_PIM_QA  "PORT4 is turned OFF.");
  }
} 

void task_pim_qa(void) {
    
  //user_debug_msg(STR_TASK_PIM_QA "Stopped.");
  OS_Stop();
  user_debug_msg(STR_TASK_PIM_QA  "Starting.");

#if 1
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); OS_Delay(250);

  user_debug_msg(STR_TASK_PIM_QA  "For the following test:");
  user_debug_msg(STR_TASK_PIM_QA  "Connect: 12V power supply.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250);
  pim_port1_dis(FALSE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_1 is ON");
  pim_port1_en(TRUE);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); 
  pim_port1_dis(TRUE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_1 is OFF");
  OS_Delay(250);
  
  pim_port2_dis(FALSE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_2 is ON");
  pim_port2_en(TRUE);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250);
  pim_port2_dis(TRUE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_2 is OFF");
  OS_Delay(250);
  
  
  user_debug_msg(STR_TASK_PIM_QA  "For the following test:");
  user_debug_msg(STR_TASK_PIM_QA  "Connect: 6-8V power supply.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250);
  pim_port3_dis(FALSE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_3 is ON");
  pim_port3_en(TRUE);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250); 
  pim_port3_dis(TRUE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_3 is OFF");
  OS_Delay(250);
  
  user_debug_msg(STR_TASK_PIM_QA  "For the following test:");
  user_debug_msg(STR_TASK_PIM_QA  "Connect: 5V power supply.");
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250);
  pim_port4_dis(FALSE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_4 is ON");
  pim_port4_en(TRUE);
  OS_Delay(250); OS_Delay(250);
  OS_Delay(250);
  pim_port4_dis(TRUE);
  user_debug_msg(STR_TASK_PIM_QA "Verify: LED2_4 is OFF");
 while(1) { 
    OS_Delay(250);
 }
#endif
 
}