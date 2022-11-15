#include <REGX52.H>
#include "Delay.h"
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x6F};
//定义0~9的数组，作为库用于函数的调用

void Nixie(unsigned char Location,Number)
//定义函数
{
     switch(Location)
	 {
		 case 1 :P2_4=1;P2_3=1;P2_2=1;break;
		 case 2 :P2_4=1;P2_3=1;P2_2=0;break;
	     case 3 :P2_4=1;P2_3=0;P2_2=1;break;
	     case 4 :P2_4=1;P2_3=0;P2_2=0;break;
	     case 5 :P2_4=0;P2_3=1;P2_2=1;break;
	     case 6 :P2_4=0;P2_3=1;P2_2=0;break;
	     case 7 :P2_4=0;P2_3=0;P2_2=1;break;
	     case 8 :P2_4=0;P2_3=0;P2_2=0;break;
	 }
	     P0=NixieTable[Number]; 
	     Delay(1);//消影
	     P0=0x00;//初始化P2
}
