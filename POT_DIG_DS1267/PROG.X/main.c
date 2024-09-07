/*
 * Autor: Matheus Dantas Cipolotti
 * 
 * Controle potenciometro digital DS1267 via SPI
 * 
*/

#include "config.h"
#include "DS1267.h"
#include <xc.h>

#define _XTAL_FREQ 20000000

unsigned char valor = 0x7F;

void main(void) {
    CMCON = 0x07;               //Desabilita os comparadores internos
    
    TRISC = 0x00;               //TRISC como saida digital
    PORTC = 0x10;               //SPI_SDO inicia em nível logico 1
    
    //Configuracao SPI
    SSPSTAT = 0x00;
    SSPCON = 0x20;              //SSPEN ativo, SPI mestre, FOSC/4
    
    while(1){
        ds1267_set_pot(valor, valor);  //Atualizacao do valor dos potenciometros
        __delay_ms(10);
        valor++;
        
        if(valor >= 0xFF){
            valor = 0x00;
        }
    }
}
