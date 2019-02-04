/*
 * PWM generation.c
 *
 * Created: 6/5/2017 5:54:50 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int i;
int main(void)
{
	uint16_t duty_cycle = 50; 
	int P_Scale;
	int required_frequency;
	
    DDRD|=(1<<PIND5); 
    
	TCCR1A|= (1<<COM1A1)|(1<<WGM11);
	TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);//setting the prescalar to 64
	
	P_Scale = 64;
	required_frequency=4000;
	
	ICR1= (F_CPU/P_Scale*required_frequency)-1;  //{This value can go upto 65535(as 16 bit register) and the count is given by {(F_CPU/P_Scale*required frequency)-1}}
	OCR1A =0;
    while (1) 
    {
	
	OCR1A = (ICR1/100)*duty_cycle;
}
}
// 100% duty cycle= ICR
// 1% duty cycle = ICR/100
// x% duty cycle = (ICR/100)*x