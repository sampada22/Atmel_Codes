/*
 * avr_timer_library.cpp
 *
 * Created: 3/6/2018 3:34:43 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define comp_value 2
int output(void);
 int count = 0;
int main(void)
{  
	 DDRA |= 0xFF;
	sei();                                           //set the global interrupt
	TCCR1A |= (0<<WGM10)|(0<<WGM11);                 //set the CTC mode
	TCCR1B |= (1<<CS10)|(1<<CS11);                   //set the pre-scalar to 1024
	TCCR1B |=(1<<WGM12)|(0<<WGM13);                  //set the CTC mode
	TIMSK1 |=(1<<OCIE1A);    //enable the interrupts on compare match
    OCR1A = 15625;                                   //timer value of 1 sec
    while (1) 
    {
	if (count == comp_value){
		output();
	}
    }
}
int output(void){
	PORTA |=(1<<PINA5);
	_delay_ms(10);
	
}

ISR(TIMER1_COMPA_vect){
	count ++;
	
}