#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "json.h"
#include "unit-rtu.h"
#include "adModbus_def.h"
#include "adModbus.h"
#include "Rescource.h"
#include "DeviceScan.h"

const char Modbus485_VERSION_STRING[] = {
	"1.0.0.1"
};

static Modbus485_RUN_EVENT_HANDLER *Modbus_EventHandler;

/**
 * \brief		    Get the Modbus485 driver library version string
 *
 * param string		the version string
 *
 * \return          None
 */
void Modbus485_get_version_string(char *string)
{
	memcpy(string, Modbus485_VERSION_STRING, sizeof(Modbus485_VERSION_STRING));    
}


/**
 * \brief               Modbus485 init function
 *
 * \param EventHandler  the teach-in event callback handler, this function creates
 *                      the Modbus485 context, so it should be called first
 *
 * \return              Modbus485 context, NULL if failed
 */
void *Modbus485_init(Modbus485_RUN_EVENT_HANDLER *EventHandler)
{

	struct json_object *topobj, *comInfo,*subcom,*comvalue;
	char *str = NULL;
	FILE *fp = NULL;
	int len;
	bool found;
	int temp;
	int i;


	Modbus_EventHandler = EventHandler;

	fp = fopen("/home/workspace/server/RS485.json", "r");
	if(fp == NULL)
	{
		fprintf(stderr, "fopen failed with msg is%s\n", strerror(errno));
	}
	printf("RS485 file open ok!\n");

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	rewind(fp);
	str = (char *)malloc(len);
	if(fread(str, 1, len, fp) < 0)
	{
		printf("fread error !!\n");
	}

	topobj = json_tokener_parse(str); 

	printf("Begin to parse\n");

	free(str);
	str = NULL;
	fclose(fp);

	//Begin to parse json
	found = json_object_object_get_ex(topobj, "comInfo", &comInfo);
	if(found)
	{
		printf("found comInfo\n");

		temp = json_object_array_length(comInfo);
		printf("Array count is %d\n", temp);

		for(i = 0; i < temp; i++)
		{
			subcom = json_object_array_get_idx(comInfo, i);

			found = json_object_object_get_ex(subcom, "com", &comvalue);
			if(found)
			{
				printf("com is %d\n", json_object_get_int(comvalue));
				pfRS485_Thread_Init[json_object_get_int(comvalue) -1]();
			}
		}
	}


	//Ch1process_Create_Thread();
}

/**
 * \brief               Modbus485 de-init function
 *
 * \param ctx           Modbus485 config context
 *
 * \return              Modbus485 config context, NULL if failed
 */
int Modbus485_deinit(void *ctx);





/*
 * \brief               Modbus485 Scan AD 4ch Dimmer controller
 *
 * \param pData         return the scaned device
 *
 * \return              retuen means the total number of device
*/
int Modbus485_4ChDimmer_Device_Scan(int Ch, Modbus485_DEVICE_SCAN_HANDLER *pfScan, STR_DEVICE_SCAN* pStrData)
{
	STR_DEVICE_SCAN Strdata;

	//if(DeciceScan_Init_Thread(Ch, pfScan, pStrData))
	if(DeciceScan_Init_Thread(0, NULL, &Strdata))
	{
		return 0;
	}

	return -1;
}
