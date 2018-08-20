#ifndef __ADMODBUS_DEF_H__
#define __ADMODBUS_DEF_H__

typedef enum
{
    Modbus485_STATE_STOP,
    Modbus485_STATE_RUNNING,
    Modbus485_STATE_CFG_TEACHIN,
    Modbus485_STATE_CFG_TEACHOUT,
    Modbus485_STATE_LISTEN,
    Modbus485_STATE_MAX
} Modbus485_STATE;

typedef enum
{        
    Modbus485_CFG_TEACHIN_SUCCESS,           // this event is not for direct-teachin
    Modbus485_CFG_TEACHOUT_SUCCESS,          // this event is not for direct-teachout
    Modbus485_CFG_TEACHIN_STOP_MAXDEVNUM,    // exit teach-in cause reaching max devices num in this channel
    Modbus485_CFG_TEACHOUT_STOP_MINDEVNUM,   // exit teach-out cause reaching there's no device in this gateway
    Modbus485_CFG_STATE_CHANGE,
    Modbus485_CFG_TEACHIN_STOP_TIMEOUT,      // exit teach-in cause timeout
    Modbus485_CFG_TEACHOUT_STOP_TIMEOUT      // exit teach-out cause timeout
} Modbus485_CFG_EVENT_TYPE;

typedef struct _ENOCEAN_EEP
{   
    uint8_t rorg;
    uint8_t func;
    uint8_t type;
} Modbus485_EEP;


typedef struct
{	
    uint32_t DevID;
    Modbus485_EEP eep;
    bool    IsSensor;    
    uint16_t    manufacturer;           // will report 0 if no profile info available in teachin
} Modbus485_DEV_DATA;

typedef struct
{
    uint8_t channel;
    uint8_t addr;
    Modbus485_CFG_EVENT_TYPE event_type;
    Modbus485_DEV_DATA event_data;
} Modbus_CFG_EVENT;


typedef struct
{    
    char resURI[64];
    uint32_t EnodevID;
    uint32_t value;
    float   value_float;    
} Modbus_RUN_EVENT;

typedef void Modbus485_CFG_EVENT_HANDLER(Modbus_CFG_EVENT *ENOCFGEvent);
typedef void Modbus485_RUN_EVENT_HANDLER(Modbus_RUN_EVENT *ENORUNEvent);


extern const char *pRS485_Channel_Description[];
extern void (*pfRS485_Thread_Init[])(void);

#endif
