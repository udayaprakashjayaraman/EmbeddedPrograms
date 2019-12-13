/*
 * File:   5_LCDisplay4BitMode.c
 * Author: Udaya
 * 5_LcdDisplay4BitMode.c
 *
 * Circuit Connection 
 * Vss to Ground
 * Vcc to 5V
 * Vee to potentiometer to adjust brightness if needed
 * RS- Register Select (0-Command mode)(1-data mode)
 * RW- Read/Write, R/W=0: Write & R/W=1: Read
 * EN- Enable. Falling edge triggered	
 * B4 to B7 Databit 0 to 4
 * So connect D0 to D4 in Port B4 to B7
 * Connect RS(RB0), RW(RB1 or Gnd), EN(RB2) 
 * A- Anode(+)
 * K- Cathode(-)
 * 
 *
 * Created
 */



#define _XTAL_FREQ 8000000

#pragma config FOSC = HS    // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic16f877a.h>


/* Configure the data bus and Control bus as per the hardware connection 
   Databus is connected to P2.4:P2.7 and control bus P2.0:P2.2*/

#define LcdDataBus  PORTB   //Data Bus

#define LcdBusPins TRISB


#define EN RB2	//use EN as 0 or 1 to sent data and command
#define RW RB1	// Use RW as 0 to set in write mode
#define RS RB0	// Register Select (0-Command mode)(1-data mode)



/* local function to generate delay */
void delay(int cnt)
{
    unsigned int i,j;
    for(i=0;i<cnt;i++)
	{
		for(j=0;j<=100;j++);
	}
}



/* Function to send the command to LCD. 
   As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */

void Lcd_CmdWrite(char cmd)
{
    LcdDataBus = (cmd & 0xF0);     //Send higher nibble
    RS = 0;   // Send LOW pulse on RS pin for selecting Command register
    RW = 0;   // Send LOW pulse on RW pin for Write operation
    EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(1000);
    EN = 0;

    delay(100);

    LcdDataBus = ((cmd<<4) & 0xF0); //Send Lower nibble
    RS = 0;   // Send LOW pulse on RS pin for selecting Command register
    RW = 0;   // Send LOW pulse on RW pin for Write operation
    EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(100);
    EN = 0; 

    delay(100);
}


/* Function to send the Data to LCD. 
   As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */

void Lcd_DataWrite(char dat)
{
    LcdDataBus = (dat & 0xF0);      //Send higher nibble
    RS = 1;   // Send HIGH pulse on RS pin for selecting data register
    RW = 0;   // Send LOW pulse on RW pin for Write operation
    EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(100);
    EN = 0;

    delay(100);

    LcdDataBus = ((dat<<4) & 0xF0);  //Send Lower nibble
    RS = 1;    // Send HIGH pulse on RS pin for selecting data register
    RW = 0;    // Send LOW pulse on RW pin for Write operation
    EN = 1;    // Generate a High-to-low pulse on EN pin
    delay(100);
    EN = 0; 

    delay(100);
}



int main()
{

    LcdBusPins = 0x00;  // Configure all the LCD pins as output
while(1)
{
    char i,a[]={"PIC16F877A MCU!"};

    Lcd_CmdWrite(0x02);        // Initialize Lcd in 4-bit mode
    Lcd_CmdWrite(0x28);        // enable 5x7 mode for chars 
    Lcd_CmdWrite(0x0E);        // Display OFF, Cursor ON
    Lcd_CmdWrite(0x01);        // Clear Display
    Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line


    Lcd_DataWrite('H');
    Lcd_DataWrite('e');
    Lcd_DataWrite('l');
    Lcd_DataWrite('l');
    Lcd_DataWrite('o');
    Lcd_DataWrite(' ');
    Lcd_DataWrite('E');
    Lcd_DataWrite('G');
    Lcd_DataWrite('A');
    Lcd_DataWrite('I');

    Lcd_CmdWrite(0xc0);        //Go to Next line and display Good Morning
    for(i=0;a[i]!=0;i++)
    {
        Lcd_DataWrite(a[i]);
    }
}
}
