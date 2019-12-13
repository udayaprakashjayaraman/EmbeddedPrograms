#include<reg51.h>

void delay(unsigned int ms_count)    //delay function for 1 sec
{
	unsigned int i,j;
   for(i=0; i<=ms_count; i++)
	 {
		 for(j=0; j<100; j++);
	 }
}

void main()         // main function
{
	while(1)
	{
	P1 = 0xff;     // on P1 port all pins   1111 1111 
	delay(1000);
	P1= 0x00;      // off P1 port all pins 0000 0000
	delay(1000);
	}
}