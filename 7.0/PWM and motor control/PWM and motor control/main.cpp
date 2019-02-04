/*
 * PWM and motor control.cpp
 *
 * Created: 10/11/2017 1:59:45 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	
   uint16_t duty_cycle =50;
   int P_Scale;
   int required_frequency;
   DDRD|= (1<<PIND5);                 //OC1Ai.e. PWM OUTPUT
   
   TCCR1A |=(1<<COM1A1)|(1<<WGM11);   //non-inverting mode
   TCCR1B |=(1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11); //prescalar of 64 and fast PWM mode
 
    P_Scale = 64;
	required_frequency = 4000;
	ICR1 = (F_CPU/P_Scale*required_frequency)-1;
	OCR1A = 0;
	
    while (1) 
    {
		OCR1A = (ICR1/100)*duty_cycle;
		
    }
}

