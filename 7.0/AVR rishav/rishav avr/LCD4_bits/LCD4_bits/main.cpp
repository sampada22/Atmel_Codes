/*
 * LCD4_bits.cpp
 *
 * Created: 10/2/2017 10:20:42 PM
 * Author : Sherlock
 */ 




#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


int main(void)
{

	DDRD = 0xFF;
	DDRC = 0xFF;
	int i;
	Lcd4_Init();
	while(1)
	{
		Lcd4_Set_Cursor(1,1);
		Lcd4_Write_String("Rochak Rijal");
		for(i=0;i<16;i++)
		{
			_delay_ms(10000);
			Lcd4_Shift_Left();
		}
		for(i=0;i<16;i++)
		{
			_delay_ms(10000);
			Lcd4_Shift_Right();
		}
		Lcd4_Clear();

		Lcd4_Set_Cursor(2,6);
		Lcd4_Write_Char('R');
		Lcd4_Write_Char('M');
		Lcd4_Write_Char('S');


		Lcd4_Set_Cursor(1,5);
		Lcd4_Write_Num(2017);
		_delay_ms(2000);
	}
}

