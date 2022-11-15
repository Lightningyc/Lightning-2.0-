#include <REGX52.H>   //<XXX>是在Keil的安装目录里寻找头文件
#include "Delay.h"//""是在自己的文件目录里寻找

void main()
{
    while(1)
	{
	  P2_5=1;
	  Delay(500);
	  P2_5=0;
	  Delay(500);
	}
}