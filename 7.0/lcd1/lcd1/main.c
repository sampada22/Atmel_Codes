#include "lcd.h"
#include<avr/io.h>
#include<util/delay.h>

int main()
{
	/*Connect RS->PD0, RW->PD1, EN->PD2 and data bus to PORTB*/
	LCD_SetUp(P0_0,P0_1,P0_2,P2_0,P2_1,P2_2,P2_3,P2_4,P2_5,P2_6,P2_7);
	LCD_Init(2,16);
	
	LCD_DisplayString("Hello world");
	LCD_DisplayString("Lcd 8-bit Mode");
	while(1);
	
	return (0);
}
