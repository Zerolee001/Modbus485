/*
 * A simple example of json string parsing with json-c.
 *
 */
#include "json.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

//#include "unit-rtu.h"
//#include "modbus.h"
//#include "jsonParse.h"

int main(void)
{
	/*long int count = 0;
	
	jsonParse_init_Data();

	printf("This json demo!!\n");

	
	jsonParse_Get_Data("RS485_CH1", NULL);

	while(1)
	{
		printf("%d\n", count);
		usleep(200000);
		jsonParse_Get_Data("RS485_CH2", NULL);
	}*/
	
	//Modbus485_init(NULL);

	Modbus485_4ChDimmer_Device_Scan();

	while(1);
	
	return 0;
}
