#include <reg51.h>

sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;
void delay(unsigned int);
void cmd1(unsigned char);
void dat1(unsigned char);
void cmd(unsigned char);
void dat(unsigned char);

void main(void)
{
	
	unsigned char ch[]="Udaya";
	unsigned char ch1[]="Embedded";
	
	unsigned int i,j,k;
	
	
	cmd(0x28);
	cmd(0x01);
	cmd(0x0c);
	cmd(0x83);
	cmd(0x06);
	for(i=0;ch[i]!='\0';i++)
	    dat(ch[i]);

		cmd(0xc3);
	for(j=0;ch1[j]!='\0';j++)
	{
		dat(ch1[j]);
 	 }
	 while(1){
	for(k=0;k<16;k++)
	{
	cmd(0x1c);
	}
	}
}
void delay(unsigned int t)
{
	unsigned int i,j;
	e=1;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);
	e=0;
}
void cmd(unsigned char a)
{
unsigned char x;
x=a&0xf0;
cmd1(x);
x=(a<<4)&0xf0;
cmd1(x);
}
 void dat(unsigned char a)
{
unsigned char x;
x=a&0xf0;
dat1(x);
x=(a<<4)&0xf0;
dat1(x);
}


void cmd1(unsigned char ch)
{
	P2=ch;
	rs=0;
	rw=0;
	delay(10);
}
void dat1(unsigned char ch)
{
	P2=ch;
	rs=1;
	rw=0;
	delay(10);
}