/*
 * USART first program.c
 *
 * Created: 10/7/2017 6:21:19 PM
 * Author : Sampada Dhakal
 */ 

#include<avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

unsigned char variable;
void Config_USART0();

int main (void){
	Config_USART0();               //configure serial communication
	variable = 255;               //initialize data
	while (1){
		while {(!(UCSRA&(1<<UDRE)))//wait until UDR is empty
		UDR0 = variable;          //send data 
		variable -=1;            //modify data for next iteration
		_delay_ms(50);
	
		}
	}
	
	
}
void Config_USART0(){
	UCSRA =(2<<UPMOO)
}