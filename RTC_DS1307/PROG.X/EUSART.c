#include <xc.h>

#include "EUSART.h"

void UART_Init(void){
    TRISCbits.TRISC7 = 0x01;
    TRISCbits.TRISC6 = 0x00;
    PORTCbits.RC7 = 0x00;
    PORTCbits.RC6 = 0x00;
    
    SPBRG = 31;                                                                 //(Assincrono) Baud Rate = Fosc/(64(X+1))
    TXSTAbits.SYNC = 0;                                                         //Configura modo assincrono
    TXSTAbits.TXEN = 1;                                                         //Ativa envio de dados
    RCSTAbits.SPEN = 1;                                                         //Ativar a porta Serial
    RCSTAbits.CREN = 1;                                                         //Ativa o recebimento de dados
}

void UART_Write(const char data){
    while(!TRMT);
    TXREG = data;
}

void UART_Write_ln(const char data){
    UART_Write(data);
    UART_Write('\r');
    UART_Write('\n');
}

void UART_Write_Text(const char text[]){
    int i;
    for(i=0;text[i]!='\0';i++){
        UART_Write(text[i]);        
    }
}

void UART_Write_Text_ln(const char text[]){
    UART_Write_Text(text);
    UART_Write('\r');
    UART_Write('\n');   
}

char UART_Read(void){
    while(!RCIF);
    return RCREG;
}

void UART_Read_Text(char *Output, const unsigned int lenght){
    for(unsigned int i = 0; i<lenght; i++){
        Output[i] = UART_Read();
    }
    Output[lenght]='\0';
}