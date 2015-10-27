#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/gps_nmea.c ../src/init.c ../src/main.c ../src/task_5sec.c ../src/task_cmd.c ../src/task_monitor.c ../src/task_new.c C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c ../src/task_gps_qa.c ../src/task_supmcu_qa.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c C:/Pumpkin/Salvo/Src/salvomem.c C:/Pumpkin/Salvo/Src/salvotime.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/gps_nmea.o ${OBJECTDIR}/_ext/1360937237/init.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/task_5sec.o ${OBJECTDIR}/_ext/1360937237/task_cmd.o ${OBJECTDIR}/_ext/1360937237/task_monitor.o ${OBJECTDIR}/_ext/1360937237/task_new.o ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o ${OBJECTDIR}/_ext/1810884970/csk_io.o ${OBJECTDIR}/_ext/1810884970/csk_led.o ${OBJECTDIR}/_ext/1810884970/csk_mhx.o ${OBJECTDIR}/_ext/1810884970/csk_power.o ${OBJECTDIR}/_ext/1810884970/csk_rand.o ${OBJECTDIR}/_ext/1810884970/csk_usb.o ${OBJECTDIR}/_ext/1810884970/csk_wdt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o ${OBJECTDIR}/_ext/2044256807/salvomem.o ${OBJECTDIR}/_ext/2044256807/salvotime.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d ${OBJECTDIR}/_ext/1360937237/init.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/task_5sec.o.d ${OBJECTDIR}/_ext/1360937237/task_cmd.o.d ${OBJECTDIR}/_ext/1360937237/task_monitor.o.d ${OBJECTDIR}/_ext/1360937237/task_new.o.d ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d ${OBJECTDIR}/_ext/1810884970/csk_io.o.d ${OBJECTDIR}/_ext/1810884970/csk_led.o.d ${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d ${OBJECTDIR}/_ext/1810884970/csk_power.o.d ${OBJECTDIR}/_ext/1810884970/csk_rand.o.d ${OBJECTDIR}/_ext/1810884970/csk_usb.o.d ${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d ${OBJECTDIR}/_ext/2044256807/salvomem.o.d ${OBJECTDIR}/_ext/2044256807/salvotime.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/gps_nmea.o ${OBJECTDIR}/_ext/1360937237/init.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/task_5sec.o ${OBJECTDIR}/_ext/1360937237/task_cmd.o ${OBJECTDIR}/_ext/1360937237/task_monitor.o ${OBJECTDIR}/_ext/1360937237/task_new.o ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o ${OBJECTDIR}/_ext/1810884970/csk_io.o ${OBJECTDIR}/_ext/1810884970/csk_led.o ${OBJECTDIR}/_ext/1810884970/csk_mhx.o ${OBJECTDIR}/_ext/1810884970/csk_power.o ${OBJECTDIR}/_ext/1810884970/csk_rand.o ${OBJECTDIR}/_ext/1810884970/csk_usb.o ${OBJECTDIR}/_ext/1810884970/csk_wdt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o ${OBJECTDIR}/_ext/2044256807/salvomem.o ${OBJECTDIR}/_ext/2044256807/salvotime.o

