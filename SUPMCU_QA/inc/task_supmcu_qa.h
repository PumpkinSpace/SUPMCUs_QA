/* 
 * File:   task_supmcu_qa.h
 * Author: SB
 *
 * Created on October 26, 2015, 4:26 PM
 */

#ifndef TASK_SUPMCU_QA_H
#define	TASK_SUPMCU_QA_H

#ifdef	__cplusplus
extern "C" {
#endif

// Function declarations
extern void task_supmcu_qa(void );

extern void sup_led_off(unsigned int);
extern void sup_led_on(unsigned int);
extern void sup_led_flash(unsigned int);
extern void sup_clk_off(unsigned int);
extern void sup_clk_on(unsigned int, unsigned int);
extern void i2c_write_all(unsigned char[]);
// Symbols, etc.
#define STR_TASK_SUPMCU_QA "task_sup_qa: " STR_1TAB


#ifdef	__cplusplus
}
#endif

#endif	/* TASK_SUPMCU_QA_H */

