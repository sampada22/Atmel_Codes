/*
 * stepperl.cpp
 *
 * Created: 1/22/2018 6:40:01 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU	16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "stepperchalaune.h"


int main(void)
{DDRD |= (1<<PIND0)|(1<<PIND1);

   
    while (1) 
    {
		PORTD |=(1<<PIND1);
		PORTD ^=(1<<PIND0);
		_delay_ms(50);
		
    }
}

