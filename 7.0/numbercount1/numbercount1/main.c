/*
 * numbercount1.c
 *
 * Created: 5/23/2017 4:21:41 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;
	DDRC = 0xFF;
    while (1) 
    {
		int i,j=0;
		for (i=0;i<9;i++){
		PORTD = 0b00111111;
		_delay_ms(500);
		PORTD = 0b00000110;
		_delay_ms(500);
		PORTD = 0b01011011;
		_delay_ms(500);
		PORTD = 0b01001111;
		_delay_ms(500);
		PORTD = 0b01100110;
		_delay_ms(500);
		PORTD = 0b01101101;
		_delay_ms(500);
		PORTD =0b01111101;
		_delay_ms(500);
		PORTD =0b00000111;
		_delay_ms(500);
		PORTD = 0b01111111;
		_delay_ms(500);
		PORTD = 0b01101111;
		_delay_ms(500); 
		if (PORTD==0b01101111){
		//PORTD=~0b01101111 &&
		PORTD=0b00111111;
		j++;
		if (j==0){
	    PORTC = 0b00111111;
		_delay_ms(500);
		}
		if (j==1){
		PORTC = 0b00000110;
		_delay_ms(500);	
		}
		if (j==2){
		PORTC = 0b01011011;
		_delay_ms(500);
		}
		if (j==3){
		PORTC = 0b01001111;
		_delay_ms(500);}
		if (j==4){
		PORTC = 0b01100110;
		_delay_ms(500);
        }
	    if (j==5){
		PORTC = 0b01100110;
		_delay_ms(500);
	    }if (j==6){
		PORTC =0b01111101;
		_delay_ms(500);
		
	    }if (j==7){
		PORTC =0b00000111;
		_delay_ms(500);
	   }if (j==8){
		PORTC = 0b01111111;
		_delay_ms(500);
		
	    }if (j==9){
		PORTC = 0b01101111;
		_delay_ms(500);
	   }
       }
	   }
	   }
	   }