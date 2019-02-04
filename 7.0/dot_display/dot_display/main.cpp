/*
 * dot_display.cpp
 *
 * Created: 11/7/2017 11:55:51 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define RPM 60
uint16_t count = 0;
void display_first();
void display_last();
int main(void)
{
    DDRD|= (1<<PIND4);
	sei();
	TCCR1B |= (1<<CS12)|(1<<CS10);      //set the prescalar to 1024
	TCCR1B|= (1<<WGM12);                //set the CTC mode	
	TIMSK |= (1<<OCIE1A);
	int degree;
	degree = 1/(6*RPM) ;
	OCR1A = degree*15625;	
    while (1) 
    {
		display_first();
    }
}


ISR (TIMER1_COMPA_vect){
	count ++;
	if (count == 180){
 	display_last();
	}
}
/*int degree(int n){
	
	
int degree ;
//int rpm = 200;
sec = (1/1200)*n;     //(1200 =6*rpm)
return sec;	

}*/


void display_first(){
PORTB|= 0x1E;
}
void display_last(){
	PORTC|=0x1E;
}