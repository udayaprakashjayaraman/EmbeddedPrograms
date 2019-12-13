#include <reg52.h>
void Delay(unsigned int ms_Count)
{
	unsigned int i,j;
	for(i=0; i<ms_Count; i++)
	{
		for(j=0; j<100; j++);
	}
}


int main()
{
	P1 = 0x00;
	
	while(1)
	{
	    P1 = 0x06;				//Display 1
		Delay(1000);
		P1= 0x5B;			    //Display 2
		Delay(1000);
		P1 = 0x4F;			    //Display 3
		Delay(1000);
	}		
	
	
}