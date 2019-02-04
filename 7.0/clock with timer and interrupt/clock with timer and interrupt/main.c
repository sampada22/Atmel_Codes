/*
 * clock with timer and interrupt.c
 *
 * Created: 6/12/2017 5:02:39 AM
 * Author : Sampada Dhakal
 */ 

#define F_CPU 16000000UL

#define disp PORTD
#define a PIND0
#define b PIND1
#define c PIND2
#define d PIND3
#define e PIND4
#define f PIND5
#define g PIND6

#define other PORTC
#define GA PINC0
#define GB PINC1
#define GC PINC2
#define GD PINC3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Time initialization
unsigned char hr = 9;
unsigned char min = 21;
unsigned char sec = 30;

uint16_t count = 0;
uint8_t segCode[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


int main(void)
{
	TCCR0A = 1<<WGM01; //set CTC mode
	OCR0A = 125; //sets the compare value
	TIMSK0 = 1<<OCIE0A; //enables the counter compare match flag
	sei(); //enables the interrupt function
	TCCR0B = 1<<CS02; //Set the pre-scalar and start the counter
	
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;
	
	disp = 0;
	other = 0b0001111;
	
	while (1)
	{

		if (sec >= 60)  {sec = 0; min++;}
		if (min >= 60)  {min = 0; hr++;}
		if (hr > 12)  hr = 1;
		
		//Displaying the numbers
		if( hr < 10)
		{
			disp = segCode[hr];
			other &= ~(1<<GB);
			_delay_ms(5);
			other |= (1<<GB);
		}
		
		if(hr >= 10)
		{
			disp = segCode[hr/10];
			other &= ~(1<<GA);
			_delay_ms(5);
			other |= (1<<GA);
			
			disp = segCode[hr%10];
			other &= ~(1<<GB);
			_delay_ms(5);
			other |= (1<<GB);
			
		}
		
		if( min < 10)
		{
			disp = segCode[min/10];
			other &= ~(1<<GC);
			_delay_ms(5);
			other |= (1<<GC);
			
			disp = segCode[min];
			other &= ~(1<<GD);
			_delay_ms(5);
			other |= (1<<GD);
		}
		
		if(min >= 10)
		{
			disp = segCode[min/10];
			other &= ~(1<<GC);
			_delay_ms(5);
			other |= (1<<GC);
			
			disp = segCode[min%10];
			other &= ~(1<<GD);
			_delay_ms(5);
			other |= (1<<GD);
			
		}
		
		
	}
}

ISR(TIMER0_COMPA_vect)
{
	count++;
	if(count >= 500)
	{
		sec++;
		count = 0;
	}
}