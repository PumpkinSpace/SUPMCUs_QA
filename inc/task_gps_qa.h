/* 
 * File:   task_gps_qa.h
 * Author: SB
 *
 * Created on October 26, 2015, 4:41 PM
 */

#ifndef TASK_GPS_QA_H
#define	TASK_GPS_QA_H

#ifdef	__cplusplus
extern "C" {
#endif


// Function declarations
extern void task_gps_qa(void );

extern void gps_led_gps(unsigned int);
extern void gps_pow_off(unsigned int);
extern void gps_pow_on(unsigned int);
extern void gps_res_off(unsigned int);
extern void gps_res_on(unsigned int);
extern void gps_pass_off(unsigned int);
extern void gps_pass_on(unsigned int);
extern void gps_log_off(unsigned int);
extern void gps_log_gga(unsigned int);

// Symbols, etc.
#define STR_TASK_GPS_QA "task_gps_qa: " STR_1TAB



#ifdef	__cplusplus
}
#endif

#endif	/* TASK_GPS_QA_H */

