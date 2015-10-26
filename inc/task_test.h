/******************************************************************************
(C) Copyright Pumpkin, Inc. All Rights Reserved.

This file may be distributed under the terms of the License
Agreement provided with this software.

THIS FILE IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND,
INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE.

$Source: C:\\RCS\\D\\Pumpkin\\CubeSatKit\\Example\\all\\all\\CubeSatKit_Dev_Board\\Test\\Test1\\task_5sec.h,v $
$Author: aek $
$Revision: 3.0 $
$Date: 2009-10-11 22:38:16-07 $

******************************************************************************/
#ifndef __task_test_h
#define __task_test_h


// Function declarations
extern void task_test(void );

extern void gps_led_off(unsigned int);
extern void gps_led_on(unsigned int);
extern void gps_led_flash(unsigned int);
extern void gps_led_gps(unsigned int);
extern void gps_sup_clk_off(unsigned int);
extern void gps_sup_clk_on(unsigned int, unsigned int);
extern void gps_pow_off(unsigned int);
extern void gps_pow_on(unsigned int);
extern void gps_res_off(unsigned int);
extern void gps_res_on(unsigned int);
extern void gps_pass_off(unsigned int);
extern void gps_pass_on(unsigned int);
extern void gps_log_off(unsigned int);
extern void gps_log_gga(unsigned int);

// Symbols, etc.
#define STR_TASK_TEST "task_test: " STR_1TAB


#endif /* __task_test_h */
