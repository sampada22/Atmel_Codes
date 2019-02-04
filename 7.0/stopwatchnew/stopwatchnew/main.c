/*
 * stopwatchnew.c
 *
 * Created: 6/21/2017 7:08:59 PM
 * Author : Sampada Dhakal
 */ 

#define F_CPU 16000000UL

#define disp PORTC
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6

#define other PORTA
#define GA 0
#define GB 1
#define GC 2
#define GD 3

#define count_speed 5			//count_speed = 500 gives the exact count of 1 second

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void update_time();
void update_sw();
void display_time();
void display_sw();

//Time Initialization
unsigned char hr = 9;
unsigned char min = 21;
unsigned char sec = 30;

//SW Initialization;
unsigned char sw_min = 0;
unsigned char sw_sec = 0;

uint16_t count = 0;
uint16_t sw_count = 0;
uint8_t segCode[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uint8_t select = 1;


int main(void)
{
	//Direction Initialization
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;
	
	//Pin Initialization
	disp = 0;
	other = 0b0001111;
	PORTD |= 1<<PIND2;
	
	
	TCCR0 = 1<<WGM01;		//set CTC mode
	OCR0 = 125;				//sets the compare value
	TIMSK = 1<<OCIE0;		//enables the counter compare match flag
	
	GICR = 1<<INT0;			//Set PIND2 as external interrupt pin
	sei();					//enables the interrupt function
	
	TCCR0 = 1<<CS02;		//Set the pre-scalar and start the counter
	
	while (1)
	{
		if(select)
		display_time();
		
		else
		display_sw();
		
	}
}

ISR(TIMER0_COMP_vect)
{
	if(select)
	update_time();
	
	else
	{
		update_time();
		update_sw();
	}
	
}

ISR(INT0_vect)
{
	if(select)
	{
		select = 0;
		sw_min = 0;
		sw_sec = 0;
	}
	else
	select = 1;
	
}

void update_time()
{
	count++;
	if(count >= count_speed)
	{
		sec++;
		if (sec >= 60)  {sec = 0; min++;}
		if (min >= 60)  {min = 0; hr++;}
		if (hr > 12)  hr = 1;
		count = 0;
	}
}

void update_sw()
{
	sw_count++;
	if(sw_count >= count_speed)
	{
		sw_sec++;
		if (sw_sec >= 60)  {sw_sec = 0; sw_min++;}
		if (sw_min >= 60)  sw_min = 0;
		sw_count = 0;
	}
}
void display_time()
{
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

void display_sw()
{
	disp = segCode[sw_min/10];
	other &= ~(1<<GA);
	_delay_ms(5);
	other |= (1<<GA);
	
	disp = segCode[sw_min%10];
	other &= ~(1<<GB);
	_delay_ms(5);
	other |= (1<<GB);
	
	
	disp = segCode[sw_sec/10];
	other &= ~(1<<GC);
	_delay_ms(5);
	other |= (1<<GC);
	
	disp = segCode[sw_sec%10];
	other &= ~(1<<GD);
	_delay_ms(5);
	other |= (1<<GD);
}