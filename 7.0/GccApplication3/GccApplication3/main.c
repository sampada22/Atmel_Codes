/*
 * GccApplication3.c
 *
 * Created: 5/22/2017 5:54:52 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

DDRB=0xFF;
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		PORTB|=0x01;
		_delay_ms(500);
		PORTB&=~0x01;
		_delay_ms(500);
    }
}

