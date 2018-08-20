#include <pthread.h>
#include "Rescource.h"

static pthread_mutex_t lock;

//CHAIR_STATE ChairState;


void Rescource_Init_Data(void)
{
	
}


void Rescource_Set_Data(unsigned char Index, void *pData)
{
	pthread_mutex_lock(&lock);


	pthread_mutex_unlock(&lock);
}

unsigned long Rescource_Get_Data(unsigned char Index, void* pData)
{
	
}