#include <REGX52.H>//如果头文件名字REG52.H，
                   //即没有定义位数，下面的P2_0无定义
void main()
{	
   while(1)
   { 
	  if(P3_3==0)//开关的位数
      {
	       P2_7=0;//P2=0xFE;//1111 1110
	  }
      else
	  {
	       P2_7=1;
	  }  
     }
}
