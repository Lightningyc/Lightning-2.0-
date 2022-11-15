#include <REGX52.H>
void Delay(unsigned int xms);

unsigned char LEDNum;//写在主函数前是全局变量

void main()
{
    P2=~0x01;//上电后第一个灯亮
    while(1)
    {
        if(P3_1==0)//如果K1按下
	    {
	        Delay(20);//延迟消抖
	        while(P3_1==0);//松手检测
			
	        Delay(20); 
		    LEDNum++;//变量自增
            if(LEDNum>=8)
          {
			  LEDNum=0;
		  }	
          P2=~(0x01<<LEDNum);//变量取反输出给LED
                             //取反是将亮灭取反（0是亮，1是灭）		  
	    }		
		if(P3_0==0)//如果K2按下
	    {
	      Delay(20);//延迟消抖
	      while(P3_0==0);//松手检测
	      Delay(20);
			
          if(LEDNum==0)	
		  {			  
			 LEDNum=7;
		  }
          else			  
		  {
		     LEDNum--;//变量自减
		  }			  
             P2=~(0x01<<LEDNum);		  
	    }
      }
}
void Delay(unsigned int xms)
//调用函数如果将函数体放后面的话
//应该在前面声明void Delay(unsigned int xms);
{
	unsigned char i, j;
    while(xms--)
   {
	 i = 2;
	 j = 239;
	 do
	 {
		 while (--j);
	 }   while (--i);
   }	
}
