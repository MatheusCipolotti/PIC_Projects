#ifndef CONVERTER_H
#define	CONVERTER_H

#include <xc.h>

unsigned char BCD_to_DEC(unsigned char bcd);
unsigned char DEC_to_BCD(unsigned char dec);
unsigned char DEC_to_ASCII(unsigned char dec);
unsigned char ASCII_to_DEC(unsigned char dec);

#endif