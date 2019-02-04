/*
 * test_basic+devs.cpp
 *
 * Created: 3/7/2018 12:05:52 PM
 * Author : Acer
 */ 

#include "basics/AVR.hpp"
#include "pphls/ExtInt.hpp"

void blink(void)
{
	PORTA ^= (1 << PINA0);
}

int main(void)
{
	sei();
	DDRA |= 0x01;
	attachInterrupt<INT::_7, blink, INT::RISING>();
     while (1) 
    {
    }
}

