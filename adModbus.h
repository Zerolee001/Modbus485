#ifndef __ADMODBUS_H__
#define __ADMODBUS_H__

#include "DeviceScan.h"

/**
 * \brief		    Get the Modbus485 driver library version string
 *
 * param string		the version string
 *
 * \return          None
 */
void Modbus485_get_version_string(char *string);

/**
 * \brief		    Get the Modbus485 state
 *
 * \return          the current Modbus485 state, return Modbus485_STATE_MAX if context invalid
 */
Modbus485_STATE Modbus485_get_current_state(void *ctx);

/**
 * \brief               Modbus485 init function
 *
 * \param EventHandler  the teach-in event callback handler, this function creates
 *                      the Modbus485 context, so it should be called first
 *
 * \return              Modbus485 context, NULL if failed
 */
void *Modbus485_init(Modbus485_RUN_EVENT_HANDLER *EventHandler);

/**
 * \brief               Modbus485 de-init function
 *
 * \param ctx           Modbus485 config context
 *
 * \return              Modbus485 config context, NULL if failed
 */
int Modbus485_deinit(void *ctx);

/**
 * \brief               Modbus485 config operation event handler registration
 *                      this function must be called after Modbus485_init called
 *
 * \param EventHandler  the config related event callback handler 
 * \param Src			the event callback handler source, 0 for WEB, 1 for LED/Button tool
 *
 * \return              Modbus485 context, NULL if failed
 */
void *Modbus485_CFG_register(Modbus485_CFG_EVENT_HANDLER *EventHandler, int Src);
//void *Modbus485_CFG_register(void *ctx, Modbus485_CFG_EVENT_HANDLER *EventHandler, int Src);

/**
 * \brief               Modbus485 register activity event handler
 *                      current event includes Modbus485 Tx or Rx activities
 *                      this function must be called after Modbus485_init called
 *
 * \param EventHandler  the activity related event callback handler 
 *
 * \return              Modbus485 context, NULL if failed
 */
//void *Modbus485_ACT_register(Modbus485_ACT_EVENT_HANDLER *EventHandler);

/**
 * \brief           Modbus485 starter function
 *
 * \param ctx       the Modbus485 context
 *
 * \return          0 if successful
 */
int Modbus485_start(void *ctx);

/**
 * \brief           Modbus485 stopper function
 *
 * \param ctx       the Modbus485 context
 *
 * \return          0 if successful
 */
int Modbus485_stop(void *ctx);

/**
 * \brief               Modbus485 acuator set function
 *
 * \param ctx           the Modbus485 context
 * \param type          the acuator type, 1 for dimming acuator (D2-01-02/D2-01-03) 2 for shutter acuator (A5-11-07)
 * \param channel       the channel to set
 * \param subchannel    the subchannel to set
 * \param func          the function to set
 * \param data	        set data
 *
 * \return          0 if successful
 */
int Modbus485_set(void *ctx, uint8_t type, uint8_t channel, uint8_t subchannel, uint8_t func, uint32_t data);


//
int Modbus485_4ChDimmer_Device_Scan(int Ch, Modbus485_DEVICE_SCAN_HANDLER *pfScan, STR_DEVICE_SCAN* pStrData);

#endif

