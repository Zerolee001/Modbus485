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
#include "Ch5process.h"

static pthread_t pthread_Ch5_485_Process;
static void* Ch5_485_Process(void* arg);



void Ch5process_Create_Thread(void)
{
    printf("Begin to create RS485 Ch5 Thread\n");
    //if (pthread_create(&pthread_Ch5_485_Process, NULL, Ch5_485_Process, NULL) != 0)
    {
        //printf("Fail to create Ch5 thread!\n");
    }
}


void* Ch5_485_Process(void* arg)
{
	while(1)
	{
		sleep(1);
		printf("Thread5 is running\n");
	}
}