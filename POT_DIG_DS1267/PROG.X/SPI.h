#ifndef __SPI
    #define __SPI

    #include <xc.h>
    #define _XTAL_FREQ 20000000

    void spi_send(unsigned char data);
    void spi_cs_status(unsigned char status);
    
#endif
