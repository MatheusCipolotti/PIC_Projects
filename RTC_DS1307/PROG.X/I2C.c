#include <xc.h>

#include "I2C.h"
#include "defines.h"

void I2C_Init(void){
    TRISCbits.TRISC3 = 0x01;
    TRISCbits.TRISC4 = 0x01;
    SSPCON = 0b00101000;                                                        //Ativa o modo I2C (Mestre)
    SSPCON2 = 0b00000000;
    SSPADD = (_XTAL_FREQ / (4 * I2C_SPEED_STANDARD_100KHZ)) - 1;                //Configura a taxa de 100kHz
    SSPSTAT = 0b00000000;
}

void I2C_Wait(void){
    while ((SSPCON2 & 0x1F) || (SSPSTATbits.R_nW));                             //Espera flag liberar (Start, Repeat Start, Stop, Receive, Acknowledge)
}                                                                               //e aguarda transmissao finalizar


void I2C_Start(void){
    I2C_Wait();
    SSPCON2bits.SEN = 1;                                                        
}

void I2C_Restart(void){
    I2C_Wait();
    SSPCON2bits.RSEN = 1;                                                       
}

void I2C_Stop(void){
    I2C_Wait();
    SSPCON2bits.PEN = 1;
}

void I2C_Write(unsigned char data){
    I2C_Wait();
    SSPBUF = data;
}

unsigned char I2C_Read(bool acknowledge){
    unsigned char read_data;
    
    I2C_Wait();
    SSPCON2bits.RCEN = 1;
    I2C_Wait();
    read_data = SSPBUF;
    
    I2C_Send_ACK(acknowledge);
    
    return read_data;
}

void I2C_Send_ACK(bool ack){
    I2C_Wait();
    SSPCON2bits.ACKDT = ack;                                                    //Le acknowledge
    SSPCON2bits.ACKEN = 1;                                                      //Envia acknowledge
}

bool I2C_Read_ACK(void){
    I2C_Wait();
    return (SSPCON2bits.ACKSTAT);
}