
void Delay(unsigned int xms)	//���ú���	//@12.000MHz
{
	unsigned char i, j;
    while(xms--)
 {
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);	  
  }	
}