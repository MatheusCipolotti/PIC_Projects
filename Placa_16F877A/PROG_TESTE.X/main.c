/*
Software de teste da Placa 16f877A 
*/

#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 20000000

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

void main(void) {
    CMCON = 0x07;
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x80;
    TRISD = 0x00;
    TRISE = 0x00;
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;
    
    SPBRG = 31;             //(Assincrono) Baud Rate = Fosc/(64(X+1))
    TXSTAbits.SYNC = 0;     //Configura modo assincrono
    TXSTAbits.TXEN = 1;     //Ativa envio de dados
    RCSTAbits.SPEN = 1;     //Ativar a porta Serial
    RCSTAbits.CREN = 1;     //Ativa o recebimento de dados

    while(1){
        UART_Write_Text_ln("teste");
        PORTBbits.RB5 = 1;
        __delay_ms(500);
        UART_Write_Text_ln("teste");
        PORTBbits.RB5 = 0;
        __delay_ms(500);
    }
}
