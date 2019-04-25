#ifndef RTC_
#define RTC_

#include <avr/io.h>
#include <avr/delay.h>

struct rtc{
   char sec;
   char min;
   char hour;
   char day;
   char month;
   char year;
   char wd;
   };

void rtcInit(void);
void rtcSetTime(char hour, char min, char sec);
void rtcSetDate(char day, char month, char year, char wd);
void rtcGetAll(struct rtc * clock);
void rtcWrite(char * data, char address);
void rtcRead(char * data, char address);
#endif