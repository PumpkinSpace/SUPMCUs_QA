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
#include "task_sim_qa.h"
#include "task_supmcu_qa.h"

// Pumpkin CubeSat Kit headers
#include "csk_uart.h"

// Pumpkin PIC24 Library.
#include "pic24_i2c.h"

// Pumpkin Salvo RTOS.
#include "salvo.h"
#include "tasks.h"

unsigned char STR_PRM_DIS[]    =   {"SIM:PRM DIS\n"};
unsigned char STR_PRM_ENAB[]   =   {"SIM:PRM ENAB\n"};
unsigned char STR_PRM_ARM[]    =   {"SIM:PRM ARM\n"};
unsigned char STR_PRM_UNARM[]  =   {"SIM:PRM UNAR\n"};
unsigned char STR_PRM_FIRE[]   =   {"SIM:PRM FIRE,7\n"};

void sim_prm_enab(unsigned int show) {
  i2c1_write(I2C_ADDR.s, STR_PRM_ENAB, sizeof(STR_PRM_ENAB)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SIM_QA  "SIM PRM enable."); 
  }
} 

void sim_prm_dis(unsigned int show) {
  i2c1_write(I2C_ADDR.s, STR_PRM_DIS, sizeof(STR_PRM_DIS)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SIM_QA  "SIM PRM disable."); 
  }
} 

void sim_prm_unarm(unsigned int show) {
  i2c1_write(I2C_ADDR.s, STR_PRM_UNARM, sizeof(STR_PRM_UNARM)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SIM_QA  "SIM PRM unarm."); 
  }
} 

void sim_prm_arm(unsigned int show) {
  i2c1_write(I2C_ADDR.s, STR_PRM_ARM, sizeof(STR_PRM_ARM)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SIM_QA  "SIM PRM arm."); 
  }
} 


void sim_prm_fire(unsigned int show) {
   i2c1_write(I2C_ADDR.s, STR_PRM_FIRE, sizeof(STR_PRM_FIRE)-1); 
  if(show) { 
    user_debug_msg(STR_TASK_SIM_QA  "SIM PRM Firing."); 
  } 
}



void task_sim_qa(void) {
  
  OS_Stop();
  user_debug_msg(STR_TASK_SIM_QA  "Starting.");
   // Verify TiNi
  user_debug_msg(STR_TASK_SIM_QA  "Verify: LED is OFF.");
  sim_prm_enab(TRUE);
  OS_Delay(150);
  sim_prm_arm(TRUE);
  OS_Delay(150);
  sim_prm_fire(TRUE);
  OS_Delay(150);
  user_debug_msg(STR_TASK_SIM_QA  "Verify: PRM Fire 7s: LED is ON.");
  OS_Delay(250); OS_Delay(250);
  sim_prm_dis(FALSE);
  sim_prm_unarm(FALSE);
  user_debug_msg(STR_TASK_SIM_QA  "Verify: LED is OFF.");
   while(1) { 
    OS_Delay(250);
   }
  
 
}