# Source Files
SOURCEFILES=../src/gps_nmea.c ../src/init.c ../src/main.c ../src/task_5sec.c ../src/task_cmd.c ../src/task_monitor.c ../src/task_new.c C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c ../src/task_gps_qa.c ../src/task_supmcu_qa.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c C:/Pumpkin/Salvo/Src/salvomem.c C:/Pumpkin/Salvo/Src/salvotime.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ256GA110
MP_LINKER_FILE_OPTION=,--script=p24FJ256GA110.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/gps_nmea.o: ../src/gps_nmea.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_nmea.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gps_nmea.c  -o ${OBJECTDIR}/_ext/1360937237/gps_nmea.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/init.o: ../src/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/init.c  -o ${OBJECTDIR}/_ext/1360937237/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_5sec.o: ../src/task_5sec.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_5sec.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_5sec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_5sec.c  -o ${OBJECTDIR}/_ext/1360937237/task_5sec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_5sec.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_5sec.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_cmd.o: ../src/task_cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_cmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_cmd.c  -o ${OBJECTDIR}/_ext/1360937237/task_cmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_cmd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_cmd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_monitor.o: ../src/task_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_monitor.c  -o ${OBJECTDIR}/_ext/1360937237/task_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_monitor.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_monitor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_new.o: ../src/task_new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_new.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_new.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_new.c  -o ${OBJECTDIR}/_ext/1360937237/task_new.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_new.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_new.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o: C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_gps_qa.o: ../src/task_gps_qa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_gps_qa.c  -o ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o: ../src/task_supmcu_qa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_supmcu_qa.c  -o ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_io.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_io.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c  -o ${OBJECTDIR}/_ext/1810884970/csk_io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_io.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_io.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_led.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c  -o ${OBJECTDIR}/_ext/1810884970/csk_led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_led.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_mhx.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_mhx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c  -o ${OBJECTDIR}/_ext/1810884970/csk_mhx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_power.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_power.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c  -o ${OBJECTDIR}/_ext/1810884970/csk_power.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_power.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_power.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_rand.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_rand.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_rand.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c  -o ${OBJECTDIR}/_ext/1810884970/csk_rand.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_rand.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_rand.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_usb.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c  -o ${OBJECTDIR}/_ext/1810884970/csk_usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_usb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_usb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_wdt.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_wdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c  -o ${OBJECTDIR}/_ext/1810884970/csk_wdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart1.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart2.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart3.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart4.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o: C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1297474772" 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c  -o ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o: C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1297474772" 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c  -o ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2044256807/salvomem.o: C:/Pumpkin/Salvo/Src/salvomem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2044256807" 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvomem.o.d 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvomem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/salvomem.c  -o ${OBJECTDIR}/_ext/2044256807/salvomem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2044256807/salvomem.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2044256807/salvomem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2044256807/salvotime.o: C:/Pumpkin/Salvo/Src/salvotime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2044256807" 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvotime.o.d 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvotime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/salvotime.c  -o ${OBJECTDIR}/_ext/2044256807/salvotime.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2044256807/salvotime.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2044256807/salvotime.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1360937237/gps_nmea.o: ../src/gps_nmea.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gps_nmea.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gps_nmea.c  -o ${OBJECTDIR}/_ext/1360937237/gps_nmea.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/gps_nmea.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/init.o: ../src/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/init.c  -o ${OBJECTDIR}/_ext/1360937237/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/init.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/init.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_5sec.o: ../src/task_5sec.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_5sec.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_5sec.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_5sec.c  -o ${OBJECTDIR}/_ext/1360937237/task_5sec.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_5sec.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_5sec.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_cmd.o: ../src/task_cmd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_cmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_cmd.c  -o ${OBJECTDIR}/_ext/1360937237/task_cmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_cmd.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_cmd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_monitor.o: ../src/task_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_monitor.c  -o ${OBJECTDIR}/_ext/1360937237/task_monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_monitor.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_monitor.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_new.o: ../src/task_new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_new.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_new.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_new.c  -o ${OBJECTDIR}/_ext/1360937237/task_new.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_new.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_new.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o: C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_i2c1.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_i2c1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_gps_qa.o: ../src/task_gps_qa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_gps_qa.c  -o ${OBJECTDIR}/_ext/1360937237/task_gps_qa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_gps_qa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o: ../src/task_supmcu_qa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/task_supmcu_qa.c  -o ${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/task_supmcu_qa.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_io.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_io.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_io.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_io.c  -o ${OBJECTDIR}/_ext/1810884970/csk_io.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_io.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_io.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_led.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_led.c  -o ${OBJECTDIR}/_ext/1810884970/csk_led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_led.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_mhx.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_mhx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_mhx.c  -o ${OBJECTDIR}/_ext/1810884970/csk_mhx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_mhx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_power.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_power.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_power.c  -o ${OBJECTDIR}/_ext/1810884970/csk_power.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_power.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_power.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_rand.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_rand.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_rand.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_rand.c  -o ${OBJECTDIR}/_ext/1810884970/csk_rand.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_rand.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_rand.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_usb.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_usb.c  -o ${OBJECTDIR}/_ext/1810884970/csk_usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_usb.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_usb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1810884970/csk_wdt.o: C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1810884970" 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1810884970/csk_wdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/CubeSatKit/PIC24/src/csk_wdt.c  -o ${OBJECTDIR}/_ext/1810884970/csk_wdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1810884970/csk_wdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart1.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart1.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart1_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart1_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart2.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart2.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart2_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart2_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart3.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart3.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart3_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart3_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart4.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart4.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o: C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1655478246" 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Library/PIC24/Src/pic24_uart4_msg_hhmmsstt.c  -o ${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1655478246/pic24_uart4_msg_hhmmsstt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o: C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1297474772" 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/MCC30/salvohook_interrupt_MCC30_IRQ.c  -o ${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1297474772/salvohook_interrupt_MCC30_IRQ.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o: C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1297474772" 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/MCC30/salvohook_wdt_MCC30_clrwdt.c  -o ${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1297474772/salvohook_wdt_MCC30_clrwdt.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2044256807/salvomem.o: C:/Pumpkin/Salvo/Src/salvomem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2044256807" 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvomem.o.d 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvomem.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/salvomem.c  -o ${OBJECTDIR}/_ext/2044256807/salvomem.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2044256807/salvomem.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2044256807/salvomem.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2044256807/salvotime.o: C:/Pumpkin/Salvo/Src/salvotime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2044256807" 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvotime.o.d 
	@${RM} ${OBJECTDIR}/_ext/2044256807/salvotime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  C:/Pumpkin/Salvo/Src/salvotime.c  -o ${OBJECTDIR}/_ext/2044256807/salvotime.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2044256807/salvotime.o.d"        -g -omf=coff -O0 -I"../inc" -I"C:/Pumpkin/Library/PIC24/Inc" -I"C:/Pumpkin/Salvo/Inc/MCC30" -I"C:/Pumpkin/Salvo/Inc" -I"C:/Pumpkin/CubeSatKit/PIC24/inc" -DSUPMCU_GPSRM1_REVC=1 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2044256807/salvotime.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Pumpkin/Salvo/Lib/MCC30-v3/libsalvolmcc30sit.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\Pumpkin\Salvo\Lib\MCC30-v3\libsalvolmcc30sit.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=coff  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/Pumpkin/Salvo/Lib/MCC30-v3/libsalvolmcc30sit.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\Pumpkin\Salvo\Lib\MCC30-v3\libsalvolmcc30sit.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/GPS_QA.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
