/*
 * debug_encoder.cpp
 *
 * Created: 12/10/2017 1:59:29 AM
 * Author : Sampada Dhakal
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

int compare1(void);

int compare2(void);

int compare3(void);
volatile long signed count0 = 0;
volatile long signed count1 = 0;
volatile long signed count2 = 0;
int a = 0;


int main(void)
{  	
	DDRC = (0<<PINC7)|(0<<PINC6)|(0<<PINC5);
	PORTC = (0<<PINC7)|(0<<PINC6)|(0<<PINC5);
	DDRD |=(0<<PIND4)|(0<<PIND5)|(0<<PIND6);
	PORTD |= (1<<PIND4)|(1<<PIND5)|(1<<PIND6);
	
	lcd_init();       
	MCUCR |= (1<<ISC01)| (1<<ISC00)|(1<<ISC10)|(1<<ISC11); // trigger at rising edge
	MCUCSR |= (1<<ISC2);
	GICR  |= (1<<INT0)|(1<<INT1);                   //enable interrupts 0,1,2 
	GICR |= (1<<INT2);
	sei();
    
	while(1)
	{ 
    if (bit_is_clear(PIND,5)){
	lcd_gotoxy(2,2);
	lcd_puts("Rotate motor 1");
	lcd_gotoxy(2,1);
	lcd_puts("                ");

	}
	if (bit_is_clear(PIND,6)){
		lcd_gotoxy(2,2);
		lcd_puts("Rotate motor 2");
		lcd_gotoxy(2,1);
		lcd_puts("                ");

     
	}
	if (bit_is_clear(PIND,7)){
		lcd_gotoxy(2,2);
		lcd_puts("Rotate motor 3");
		lcd_gotoxy(2,1);
		lcd_puts("                ");

}
	}
}
    int compare1(void){
		  if (a == 1){
			  lcd_clear();
			  lcd_puts("       ");
			  lcd_gotoxy(2,1);
			  lcd_puts("clk:");
			  lcd_putint(count0);
		  }
		  if (a == 2){
			 lcd_clear();
			  lcd_puts("         ");
			  lcd_gotoxy(2,1);
			  lcd_puts("anticlk:");
			    lcd_putint(count0);
		  }
	}
	int compare2(void){
		  	if (a == 3){

		   		lcd_puts("                ");
		   		lcd_gotoxy(2,1);
		   		lcd_puts("clk:");
				     lcd_putint(count1);
					
		   	}
		   	if (a == 4){
		   	
		   		lcd_puts("                ");
		   		lcd_gotoxy(2,1);
		   		lcd_puts("anticlk:");
				     lcd_putint(count1);
					 
		   	}
	}
	int compare3(void){
		   	if (a == 5){
		   		lcd_puts("                ");
		   		lcd_gotoxy(2,1);
		   		lcd_puts("clk:");
				     lcd_putint(count2);
		   	}
		   	if (a == 6){
		   		lcd_puts("                ");
		   		lcd_gotoxy(2,1);
		   		lcd_puts("anticlk:");
				     lcd_putint(count2);
		   	}
	}
ISR (INT0_vect){
	
	if (bit_is_set(PINC,7)){
	count0++;
	a = 1;
	compare1();
	}
	
	else if (bit_is_clear(PINC,7)){
		count0--;
		a = 2;
		compare1();
}
}

ISR (INT1_vect){
	
	if (bit_is_set(PINC,6)){
		count1++;
		a = 3;
		
		compare2();
		
	}
	
	else if (bit_is_clear(PINC,6)){
		count1--;
		a = 4;
		
		compare2();
	}
}


ISR (INT2_vect){
	
	if (bit_is_set(PINC,5)){
		count2++;
		a = 5;
		compare3();
		
	}
	
	else if (bit_is_clear(PINC,5)){
		count2--;
		a = 6;
		compare3();
	}
}
