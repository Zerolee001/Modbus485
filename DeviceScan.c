#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include "unit-rtu.h"
#include "DeviceScan.h"
#include "modbus.h"
#include "adModbus_def.h"
#include "adModbus.h"

pthread_t pthread_Scan_Device; //max 6 thread
static void* Device_Scan_Process(void* arg);
static STR_DEVICE_SCAN* pSt_DeviceOCF;

Modbus485_DEVICE_SCAN_HANDLER* pf_DeviceScan_Callback;

int DeciceScan_Init_Thread(int Ch, Modbus485_DEVICE_SCAN_HANDLER *pfScan,  STR_DEVICE_SCAN* pStrData)
{
	if(Ch >= 6)
	{
		printf("Ch is not right, can't create Device scan thread\n");
		return -1;
	}

	if (pthread_create(&pthread_Scan_Device, NULL, Device_Scan_Process, (void *)&Ch) != 0)
	{
		printf("Fail to Create decice scan pthread success\n");
		return -1;
	}

	pf_DeviceScan_Callback = pfScan;
	pSt_DeviceOCF = pStrData;
	pSt_DeviceOCF->Total = 0;

	printf("Create device scan pthread success\n");

	return 0;
}

void * Device_Scan_Process(void* arg)
{
	int *pdata;
	modbus_t *ctx;
    modbus_mapping_t *mb_mapping;
    uint16_t Address;
    int rc;
    char i;

	pdata = arg;

	printf("Ch is%d\n", *pdata);
	ctx = modbus_new_rtu(pRS485_Channel_Description[(*pdata)], 115200, 'N', 8, 1);
	
	modbus_set_debug(ctx, TRUE);


	mb_mapping = (modbus_mapping_t *)modbus_mapping_new(0, 0, 10, 0);
	if(mb_mapping == NULL)
	{
		fprintf(stderr, "Failed to allocate the mapping: %s\n", modbus_strerror(errno));
		modbus_free(ctx);
		return;
	}

	pSt_DeviceOCF->Total = 0;
	
	while(1)
	{
		for(i = 0; i < MAX_4CHDIMMER_NUMBER; i++)
		{
			modbus_set_slave(ctx, i+1);
			rc = modbus_connect(ctx);
			if (rc == -1) 
			{
        		fprintf(stderr, "Unable to connect %s\n", modbus_strerror(errno));
        		break;
    		}

    		rc = modbus_read_registers(ctx, 0, 1, &Address);
    		if(rc == -1)
    		{
    			fprintf(stderr, "Unable to connect %s\n", modbus_strerror(errno));
        		break;
    		}
    		pSt_DeviceOCF->Total++;
    		pSt_DeviceOCF->SlaveAddr[i] = (char)Address;
    		printf("Slave address is %d\n", pSt_DeviceOCF->SlaveAddr[i]);
		}
	}

	modbus_mapping_free(mb_mapping);
	modbus_free(ctx);


	//pf_DeviceScan_Callback();

	//call callback function
	//设置取消类型为延时取消
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	//设置取消状态为可以取消
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    if(pthread_cancel(pthread_self()) == 0)
    {
    	printf("Cancel scan device thread success\n");
    }

    pthread_exit((void *)0);

    return;
}

