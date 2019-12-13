#include<reg51.h>
#define display_port P2      //Data pins connected to port 2 on microcontroller
sbit rs = P3^2;  //RS pin connected to pin 2 of port 3
sbit rw = P3^3;  // RW pin connected to pin 3 of port 3
sbit e =  P3^4;  //E pin connected to pin 4 of port 3
                // Connecting keypad to Port 1
sbit C3 = P1^7;
sbit C2 = P1^6;
sbit C1 = P1^5;
sbit R4 = P1^4;
sbit R3 = P1^3;
sbit R2 = P1^2;
sbit R1 = P1^1;
static int lcdcount;

void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{   lcdcount == 0;
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
	  lcdcount=lcdcount++;
}

 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x80);  // bring cursor to position 1 of line 1
    msdelay(10);
}

 void lcd_init2()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0xc0);  // bring cursor to position 1 of line 2
    msdelay(10);
}

void row_finder1() //Function for finding the row for column 1
{
R1=R2=R3=R4=1;
C1=C2=C3=0;

if(R1==0)
lcd_data('1');
if(R2==0)
lcd_data('4');
if(R3==0)
lcd_data('7');
if(R4==0)
lcd_data('*');
}

void row_finder2() //Function for finding the row for column 2
{
R1=R2=R3=R4=1;
C1=C2=C3=0;

if(R1==0)
lcd_data('2');
if(R2==0)
lcd_data('5');
if(R3==0)
lcd_data('8');
if(R4==0)
lcd_data('0');
}

void row_finder3() //Function for finding the row for column 3
{
R1=R2=R3=R4=1;
C1=C2=C3=0;

if(R1==0)
lcd_data('3');
if(R2==0)
lcd_data('6');
if(R3==0)
lcd_data('9');
if(R4==0)
lcd_data('#');
}


void main()
{
    lcd_init();
    while(1)
    {    
        msdelay(30); 
          C1=C2=C3=1;
          R1=R2=R3=R4=0;
          if(C1==0)
          row_finder1();
          else if(C2==0)
           row_finder2();
           else if(C3==0)
            row_finder3();
       if(lcdcount==16)
			 {
				  lcd_init2();
			 }
    }

}