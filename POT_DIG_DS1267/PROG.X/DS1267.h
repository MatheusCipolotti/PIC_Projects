#ifndef __DS1267
    #define __DS1267

    #include <xc.h>
    #define _XTAL_FREQ 20000000

    void ds1267_set_pot(unsigned char data1, unsigned char data2);

#endif