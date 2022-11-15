#include <REGX52.H>
void Delay(unsigned int xms)	//调用函数	//@12.000MHz
{
	unsigned char i, j;
while(xms)
  {
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	  xms--;//xms=xms-1的缩写
  }	
}

    void main()
{
	 unsigned char LEDNum=0;//定义变量
     while(1)
     {
      if(P3_1==0)//如果开关处于打开状态（轻触开关）
	  {
	    Delay(20);//延迟20ms后再亮灯
	    while(P3_1==0);
	    Delay(20);  
	    LEDNum++;//对变量迭代（二进制转换）
		P2=~LEDNum;//再将变量值赋给P2
	  }
     }
}
