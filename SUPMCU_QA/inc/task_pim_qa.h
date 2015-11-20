/* 
 * File:   task_pim_qa.h
 * Author: Sonja
 *
 * Created on October 29, 2015, 3:12 PM
 */

#ifndef TASK_PIM_QA_H
#define	TASK_PIM_QA_H

#ifdef	__cplusplus
extern "C" {
#endif

// Function declarations
extern void task_pim_qa(void );

extern void pim_port1_en(unsigned int);
extern void pim_port1_dis(unsigned int);
extern void pim_port2_en(unsigned int);
extern void pim_port2_dis(unsigned int);
extern void pim_port3_en(unsigned int);
extern void pim_port3_dis(unsigned int);
extern void pim_port4_en(unsigned int);
extern void pim_port4_dis(unsigned int);
// Symbols, etc.
#define STR_TASK_PIM_QA "task_pim_qa: " STR_1TAB

#ifdef	__cplusplus
}
#endif

#endif	/* TASK_PIM_QA_H */

