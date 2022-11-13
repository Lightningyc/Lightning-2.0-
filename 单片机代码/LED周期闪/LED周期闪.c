#include <REGX52.H>
#include <INTRINS.H>
void Delay500ms()		//@18.432MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 6;
	j = 215;
	k = 31;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

int main()
{	
	while(1)
{
	P2=0xFE;
	Delay500ms();
	P2=0xFF;
	Delay500ms();
}
}