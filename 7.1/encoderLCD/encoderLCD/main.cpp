/*
 * encoderLCD.cpp
 *
 * Created: 10/10/2017 6:21:42 PM
 * Author : Sherlock
 */ 

#include <avr/io.h>
#include <avr/io.h>
#include <avr/interrupt.h>



#include "lcd.h"

#define F_CPU 16000000UL
#define SAMPLE_TIME 2       //In seconds *less than 4 seconds*
#define kppr 100

volatile  long unsigned count=0; // Pulse counter
volatile  long unsigned rpm=0;   // Revolution per min

int main(void)
{	
	
	DDRD   = (0<<PIND2)|(0<<PIND3)|(1<<PIND7);
	
	lcd_init();
	// Timer Clock = 1/1024 of sys clock and CTC mode
	TCCR1B|=((1<<WGM12)|(1<<CS12)|(1<<CS10));
	
	// Initialize INT0
	MCUCR |= (1<<ISC00)|(1<<ISC01);   // Rising edge on INT0 triggers interrupt.
	GICR  |= (1<<INT0);               // Enable INT0 interrupt
	TIMSK |= (1<<OCIE1A);             // Output compare 1A interrupt enable
	OCR1A  = (15624*SAMPLE_TIME);     // Compare value = 1 second
	sei();
	
	lcd_gotoxy(2,2);
	

	while(1)
	{
	  
	   lcd_putint(rpm);
	   _delay_ms(10);

			
	}
	return 0;
}

ISR(INT0_vect)
{
	   
count++;
 	 	
}

ISR(TIMER1_COMPA_vect)
{
	// Every SAMPLE_TIME sec !
	
	rpm = (count*60.0)/(kppr*SAMPLE_TIME);
	
	count = 0;
}



