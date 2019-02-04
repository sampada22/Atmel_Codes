/*
 * checkhexfile.cpp
 *
 * Created: 3/7/2018 5:00:37 PM
 * Author : Sampada Dhakal
 */ 

#include <avr/io.h>


int main(void)
{
	
	DDRA = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		PORTA = 0x00;
		PORTA = 0xff;
    }
}

