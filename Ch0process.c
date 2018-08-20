#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include "json.h"
#include "unit-rtu.h"
#include "adModbus_def.h"
#include "adModbus.h"
#include "Ch0process.h"

static pthread_t pthread_Ch0_485_Process;
static void* Ch0_485_Process(void* arg);



void Ch0process_Create_Thread(void)
{
    printf("Begin to create RS485 ch0 Thread\n");
    //if (pthread_create(&pthread_Ch0_485_Process, NULL, Ch0_485_Process, NULL) != 0)
    {
        //printf("Fail to create Ch0 thread!\n");
    }
}


void* Ch0_485_Process(void* arg)
{
	while(1)
	{
		sleep(1);
		printf("Thread0 is running\n");
	}
}