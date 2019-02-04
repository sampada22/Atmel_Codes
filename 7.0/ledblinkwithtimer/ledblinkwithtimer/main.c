/*
 * ledblinkwithtimer.c
 *
 * Created: 6/1/2017 2:55:50 PM
 * Author : Sampada Dhakal
 */ 
#include<avr/io.h>
int main(void){
	DDRB|=(1<<0);
	TCCR1B|=((1<<CS10)|(1<<CS11));
	unsigned int i;
	i=0;
	while(1){
		if (TCNT1>=15624){
			TCNT1=0;
			i++;
			if (i==60){
				i=0;
			PORTB^=(1<<0);	
			}

			
		}
		
	
	
	
}
}