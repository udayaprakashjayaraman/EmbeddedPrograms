/***************************************************************************************************
                                              ExploreEmbedded Copyright Notice 
****************************************************************************************************
 * File:   main.c
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: This file contains the program to display messages on LCD in 8-bit mode. 

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


/*
 * 
 */
int main() 
{
	
    /*Connect RS->P0.0, RW->P0.1, EN->P0.2 and data bus to P0.4 to P0.7*/
    LCD_SetUp(P1_0,P1_1,P1_2,P_NC,P_NC,P_NC,P_NC,P1_4,P1_5,P1_6,P1_7);
    LCD_Init(16,2);
    
    LCD_DisplayString("Explore Embedded");
    LCD_DisplayString("Lcd 8-bit Mode");
    while(1);
    
    return (0);
}

