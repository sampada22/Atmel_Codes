/*
 * rpm_check.cpp
 *
 * Created: 11/19/2017 5:01:55 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
uint16_t count = 0;
uint16_t sec = 0;
int rpm;

int main(void)
{lcd_init();
	sei();
	TCCR1B|=(1<<CS12)|(1<<CS10);
	TCCR1B |=(1<<WGM12);
	TIMSK |= (1<<OCIE1B);
	OCR1A = 15625;
	MCUCR |= (1<<ISC00)|(1<<ISC01);
	GICR |= (1<<INT1);
   rpm = (count/sec)*60;
   lcd_gotoxy(5,1);
   lcd_puts("RPM:");
    while (1) 
    {
		
	}
}
ISR (INT1_vect){
count ++;
	
}
ISR (TIMER1_COMPA_vect){
	sec++;
	if (sec == 60){
		lcd_gotoxy(7,2);
		lcd_putint(rpm);
	}
	
}