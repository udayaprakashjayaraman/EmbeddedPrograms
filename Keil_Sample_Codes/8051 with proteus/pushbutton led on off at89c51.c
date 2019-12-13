#include "reg51.h"

int main() 
{
  
  
    P1 = 0x00; /* Configure P1 as Input to read the Switch status */
    P3 = 0xff; //output
	 
   while(1)
    {  
    /* Read the switches connected to P3 and accordingly turn ON/OFF  leds connected to P1*/
       P1 = P3;  
    }

    return (0);
}

