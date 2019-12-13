/*Program By Udaya Prakash Jayaraman */

#include<reg51.h>
sbit LED = P0^0;

void timerDelay()
{
    TH0 = 0X4B;        //Load the timer value
    TL0 = 0XFD;
    TR0 = 1;           //turn ON Timer zero
    while(TF0 == 0);   // Wait for Timer Overflow
    TF0 = 0;           //clear the timer Over flow flag
    TR0 = 0;
}

void main()
{
    TMOD = 0x01; //Timer0 mode 1 
    while(1)
    {
        LED = 1;
        timerDelay();
        LED = 0;
        timerDelay();
    } 
}