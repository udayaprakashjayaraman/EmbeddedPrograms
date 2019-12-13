#include<reg52.h>

void main()
{
	unsigned char x, y;
	unsigned int i;
	P1 =0x00;  //Port 1 as output
	while(1)
	{
	x=0x01;   //0000 0001 b
		for(y =0; y<8; y++)
		{
			P1=x;
			for(i=0l; i<60000; i++);
			x=x<<1;
		}
	}
	
	
}