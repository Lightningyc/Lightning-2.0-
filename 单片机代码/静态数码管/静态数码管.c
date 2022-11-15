#include <REGX52.H>
//该开发板的数码管是共阴极的，
//所以是1亮0灭
unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0X66,0x6D,0x7D,0x07,0x7F,0x6F};
void Nixie(unsigned char Location,Number)
{
     switch(Location)
	 {
		 case 1 :P2_4=1;P2_3=1;P2_2=1;break;
		 case 2 :P2_4=1;P2_3=1;P2_2=0;break;
	     case 3 :P2_4=1;P2_3=0;P2_2=1;break;
	     case 4 :P2_4=1;P2_3=0;P2_2=0;break;
	     case 5 :P2_4=0;P2_3=1;P2_2=1;break;
	     case 6 :P2_4=0;P2_3=1;P2_2=0;break;
	     case 7 :P2_4=0;P2_3=0;P2_2=1;break;
	     case 8 :P2_4=0;P2_3=0;P2_2=0;break;
	 }
	     P0=NixieTable[Number];   
}

void main()
{
	
	Nixie(4,9);
	while(1)
	{
	
	}
}