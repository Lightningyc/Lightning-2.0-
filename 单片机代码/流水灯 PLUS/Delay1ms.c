
void Delay1ms(unsigned int xms)	//调用函数	//@12.000MHz
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