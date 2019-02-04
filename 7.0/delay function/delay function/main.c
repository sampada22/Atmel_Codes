/*
 * delay function.c
 *
 * Created: 6/2/2017 5:31:32 AM
 * Author : Sampada Dhakal
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
void delay(int n);

int main(void)
{
   DDRB  |=(1<<0);
   TCCR1B |=((1<<CS10)|(1<<CS12));
   //int cnt,i,n;
    while (1) 
    {
		//PORTB ^=(1<<0);
		//delay(1000);
	   PORTB^=(1<<0);
	   delay(1);
	       }
}

void delay(int n)
{
	//int i;
	


		
		   TCNT1 = 0;
			 if (TCNT1 == n*15)
				
	   return;
		
		
	


}