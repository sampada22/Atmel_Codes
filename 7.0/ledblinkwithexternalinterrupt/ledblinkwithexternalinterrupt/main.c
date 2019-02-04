/*
 * ledblinkwithexternalinterrupt.c
 *
 * Created: 6/13/2017 5:14:08 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int main(void)
{
	DDRB=0xFF;
	DDRD=0x00;
   sei();
   GICR |=(1<<INT1);
  // MCUCR |=(0<<ISC11)|(1<<ISC10);
   //GIFR|=(1<<INTF1);
    while (1) 
    {
		//PORTB=0x00;
    }
}

ISR(INT1_vect){
	int a[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
		int i;
		for (i=0; i<10; i++){
	
		PORTB ^= a[i];	
		_delay_ms(500);
		}
	//PORTB ^=(1<<PINB0);
	
	
}