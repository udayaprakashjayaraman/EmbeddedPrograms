/***************************************************************************************************
                                              ExploreEmbedded Copyright Notice 
****************************************************************************************************
 * File:   main.c
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: This file contains the program to display 4-digit up counter on LCD in 4-bit mode. 

This code has been developed and tested on ExploreEmbedded boards.  
We strongly believe that the library works on any of development boards for respective controllers. 
Check this link http://www.exploreembedded.com/wiki for awesome tutorials on 8051,PIC,AVR,ARM,Robotics,RTOS,IOT.
ExploreEmbedded invests substantial time and effort developing open source HW and SW tools, to support consider buying the ExploreEmbedded boards.
 
The ExploreEmbedded libraries and examples are licensed under the terms of the new-bsd license(two-clause bsd license).
See also: http://www.opensource.org/licenses/bsd-license.php

EXPLOREEMBEDDED DISCLAIMS ANY KIND OF HARDWARE FAILURE RESULTING OUT OF USAGE OF LIBRARIES, DIRECTLY OR
INDIRECTLY. FILES MAY BE SUBJECT TO CHANGE WITHOUT PRIOR NOTICE. THE REVISION HISTORY CONTAINS THE INFORMATION 
RELATED TO UPDATES.
 

Permission to use, copy, modify, and distribute this software and its documentation for any purpose
and without fee is hereby granted, provided that this copyright notices appear in all copies 
and that both those copyright notices and this permission notice appear in supporting documentation.
**************************************************************************************************/
#include "lcd.h"
#include "delay.h" 


/*
 * 
 */
int main() 
{
    int count = 0;
	
    /*Connect RS->P0.0, RW->P0.1, EN->P0.2 and data bus to P0.4 to P0.7*/
    LCD_SetUp(P3_2,P3_3,P3_4,P_NC,P_NC,P_NC,P_NC,P2_4,P2_5,P2_6,P2_7);
    LCD_Init(2,16);
    
    LCD_DisplayString("Decimal");

    while(1)
    {   LCD_Clear();
        LCD_GoToLine(1);
			Enable_LCD_Printf   = 1    
			LCD_Printf("Count=%4d",count);
        DELAY_ms(500);
        count++;
    }
    
    return (0);
}

