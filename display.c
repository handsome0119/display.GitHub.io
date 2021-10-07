#include "display.h"

u16 display_date[6];
u16 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delay(u16 i)	//延时函数
{
	while(i--);
}

void function_display(int b)  //数码管显示的提取数值
{
	display_date[1]=smgduan[b/10000];
	display_date[2]=smgduan[b%10000/1000];
	display_date[3]=smgduan[b%1000/100];
	display_date[4]=smgduan[b%100/10];
	display_date[5]=smgduan[b%10];
}

void display_1()			   //数码管显示
{
	u16 i;
	for(i=1;i<=5;i++)
	{
	switch(i)
	{
		case(1):
			LSA=1;LSB=1;LSC=1;break;
		case(2):
			LSA=0;LSB=1;LSC=1;break;
		case(3):
			LSA=1;LSB=0;LSC=1;break;
		case(4):
			LSA=0;LSB=0;LSC=1;break;
		case(5):
			LSA=1;LSB=1;LSC=0;break;
	}
		P0=display_date[i];
		delay(100);
		P0=0x00;
	}
}

void display(int date)		   //数码管显示集成函数
{
   function_display(date);
   display_1();
}
