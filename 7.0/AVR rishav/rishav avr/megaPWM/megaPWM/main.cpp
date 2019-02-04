/*
 * megaPWM.cpp
 *
 * Created: 10/1/2017 8:08:28 PM
 * Author : Rishav Dhungel
 */ 

#include <avr/io.h>
#include "pwm.h"

#define F_CPU 16000000UL
uint16_t top = 624;

int main(void)
{

	
	init_timer(1,1,1,1);
	selectPin_timer1(1,1,1);
	selectPin_timer3(1,1,1);
	selectPin_timer4(1,1,1);
	selectPin_timer5(1,1,1);
	OCR1B = (top*0.50);
	
	 
	
	while (1) {}
}
