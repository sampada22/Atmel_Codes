/*
 * numebrcountt.c
 *
 * Created: 5/22/2017 7:01:32 PM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{int i,j;
   
    while (1) 
    {
		for (i=0;i<9;i++){
			
			DDRD|=0x3F;
			PORTD|=0x3F;
			_delay_ms(500);
			PORTD&=~0x3F;
			_delay_ms(500);
			DDRD|=0x06;
			PORTD|=0x06;
			_delay_ms(500);
			PORTD&=~0x06;
			_delay_ms(500);
			DDRD|=0x5B;
			PORTD|=0x5B;
			_delay_ms(500);
			PORTD&=~0x5B;
			_delay_ms(500);
			DDRD|=0x4F;
			PORTD|=0x4F;
			_delay_ms(500);
			PORTD&=~0x4F;
			_delay_ms(500);
			DDRD|=0x6E;
			PORTD|=0x6E;
			_delay_ms(500);
			PORTD&=~0x6E;
			_delay_ms(500);
			DDRD|=0x6D;
			PORTD|=0x6D;
			_delay_ms(500);
			PORTD&=~0x6D;
			_delay_ms(500);
			DDRD|=0x7D;
			PORTD|=0x7D;
			_delay_ms(500);
			PORTD&=~0x7D;
			_delay_ms(500);
			DDRD|=0x07;
			PORTD|=0x07;
			_delay_ms(500);
			PORTD&=~0x07;
			_delay_ms(500);
			DDRD|=0xFF;
			PORTD|=0xFF;
			_delay_ms(500);
			PORTD&=~0xFF;
			_delay_ms(500);
			DDRD|=0xEF;
			PORTD|=0xEF;
			_delay_ms(500);
			PORTD&=~0xEF;
			_delay_ms(500);
			if (PORTD|=0xEF){
				j++;
				if (j==0){
				DDRC|=0x3F;
				PORTC|=0x3F;
				_delay_ms(500);
				PORTC&=~0x3F;
				_delay_ms(500);}
				if (j==1){
				DDRC|=0x06;
				PORTC|=0x06;
				_delay_ms(500);
				PORTC&=~0x06;
				_delay_ms(500);}
				if (j==2){
				DDRC|=0x5B;
				PORTC|=0x5B;
				_delay_ms(500);
				PORTC&=~0x5B;
				_delay_ms(500);}
				if (j==3){
				DDRC|=0x4F;
				PORTC|=0x4F;
				_delay_ms(500);
				PORTC&=~0x4F;
				_delay_ms(500);}
				if (j==4){
				DDRC|=0x6E;
				PORTC|=0x6E;
				_delay_ms(500);
				PORTC&=~0x6E;
				_delay_ms(500);}
				if (j==5){
				DDRC|=0x6D;
				PORTC|=0x6D;
				_delay_ms(500);
				PORTC&=~0x6D;
				_delay_ms(500);}
				if (j==6){
				DDRC|=0x7D;
				PORTC|=0x7D;
				_delay_ms(500);
				PORTC&=~0x7D;
				_delay_ms(500);}
				if (j==7){
					
				DDRC|=0x07;
				PORTC|=0x07;
				_delay_ms(500);
				PORTC&=~0x07;
				_delay_ms(500);}
				if (j==8){
				DDRC|=0xFF;
				PORTC|=0xFF;
				_delay_ms(500);
				PORTC&=~0xFF;
				_delay_ms(500);}
				if (j==9){
				DDRC|=0xEF;
				PORTC|=0xEF;
				_delay_ms(500);
				PORTC&=~0xEF;
				_delay_ms(500);
				
				}
				
			
			
			
			
			
			
			
			
			
			
			
			
		}
		
		
		}
		
		
    }
}

