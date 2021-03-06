#ifndef SYS_STATE_SERVICE_H_
#define SYS_STATE_SERVICE_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "prod_defs.h"

typedef struct{
	Uint16 high8bit : 8;
	Uint16 low8bit	: 8;
}VAR16BIT;
typedef struct _ERROR_16BIT
{
	Uint16 software : 1;
	Uint16 init : 1;
	Uint16 temperature : 1;
	Uint16 busVoltage : 1;
	Uint16 busCurrent : 1;
	Uint16 hardware : 1;
	Uint16 memoryFull : 1;
	Uint16 rxQFull : 1;
	Uint16 txQFull : 1;
	Uint16 j : 1;
	Uint16 k : 1;
	Uint16 l : 1;
	Uint16 m : 1;
	Uint16 n : 1;
	Uint16 o : 1;
	Uint16 p : 1;
}ERROR_16BIT;
typedef struct _ALARM_16BIT
{
	Uint16 software     : 1;
	Uint16 init         : 1;
	Uint16 temperature  : 1;
	Uint16 busVoltage   : 1;
	Uint16 busCurrent   : 1;
	Uint16 hardware     : 1;
	Uint16 pgVdd3V3     : 1;
	Uint16 pg1v9        : 1;
	Uint16 pgVcc3V3     : 1;
	Uint16 j            : 1;
	Uint16 k            : 1;
	Uint16 l            : 1;
	Uint16 m            : 1;
	Uint16 n            : 1;
	Uint16 o            : 1;
	Uint16 p            : 1;
}ALARM_16BIT;

typedef struct _WARINING_16BIT
{
	Uint16 software     : 1;
	Uint16 init         : 1;
	Uint16 temperature  : 1;
	Uint16 busVoltage   : 1;
	Uint16 busCurrent   : 1;
	Uint16 hardware     : 1;
	Uint16 g : 1;
	Uint16 h : 1;
	Uint16 i : 1;
	Uint16 j : 1;
	Uint16 k : 1;
	Uint16 l : 1;
	Uint16 m : 1;
	Uint16 n : 1;
	Uint16 o : 1;
	Uint16 p : 1;
}WARINING_16BIT;

typedef union
{
	Uint16          all;
	VAR16BIT        data;
	ERROR_16BIT     bit;
}SYSERRO;

typedef union
{
	Uint16          all;
	VAR16BIT        data;
	WARINING_16BIT  bit;
}SYSWARNING;

typedef union
{
	Uint16          all;
	VAR16BIT        data;
	ALARM_16BIT     bit;
}SYSALARM;



typedef enum _ROTATE_DIRECTION
{
    STOP,
    FORWARD,
    BACKWARD
}ROTATE_DIRECTION;

typedef enum _SYS_RUNNING_STATE
{
    SYS_INIT,
    SYS_FORWARD_RUN,
    SYS_BACKWARD_RUN,
    SYS_STOP,
    SYS_ALARM,
    SYS_WARNING
    
}SYS_RUNNING_STATE;

typedef struct _SYS_STATE_FLAG
{
    ROTATE_DIRECTION rotateDirectoin;
    SYSALARM alarm;
	SYSWARNING warning;
	SYSERRO error;
    SYS_RUNNING_STATE sysRunningState;
    /* data */
}SYS_STATE_FLAG;



#define SET_SYS_RUNNING_STATE_INIT                      (gSysStateFlag.sysRunningState = SYS_INIT)
#define SET_SYS_RUNNING_STATE_FORWARD_RUN               (gSysStateFlag.sysRunningState = SYS_FORWARD_RUN)
#define SET_SYS_RUNNING_STATE_BACKWARD_RUN              (gSysStateFlag.sysRunningState = SYS_BACKWARD_RUN)
#define SET_SYS_RUNNING_STATE_STOP                      (gSysStateFlag.sysRunningState = SYS_STOP)
#define SET_SYS_RUNNING_STATE_ALARM                     (gSysStateFlag.sysRunningState = SYS_ALARM)
#define SET_SYS_RUNNING_STATE_WARNING                   (gSysStateFlag.sysRunningState = SYS_WARNING)


#define SOFTWARE_ALARM_MASK                             BIT0
#define INIT_ALARM_MASK                                 BIT1
#define TEMPERATURE_ALARM_MASK                          BIT2
#define BUS_VOLTAGE_ALARM_MASK                          BIT3
#define BUS_CURRENT_ALARM_MASK                          BIT4
#define HARDWARE_ALARM_MASK                             BIT5
#define POWER_GOOD_VDD3V3_MASK                          BIT6
#define POWER_GOOD_1V9_MASK                             BIT7
#define POWER_GOOD_VCC3V3_MASK                          BIT8



#define IS_SYS_ENABLE_FORWARD_ROTATE                    (gSysStateFlag.rotateDirectoin == FORWARD)
#define IS_SYS_ENABLE_BACKWARD_ROTATE                   (gSysStateFlag.rotateDirectoin == BACKWARD)
#define IS_SYS_ALARM                                    (gSysStateFlag.alarm.all)
#define IS_SYS_WARNING                                  (gSysStateFlag.warning.all)
#define CLEAR_SYS_ALARM                                 (gSysStateFlag.alarm.all = 0)
#define CLEAR_SYS_WARNING                               (gSysStateFlag.warning.all = 0)
#define CLEAR_SYS_ERROR                                 (gSysStateFlag.error.all = 0)

