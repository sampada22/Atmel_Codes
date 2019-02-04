/*
 * clock.c
 *
 * Created: 5/22/2017 4:07:41 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD =  0xFF;
	int i,j,k,l,m,n;
	int a[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
	int b[10]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};	
    while (1) 
    {
		for (i=0;i<2;i++){
		PORTC = a[i];
		
		for (j=0;j<10;j++){
		PORTC=b[j];
		_delay_ms(5);
		for(k=0;k<7;k++){
		PORTA = a[k];
		_delay_ms(5);
		for (l=0;l<10;l++){
		PORTA = b[l];
		_delay_ms(5);
		for (m=0;m<7;m++){
		PORTD = b[m];
		_delay_ms(5);
		for (n=0;n<10;n++){
		PORTB = b[n];
		_delay_ms(50);}
		}
	    }
		}
		}
		}
	    }
	    }
			
	