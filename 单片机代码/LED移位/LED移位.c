#include <REGX52.H>
void Delay(unsigned int xms);

unsigned char LEDNum;//д��������ǰ��ȫ�ֱ���

void main()
{
    P2=~0x01;//�ϵ���һ������
    while(1)
    {
        if(P3_1==0)//���K1����
	    {
	        Delay(20);//�ӳ�����
	        while(P3_1==0);//���ּ��
			
	        Delay(20); 
		    LEDNum++;//��������
            if(LEDNum>=8)
          {
			  LEDNum=0;
		  }	
          P2=~(0x01<<LEDNum);//����ȡ�������LED
                             //ȡ���ǽ�����ȡ����0������1����		  
	    }		
		if(P3_0==0)//���K2����
	    {
	      Delay(20);//�ӳ�����
	      while(P3_0==0);//���ּ��
	      Delay(20);
			
          if(LEDNum==0)	
		  {			  
			 LEDNum=7;
		  }
          else			  
		  {
		     LEDNum--;//�����Լ�
		  }			  
             P2=~(0x01<<LEDNum);		  
	    }
      }
}
void Delay(unsigned int xms)
//���ú��������������ź���Ļ�
//Ӧ����ǰ������void Delay(unsigned int xms);
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
