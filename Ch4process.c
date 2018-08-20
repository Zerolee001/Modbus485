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
#include "Ch4process.h"

static pthread_t pthread_Ch4_485_Process;
static void* Ch4_485_Process(void* arg);



void Ch4process_Create_Thread(void)
{
    printf("Begin to create RS485 Ch4 Thread\n");
    //if (pthread_create(&pthread_Ch4_485_Process, NULL, Ch4_485_Process, NULL) != 0)
    {
        //printf("Fail to create Ch4 thread!\n");
    }
}


void* Ch4_485_Process(void* arg)
{
	while(1)
	{
		sleep(1);
		printf("Thread4 is running\n");
	}
}