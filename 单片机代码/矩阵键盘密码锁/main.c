#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MrixKey.h"

unsigned char KeyNum;
unsigned int PassWord,Count;//定义输入次数
void main()
{
    LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
   while(1)
   {
	   KeyNum=MrixKey();
	   if(KeyNum!=0)//按键松开就执行
	   {
		 if(KeyNum<=10)//如果S1~S10按下 
		 {			 
	         if(Count<4)
			 {
			 PassWord*=10;//当前键码乘十，即左移一位			
			 PassWord+=KeyNum%10;//表示键码对十取余
			 }
			 Count++;
		 }

		 LCD_ShowNum(1,10,PassWord,4);//在1行10列输出四位密码
	   }
	   if(KeyNum==15)//如果按下S15（设置确认键）
	   {
	     if(PassWord==1209)//如果密码正确
	     {
	     LCD_ShowString(2,1,"True ");//防止字符重叠
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//密码清零
	     Count=0;//计次清零
		 LCD_ShowNum(1,10,PassWord,4);//更新显示
		 LCD_ShowString(1,1,"PassWord:");			 
		 }
		 else//否则
		 {
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//密码清零
	     Count=0;//计次清零
		 LCD_ShowNum(1,10,PassWord,4);//更新显示
		 LCD_ShowString(1,1,"PassWord:");	
		 }
       }
	   if(KeyNum==16)//如果按下S16（设置取消键）
	   {
		 Delay(1500);	 
		 LCD_Init();
		 PassWord=0;//密码清零
	     Count=0;//计次清零
		 LCD_ShowNum(1,10,PassWord,4);//更新显示
		 LCD_ShowString(1,1,"PassWord:");	
	   }
   }

}