/*
 * numberdisplay1.c
 *
 * Created: 5/24/2017 7:53:50 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
//#define zero 0b00111111
//#define one 0b00000110
//#define two 0b01011011
//#define three 0b01001111
//#define four 0b01100110
//#define five 0b01101101
//#define six 0b01111101
//#define seven 0b00000111
//#define eight 0b011111111
//#define nine 0b01101111

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int a[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b011111111,0b01101111};
	int count = 0;
    DDRC=0xFF;
	DDRD=0xFF;
    while (1) 
    {
		for (int i = 0 ; i < 10 ; i++)
		{
			PORTD = a[i];
			PORTC = a[count];
			_delay_ms(500);
			
		}
		++count;
	}
}