#define INIT_SYS_RUNNING_STATE                           (gSysStateFlag.sysRunningState = SYS_INIT)
#define INIT_SYS_ROTATE_DIRECTION                        (gSysStateFlag.rotateDirectoin = STOP)



#define SET_SYS_SOFTWARE_ALARM                          (gSysStateFlag.alarm.bit.software = 1)
#define CLEAR_SYS_SOFTWARE_ALARM                        (gSysStateFlag.alarm.bit.software = 0)
#define IS_SYS_SOFTWARE_ALARM                           (gSysStateFlag.alarm.bit.software | SOFTWARE_ALARM_MASK)


#define SET_SYS_INIT_ALARM                              (gSysStateFlag.alarm.bit.init = 1)
#define CLEAR_SYS_INIT_ALARM                            (gSysStateFlag.alarm.bit.init = 0)
#define IS_SYS_INIT_ALARM                               (gSysStateFlag.alarm.bit.init | INIT_ALARM_MASK)


#define SET_SYS_TEMPERATURE_ALARM                       (gSysStateFlag.alarm.bit.temperature = 1)
#define CLEAR_SYS_TEMPERATURE_ALARM                     (gSysStateFlag.alarm.bit.temperature = 0)
#define IS_SYS_TEMPERATURE_ALARM                        (gSysStateFlag.alarm.bit.temperature | TEMPERATURE_ALARM_MASK)

#define SET_SYS_BUS_VOLTAGE_ALARM                       (gSysStateFlag.alarm.bit.busVoltage = 1)
#define CLEAR_SYS_BUS_VOLTAGE_ALARM                     (gSysStateFlag.alarm.bit.busVoltage = 0)
#define IS_SYS_BUS_VOLTAGE_ALARM                        (gSysStateFlag.alarm.bit.busVoltage | BUS_VOLTAGE_ALARM_MASK)


#define SET_SYS_BUS_CURRENT_ALARM                       (gSysStateFlag.alarm.bit.busCurrent = 1)
#define CLEAR_SYS_BUS_CURRENT_ALARM                     (gSysStateFlag.alarm.bit.busCurrent = 0)
#define IS_SYS_BUS_CURRENT_ALARM                        (gSysStateFlag.alarm.bit.busCurrent | BUS_CURRENT_ALARM_MASK)


#define SET_SYS_HARDWARE_ALARM                          (gSysStateFlag.alarm.bit.hardware = 1)
#define CLEAR_SYS_HARDWARE_ALARM                        (gSysStateFlag.alarm.bit.hardware = 0)
#define IS_SYS_HARDWARE_ALARM                           (gSysStateFlag.alarm.bit.hardware | HARDWARE_ALARM_MASK)

#define SET_SYS_PG_VDD3V3_ALARM                         (gSysStateFlag.alarm.bit.pgVdd3V3 = 1)
#define CLEAR_SYS_PG_VDD3V3_ALARM                       (gSysStateFlag.alarm.bit.pgVdd3V3 = 0)
#define IS_SYS_PG_VDD3V3_ALARM                          (gSysStateFlag.alarm.bit.pgVdd3V3 | POWER_GOOD_VDD3V3_MASK)

#define SET_SYS_PG_1V9_ALARM                            (gSysStateFlag.alarm.bit.pg1v9 = 1)
#define CLEAR_SYS_PG_1V9_ALARM                          (gSysStateFlag.alarm.bit.pg1v9 = 0)
#define IS_SYS_PG_1V9_ALARM                             (gSysStateFlag.alarm.bit.pg1v9 | POWER_GOOD_1V9_MASK)

#define SET_SYS_PG_VCC3V3_ALARM                         (gSysStateFlag.alarm.bit.pgVcc3V3 = 1)
#define CLEAR_SYS_PG_VCC3V3_ALARM                       (gSysStateFlag.alarm.bit.pgVcc3V3 = 0)
#define IS_SYS_PG_VCC3V3_ALARM                          (gSysStateFlag.alarm.bit.pgVcc3V3 | POWER_GOOD_VCC3V3_MASK)


#define SET_SYS_MEMORY_MOLLOC_ERROR                     (gSysStateFlag.error.bit.memoryFull = 1)
#define CLEAR_SYS_MEMORY_MOLLOC_ERROR                   (gSysStateFlag.error.bit.memoryFull = 0)
#define IS_SYS_MEMORY_MOLLOC_ERROR                      (gSysStateFlag.error.bit.memoryFull | BIT6)

#define SET_SYS_RX_QUEUE_FULL_ERROR                     (gSysStateFlag.error.bit.rxQFull = 1)
#define CLEAR_SYS_RX_QUEUE_FULL_ERROR                   (gSysStateFlag.error.bit.rxQFull = 0)
#define IS_SYS_RX_QUEUE_FULL_ERROR                      (gSysStateFlag.error.bit.rxQFull | BIT7)

#define SET_SYS_TX_QUEUE_FULL_ERROR                     (gSysStateFlag.error.bit.txQFull = 1)
#define CLEAR_SYS_TX_QUEUE_FULL_ERROR                   (gSysStateFlag.error.bit.txQFull = 0)
#define IS_SYS_TX_QUEUE_FULL_ERROR                      (gSysStateFlag.error.bit.txQFull | BIT8)

#define SYS_STATE_MACHINE								(*Sys_hlstPtr)()
extern void (*Sys_hlstPtr)(void);
void Init_Sys_State_Service(void);
extern SYS_STATE_FLAG gSysStateFlag;
#endif
