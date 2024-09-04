#ifndef EUSART_H
    #define EUSART_H

    #include <xc.h>
    #include "defines.h"
    
    void UART_Init(void);
    void UART_Write(const char data);
    void UART_Write_ln(const char data);
    void UART_Write_Text(const char text[]);
    void UART_Write_Text_ln(const char text[]);
    char UART_Read(void);
    void UART_Read_Text(char *Output, const unsigned int lenght);

#endif