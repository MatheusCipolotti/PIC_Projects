#include "SPI.h"

#define CS_PIN      PORTCbits.RC0
#define SPI_SCK     PORTCbits.RC3
#define SPI_SDO     PORTCbits.RC5

// Fun��o para enviar um byte via SPI
void spi_send(unsigned char data){
    SSPBUF = data;
    while(!SSPSTATbits.BF);     //Aguarda a transmiss�o ser conclu�da
}

//Fun��o de controle do Chip Selector
void spi_cs_status(unsigned char status){
    CS_PIN = status;
}