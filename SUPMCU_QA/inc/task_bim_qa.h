/* 
 * File:   task_bim_qa.h
 * Author: Sonja
 *
 * Created on October 27, 2015, 9:44 AM
 */

#ifndef TASK_BIM_QA_H
#define	TASK_BIM_QA_H

#ifdef	__cplusplus
extern "C" {
#endif


// Function declarations
extern void task_bim_qa(void );

extern void bim_tini_dis(unsigned int);
extern void bim_tini_enab(unsigned int);
extern void bim_tini_arm(unsigned int);
extern void bim_tini_unarm(unsigned int);
extern void bim_tini_fire(unsigned int);

extern void bim_uart1_on(unsigned int);
extern void bim_uart1_off(unsigned int);
extern void bim_uart2_on(unsigned int);
extern void bim_uart2_off(unsigned int);
extern void bim_uart3_on(unsigned int);
extern void bim_uart3_off(unsigned int);

extern void bim_eth1_on(unsigned int);
extern void bim_eth1_off(unsigned int);
extern void bim_eth2_on(unsigned int);
extern void bim_eth2_off(unsigned int);
extern void bim_eth3_on(unsigned int);
extern void bim_eth3_off(unsigned int);
extern void bim_eth_res(unsigned int);
extern void bim_eth_mode0(unsigned int);
extern void bim_eth_mode1(unsigned int);
extern void bim_eth_mode2(unsigned int);
extern void bim_eth_mode3(unsigned int);
extern void bim_eth_mode_off(unsigned int);
extern void bim_eth_i2c_on(unsigned int);
extern void bim_eth_i2c_off(unsigned int);

extern void bim_temp_on(unsigned int);
extern void bim_temp_off(unsigned int);
extern void bim_ttest_on(unsigned int);
extern void bim_ttest_off(unsigned int);

extern void bim_ee_i2c_on(unsigned int);
extern void bim_ee_i2c_off(unsigned int);
extern void bim_sky_on(unsigned int);
extern void bim_sky_off(unsigned int);
extern void bim_imu_on(unsigned int);
extern void bim_imu_off(unsigned int);
extern void bim_wdt_force(unsigned int);

// Symbols, etc.
#define STR_TASK_BIM_QA "task_bim_qa: " STR_1TAB


#ifdef	__cplusplus
}
#endif

#endif	/* TASK_BIM_QA_H */

