#include<reg52.h>

int main ()
{
	P1 = 0x00;   // P1 as input
	P2 = 0xFF;   // P2 as output
	
while(1)
{
	P2 = P1 & 0xAA;
}
	
	
	
}