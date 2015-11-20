/* 
 * File:   telemetry.h
 * Author: Sonja
 *
 * Created on November 11, 2015, 3:29 PM
 */

#ifndef TELEMETRY_H
#define	TELEMETRY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define STR_TELEMETRY_QA    "task_telem: " STR_1TAB
 


extern void task_telemetry();    
extern void supmcu_selftest_start(unsigned int);
extern void supmcu_selftest_res(unsigned int);

#ifdef	__cplusplus
}
#endif

#endif	/* TELEMETRY_H */

