#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec,Min,Hour;

void main()
{
    LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Clock:");
    while(1)
     {
      LCD_ShowNum(1,7,Hour,2);
	  LCD_ShowChar(1,9,':');
	  LCD_ShowNum(1,10,Min,2);
	  LCD_ShowChar(1,12,':');
	  LCD_ShowNum(1,13,Sec,2); 
	  LCD_ShowChar(2,8,'h');
      LCD_ShowChar(2,11,'m');
      LCD_ShowChar(2,14,'s');		 
     }

}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
	  T0Count=0;
	  Sec++;
		if(Sec>=60)//60进1
		{
		 Sec=0;
		 Min++;
			if(Min>=60)
            {
			 Min=0;
			 Hour++;
			}		
		}
	}
}