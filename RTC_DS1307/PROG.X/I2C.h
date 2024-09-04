#ifndef I2C_H
#define	I2C_H

#include <xc.h>                                                                 //Include processor files - each processor file is guarded.  
#include <stdbool.h>

void I2C_Init(void);
void I2C_Wait(void);
void I2C_Start(void);
void I2C_Restart(void);
void I2C_Stop(void);
void I2C_Write(unsigned char data);
unsigned char I2C_Read(bool acknowledge);
void I2C_Send_ACK(bool ack);
bool I2C_Read_ACK(void);

#endif

