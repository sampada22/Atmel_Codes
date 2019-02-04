/*
 * commonanode.c
 *
 * Created: 5/30/2017 5:24:15 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include<util/delay.h>
#include <avr/io.h>


int main(void)
{DDRC=0xFF;
    PORTC=0x08;
    while (1) 
    {
    }
}

