/*
 * numbercount withtimer.c
 *
 * Created: 6/3/2017 5:01:06 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRD |= (1 << 0); 
	DDRC = 0xFF;
	DDRB=0xFF;
	TCCR1B |= ((1 << CS10 ) | (1 << CS12 ));
	int i=-1,j=0; 
	int a[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
	
	for (;;)
	{
		
		if ( TCNT1 >= 15624)
		{
			PORTD ^= (1 << 0);
			
			 
			
					if (PORTD==0x01){
					PORTB = a[j+1]; 
					j++;
					
					if (j==9){
			       j=-1;}
				    if (j==0){
					    PORTC= a[i+2];
					    i++;
				    }
				   
					}
	TCNT1 = 0; 
	}
}
}
