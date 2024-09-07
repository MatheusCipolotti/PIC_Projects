#include "DS1267.h"
#include "SPI.h"

// Função para configurar o DS1267
void ds1267_set_pot(unsigned char data1, unsigned char data2){
    spi_cs_status(0x01);        //Pino de seleção do chip ativo
    spi_send(0x01);             //Envia o comando
    spi_send(data1);            //Envia os dados do primeiro potenciometro
    spi_send(data2);            //Envia os dados do segundo potenciometro
    spi_cs_status(0x00);        //Pino de seleção do chip inativo
}