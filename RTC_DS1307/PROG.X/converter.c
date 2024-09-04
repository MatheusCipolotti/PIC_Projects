#include <xc.h>

#include "converter.h"

unsigned char BCD_to_DEC(unsigned char bcd){
    return ((bcd / 16 * 10) + (bcd % 16));
}

unsigned char DEC_to_BCD(unsigned char dec){
    return ((dec / 10 * 16) + (dec % 10));
}

unsigned char DEC_to_ASCII(unsigned char dec){
    return dec + 0x30;
}

unsigned char ASCII_to_DEC(unsigned char dec){
    return dec - 0x30;
}
