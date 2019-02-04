/*
 * battiPilikPilik.c
 *
 * Created: 11/18/2017 2:12:59 PM
 * Author : puspa
 */ 
#define F_CPU		16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0X01;
	
    while (1) 
    {
		PORTD=0X01;
		_delay_ms(500);
		PORTD=0x00;
		_delay_ms(500);
		
    }
}

