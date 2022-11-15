#include <REGX52.H>//该开发板是共阴极的，所以是1亮0灭
#include "Nixie.h"
#include "Delay.h"

void main()//函数主体
{
	while(1)
	{
	 Nixie(2,5);
	 Delay(200);	
     Nixie(3,2);
	 Delay(200);
	 Nixie(4,0);
	 Delay(200);
	}
}