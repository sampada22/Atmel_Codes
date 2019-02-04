/*
 * led blink with pwm.c
 *
 * Created: 6/7/2017 8:15:20 AM
 * Author : Sampada Dhakal
 */ 

#define F_CPU 16000000UL
# #include <avr/io.h>

#include <util/delay.h>

int main(void)
{
	DDRD = 0;
	DDRB = 0xFF;
	TCCR0 |=(1<<WGM00)|(1<<WGM01)|(1<<COM00)|(1<<COM01)|(1<<CS00);
	OCR0 = 0;
	while(1)
	{
		if (bit_is_clear(PIND,5))
		{
			if (OCR0<255)
			{
				OCR0++;
			}
			_delay_ms(50);
			
		}
		if (bit_is_clear(PIND,6))
		{
			if (OCR0>0)
			{
				OCR0--;
			}
			_delay_ms(50);
		}
	}
}