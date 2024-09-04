#ifndef DS1307_H
#define	DS1307_H

#include <xc.h> // include processor files - each processor file is guarded.  

void RTC_Init(void);
void RTC_Set_Time(unsigned char second, unsigned char minute, unsigned char hour,
        unsigned char dayweek, unsigned char day, unsigned char month, 
        unsigned char year);
void RTC_Get_Time(unsigned char *second, unsigned char *minute, 
        unsigned char *hour, unsigned char *dayweek, unsigned char *day, 
        unsigned char *month, unsigned char *year);

#endif

