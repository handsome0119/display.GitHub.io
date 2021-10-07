#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <reg52.h>

typedef unsigned int u16;
typedef unsigned char u8;
extern u16 display_date[6];
//extern u16 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void delay(u16 i);
void function_display(int b);
void display_1();
void display(int date);


#endif  //__DISPLAY_H__

