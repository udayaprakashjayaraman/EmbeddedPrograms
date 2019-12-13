/*
 * File:   2_LedOnOffWithPushButton.c
 * Author: Udaya
 * LED Blink
 *
 * Circuit connection
 * RB0- Connected to LED as OUTPUT
 * RD0- Connected to Pushbutton/SPDT switch to on/off control
 *
 * Created on June 3, 2019, 2:23 PM
 */



#define _XTAL_FREQ 8000000

#pragma config FOSC = HS     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void delay(count)
{    							//delay function
    unsigned int i,j;
    for(i=0;i<count;i++)
    {
        for(j=0;j<100;j++);
    }
}
int main()
{
	TRISB0 = 0;
	TRISD0 = 1;
	while(1)
	{
		if(RD0 = 1)
		{
			RB0 =1;
			delay(100);
		}
		else
		{
			RB0 = 0;
			delay(100);
		}
	}
	
}