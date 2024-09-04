#include <xc.h>

#include "DS1307.h"
#include "defines.h"
#include "I2C.h"

void RTC_Init(void){
    I2C_Start();
    
    I2C_Write(0xD0);                                                            //Address 0x68 + bit 0x00
    I2C_Write(0x07);                                                            //Seleciona registro de controle do DS1307
    I2C_Write(0x10);                                                            //Escreve 0x10 no registro de controle para
                                                                                //Ter no pino SQW-Out 1HZ
    I2C_Stop();
    
    __delay_ms(50);
}

void RTC_Set_Time(unsigned char second, unsigned char minute, unsigned char hour,
        unsigned char dayweek, unsigned char day, unsigned char month, 
        unsigned char year){
    I2C_Start();
    
    I2C_Write(0xD0);                                                            //Address 0x68 + bit 0x00
    I2C_Write(0x00);                                                            //Seleciona registro de controle do DS1307
    
    I2C_Write(second & 0x7F);                                                   //Define segundos e Habilita o cristal
    I2C_Write(minute);
    I2C_Write(hour);
    I2C_Write(dayweek);
    I2C_Write(day);
    I2C_Write(month);
    I2C_Write(year);
    
    I2C_Stop();
}

void RTC_Get_Time(unsigned char *second, unsigned char *minute, 
        unsigned char *hour, unsigned char *dayweek, unsigned char *day, 
        unsigned char *month, unsigned char *year){
    I2C_Start();
    
    I2C_Write(0xD0);
    I2C_Write(0x00);
    
    I2C_Stop();
    
    I2C_Start();
    
    I2C_Write(0xD1);
    
    *second = I2C_Read(ACK);                                                    
    *minute = I2C_Read(ACK);                                                    
    *hour = I2C_Read(ACK);
    *dayweek = I2C_Read(ACK);
    *day = I2C_Read(ACK);
    *month = I2C_Read(ACK);
    *year = I2C_Read(NACK);
    
    I2C_Stop();
}