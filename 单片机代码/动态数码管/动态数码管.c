#include <REGX52.H>
//该开发板的数码管是共阴极的，
//所以是1亮0灭
void Delay(unsigned int xms)		//@12.000MHz
{
	 unsigned char i, j;
     while(xms--)
   {
	  i = 2;
	  j = 239;
	  do
	  {  (--j);
	  } while (--i);
   }
}

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x6F};
//定义一个0~9的数组用于Number的调用
void Nixie(unsigned char Location,Number)
//定义函数
{
     switch(Location)
	 {
		 case 1 :P2_4=1;P2_3=1;P2_2=1;break;//执行一次后停止
		 case 2 :P2_4=1;P2_3=1;P2_2=0;break;
	     case 3 :P2_4=1;P2_3=0;P2_2=1;break;
	     case 4 :P2_4=1;P2_3=0;P2_2=0;break;
	     case 5 :P2_4=0;P2_3=1;P2_2=1;break;
	     case 6 :P2_4=0;P2_3=1;P2_2=0;break;
	     case 7 :P2_4=0;P2_3=0;P2_2=1;break;
	     case 8 :P2_4=0;P2_3=0;P2_2=0;break;
	 }
	     P0=NixieTable[Number];
         //引用数组	 
	     Delay(1);
	     P0=0x00;
}

void main()
{
	while(1)
	{
	 Nixie(1,0);
	 Delay(20);	
     Nixie(2,1);
	 Delay(20);
	 Nixie(3,7);
	 Delay(20);
	}
}