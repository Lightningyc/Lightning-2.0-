#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
void main()
{
    LCD_init();	    
    while(1)
   {
    LCD_ShowString(1,1,"Lightning");
    Delay(500);
	LCD_ShowChar(2,1,'0');
	LCD_ShowChar(2,2,'1');
	LCD_ShowChar(2,3,'7');
	Delay(500);
   }
	
}