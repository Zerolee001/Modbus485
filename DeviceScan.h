#ifndef __DEVICESCAN_H__
#define __DEVICESCAN_H__

//address 0 is broadcast
#define MAX_4CHDIMMER_NUMBER      31

typedef struct{
    int Total;  //Total number of Slave device
    char SlaveAddr[MAX_4CHDIMMER_NUMBER]; //Slave device address
}STR_DEVICE_SCAN;

typedef void Modbus485_DEVICE_SCAN_HANDLER(STR_DEVICE_SCAN *pstr_Scan);


int DeciceScan_Init_Thread(int Ch, Modbus485_DEVICE_SCAN_HANDLER *pfScan,  STR_DEVICE_SCAN* pStrData);

#endif
