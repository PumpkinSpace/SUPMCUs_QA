/* 
 * File:   task_sim_qa_g.h
 * Author: Sonja
 *
 * Created on November 9, 2015, 1:57 PM
 */

#ifndef TASK_SIM_QA_G_H
#define	TASK_SIM_QA_G_H

#ifdef	__cplusplus
extern "C" {
#endif

extern void task_sim_qa(void );

extern void sim_prm_arm(unsigned int);
extern void sim_prm_unarm(unsigned int);
extern void sim_prm_enab(unsigned int);
extern void sim_prm_dis(unsigned int);
extern void sim_prm_fire(unsigned int);

#define STR_TASK_SIM_QA "task_sim_qa: " STR_1TAB

#ifdef	__cplusplus
}
#endif

#endif	/* TASK_SIM_QA_G_H */

