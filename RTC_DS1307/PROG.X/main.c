/*
 * Interface DS1307
 */

#include <xc.h>

#include "defines.h"
#include "configs.h"
#include "defines.h"
#include "I2C.h"
#include "EUSART.h"
#include "DS1307.h"
#include "converter.h"

char uart_rd;

void Get_RTC(void);
void Write_RTC(void);

void main(void){
    CMCON = 0x07;
    
    UART_Init();
    __delay_ms(50);
    I2C_Init();
    __delay_ms(50);
    RTC_Init();
    
    while(1){
        uart_rd = UART_Read();
        
        switch(uart_rd){
            case 'H':
                Get_RTC();
                break;
            case 'V':
                Write_RTC();
                break;    
        }
    }
}

//Funcao de Menu e Leitura dos dados do RTC
void Get_RTC(void){
    unsigned char RC_Seconds = 0, RC_Minuts = 0,RC_Hour = 0, RC_Dayweek = 0,
            RC_Day = 0, RC_Month = 0, RC_Year = 0;
    
    RTC_Get_Time(&RC_Seconds, &RC_Minuts, &RC_Hour, &RC_Dayweek, &RC_Day, 
            &RC_Month, &RC_Year);
    
    UART_Write('(');
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Day / 16)));                          
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Day % 16)));
    UART_Write('/');
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Month / 16)));
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Month % 16)));
    UART_Write('/');
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Year / 16)));
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Year % 16)));
    UART_Write(')');
    
    switch(RC_Dayweek){
        case 0x01:
            UART_Write_Text(" Domingo ");
            break;
        case 0x02:
            UART_Write_Text(" Segunda Feira ");
            break;
        case 0x03:
            UART_Write_Text(" Terca Feira ");
            break;
        case 0x04:
            UART_Write_Text(" Quarta Feira ");
            break;
        case 0x05:
            UART_Write_Text(" Quinta Feira ");
            break;
        case 0x06:
            UART_Write_Text(" Sexta Feira ");
            break;
        case 0x07:
            UART_Write_Text(" Sabado ");
            break;
    }
    
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Hour / 16)));                         
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Hour % 16)));                         
    UART_Write(':');
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Minuts / 16)));                       
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Minuts % 16)));                       
    UART_Write(':');
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Seconds / 16)));                      
    UART_Write(DEC_to_ASCII(BCD_to_DEC(RC_Seconds % 16)));                      
    UART_Write('\r');                                                           
    UART_Write('\n');
}

//Funcao de Menu e Gravacao do RTC
void Write_RTC(void){
    unsigned char hour_tens, hour_units, min_tens, min_units, sec_tens, 
            sec_units, dia_tens, dia_units, mes_tens, mes_units, ano_tens, 
            ano_units, dia_semana;
    
    // Recebe Dia
    UART_Write_Text_ln("Digite o dia: ");
    dia_tens = ASCII_to_DEC(UART_Read());                                       
    dia_units = ASCII_to_DEC(UART_Read());                                      
    UART_Read();                                                                

    // Recebe Mes
    UART_Write_Text_ln("Digite o mes: ");
    mes_tens = ASCII_to_DEC(UART_Read());                                       
    mes_units = ASCII_to_DEC(UART_Read());                                      
    UART_Read();                                                                

    // Recebe Ano
    UART_Write_Text_ln("Digite o ano: ");
    ano_tens = ASCII_to_DEC(UART_Read());                                       
    ano_units = ASCII_to_DEC(UART_Read());                                      
    
    // Recebe o dia da semana
    UART_Write_Text_ln("Digite o numero correspondente ao dia da semana: ");
    UART_Write_Text_ln("1 - Domingo");
    UART_Write_Text_ln("2 - Segunda Feira ");
    UART_Write_Text_ln("3 - Terca Feira ");
    UART_Write_Text_ln("4 - Quarta Feira ");
    UART_Write_Text_ln("5 - Quinta Feira ");
    UART_Write_Text_ln("6 - Sexta Feira ");
    UART_Write_Text_ln("7 - Sabado ");
    dia_semana = ASCII_to_DEC(UART_Read());
    
    // Recebe Hora
    UART_Write_Text_ln("Digite a Hora: ");
    hour_tens = ASCII_to_DEC(UART_Read());
    hour_units = ASCII_to_DEC(UART_Read());
    UART_Read();

    // Recebe Minutos
    UART_Write_Text_ln("Digite os minutos: ");
    min_tens = ASCII_to_DEC(UART_Read());
    min_units = ASCII_to_DEC(UART_Read());
    UART_Read();

    // Recebe Segundos
    UART_Write_Text_ln("Digite os segundos: ");
    sec_tens = ASCII_to_DEC(UART_Read());
    sec_units = ASCII_to_DEC(UART_Read());

    unsigned char dia = DEC_to_BCD((dia_tens * 10) + dia_units);
    unsigned char mes = DEC_to_BCD((mes_tens * 10) + mes_units);
    unsigned char ano = DEC_to_BCD((ano_tens * 10) + ano_units);
    unsigned char hour = DEC_to_BCD((hour_tens * 10) + hour_units);
    unsigned char min = DEC_to_BCD((min_tens * 10) + min_units);
    unsigned char sec = DEC_to_BCD((sec_tens * 10) + sec_units); 
    
    RTC_Set_Time(sec, min, hour, dia_semana, dia, mes, ano);
    
    UART_Write_Text_ln("Relogio configurado");
}