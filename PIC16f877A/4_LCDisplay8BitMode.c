/*
 * File:   4_LCDisplay8BitMode.c
 * Author: Udaya
 * LED Blink
 *
 * Circuitrcuit Connection 
 * Vss to Ground
 * Vcc to 5V
 * Vee to potentiometer to adjust brightness if needed
 * RS- Register Select (0-Command mode)(1-data mode)
 * RW- Read/Write, R/W=0: Write & R/W=1: Read
 * EN- Enable. Falling edge triggered	
 * D0 to D7 Databit 0 to 7
 * So connect D0 to D7 in Port B0 to B7
 * Connect RS(RC0), RW(RC1 or Gnd), EN(RC2) 
 * A- Anode(+)
 * K- Cathode(-)
 * 
 *
 * Created on June 3, 2019, 2:23 PM
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
   Dtatus bus is connected to PB0:PB7 and control bus PD0:PD2*/

#define LcdDataBus      PORTB   //Data Bus
#define LcdControlBus   PORTC	//Control/Command Bus

#define LcdDataBusPins   TRISB
#define LcdCtrlBusPins   TRISC


#define EN RC2	//use EN as 0 or 1 to sent data and command
#define RW RC1	// Use RW as 0 to set in write mode
#define RS RC0	// Register Select (0-Command mode)(1-data mode)


void delay(unsigned int Count)
{
    unsigned int i,j;
    for(i=0;i<Count;i++)
    {
        for(j=0;j<100;j++);
    }
}

void Lcd_CmdWrite(char cmd)
{
	LcdDataBus = cmd;  //cmd is set to PORTB data pins PB0 to PB7
	RS = 0;	// set RS as 1 to configure in command mode
    RW = 0;			   // set RW as 0 to configure as Write mode
	EN = 1;			   // set EN as 1 to sent 8bit command from PORTB to LCD
	delay(100);			
	EN = 0;				// set EN as 0 after sending command to LCD display
	delay(100);
}
void Lcd_DataWrite(char dat)
{
	LcdDataBus = dat;  // dat is set to PORTB data pins PB0 to PB7
	RS = 1;			   // set RS as 0 to configure in data mode
    RW = 0;			   // set RW as 0 to configure as Write mode
	EN = 1;			   // set EN as 1 to sent 8bit data from PORTB to LCD
	delay(100);			
	EN = 0;				// set EN as 0 after sending data to LCD display
	delay(100);
}

int main()
{
    while(1)
    {
	char i,a[]={"PIC16F877A MCU"};
	
	LcdDataBusPins = 0x00;
	LcdCtrlBusPins = 0x00;
    TRISC0 = 0;
    delay(1000);
	
    Lcd_CmdWrite(0x38);        // enable 8bit mode, 5x7 mode for chars 
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