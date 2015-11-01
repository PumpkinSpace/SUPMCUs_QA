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


/*// Supmcu's I2C address
#if defined(SUPMCU_GPSRM1_REVA) \
   || defined(SUPMCU_GPSRM1_REVB) \
   || defined(SUPMCU_GPSRM1_REVC) 
#define I2C_ADDR 0x51
#elif defined(SUPMCU_BIM1_REVA) \
     || defined(SUPMCU_BIM1_REVB)
#define I2C_ADDR 0x52
#elif defined(SUPMCU_PIM1_REVA) \
      || defined(SUPMCU_PIM1_REVB)
#define I2C_ADDR 0x53
#elif defined(SUPMCU_SIM1_REVA) \
      || defined(SUPMCU_SIM1_REVB)
#define I2C_ADDR 0x54
#endif
*/
// Symbols, etc.
#define STR_TASK_SUPMCU_QA "task_supmcu_qa: " STR_1TAB


#ifdef	__cplusplus
}
#endif

#endif	/* TASK_SUPMCU_QA_H */

