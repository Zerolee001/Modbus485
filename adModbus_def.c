#include "Ch0process.h"
#include "Ch1process.h"
#include "Ch2process.h"
#include "Ch3process.h"
#include "Ch4process.h"
#include "Ch5process.h"

//point to the hardware resouce
const char *pRS485_Channel_Description[] = {
	"/dev/ttyS1",
	"/dev/ttyS3",
	"/dev/ttyXRUSB0",
	"/dev/ttyXRUSB1",
	"/dev/ttyXRUSB2",
	"/dev/ttyXRUSB3"
};

//point to the thread init function
void (*pfRS485_Thread_Init[])(void) = {
	Ch0process_Create_Thread,
	Ch1process_Create_Thread,
	Ch2process_Create_Thread,
	Ch3process_Create_Thread,
	Ch4process_Create_Thread,
	Ch5process_Create_Thread,
};
