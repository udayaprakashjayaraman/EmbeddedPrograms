#include <reg51.h>

#define LED P3		// LED's are connected to higher bits of P3


void DELAY_ms(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<100;j++);
    }
}

int main()
{

   P3 = (0xf0<<LED);           // Configure PORT3.4 to PORT  3.7 as output
	 P2 = (0x00);     // config p2 as input
  
if(P2 = )
    
    while(1)
	{
		P3 = (0xf0<<LED);        // Turn ON Led's connected to P3  	
		DELAY_ms(1000);      // Wait for some time

		P3 = (0x00<<LED);        // Turn OFF Led connected to P3
	    DELAY_ms(1000);      // Wait for some time
	}
	return 0;
}