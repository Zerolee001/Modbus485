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
#include "Ch3process.h"

static pthread_t pthread_Ch3_485_Process;
static void* Ch3_485_Process(void* arg);



void Ch3process_Create_Thread(void)
{
    printf("Begin to create RS485 Ch3 Thread\n");
    //if (pthread_create(&pthread_Ch3_485_Process, NULL, Ch3_485_Process, NULL) != 0)
    {
        //printf("Fail to create Ch3 thread!\n");
    }
}


void* Ch3_485_Process(void* arg)
{
	while(1)
	{
		sleep(1);
		printf("Thread3 is running\n");
	}
}