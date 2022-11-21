#include <REGX52.H>
#include "Delayxms.h"
void main()
{
    while(1)
	{
	    P2_5=0;
		Delay(500);
		P2_5=1;
		Delay(500);		
	}
}