/*
 * 7 segment display.c
 *
 * Created: 5/22/2017 5:56:02 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
// 	DDRA = 0xFF;
// 	PORTA = 0xFF;
	while(1);
    while (1) 
    {
		PORTC = 0x6D;
		_delay_ms(500);
		PORTC = 0x6D;
		_delay_ms(500);
		PORTC = 0x77;
		_delay_ms(500);
		PORTC = 0x4F;
		_delay_ms(500);
		PORTC = 0x73;
		_delay_ms(500);
		PORTC = 0x77;
		_delay_ms(500);
		PORTC = 0x3F;
		_delay_ms(500);
		PORTC = 0x77;
		_delay_ms(500);
		
    }
}

