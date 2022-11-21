#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MrixKey.h"

unsigned char KeyNum;

void main()
{
   LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:");
   while(1)
   {
	   KeyNum=MrixKey();
	   if(KeyNum!=0)//按键松开就执行
	   {
		   
	     LCD_ShowNum(2,1,KeyNum,2);
	   
	   }
   }

}