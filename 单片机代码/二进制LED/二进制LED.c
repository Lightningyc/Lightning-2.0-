#include <REGX52.H>
void Delay(unsigned int xms)	//���ú���	//@12.000MHz
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
	  xms--;//xms=xms-1����д
  }	
}

    void main()
{
	 unsigned char LEDNum=0;//�������
     while(1)
     {
      if(P3_1==0)
	  {
	    Delay(2000);
	    while(P3_1==0);
	    Delay(2000);  
	    LEDNum++;//�Ա������и�ֵ
		P2=~LEDNum;//�ٽ�����ֵ����P2
	  }
     }
}
