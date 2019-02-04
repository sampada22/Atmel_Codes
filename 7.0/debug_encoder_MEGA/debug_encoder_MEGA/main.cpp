/*
 * debug_encoder_MEGA.cpp
 *
 * Created: 1/3/2018 9:46:03 AM
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


struct direction{
	bool direction;
	};
struct flag{
	bool flag;
};
enum {
	clockwise,
	anticlockwise
};
	
struct direction motor1,motor2,motor3,motor4;
struct flag motor1, motor2,motor3,motor4;


int main(void)
{
	DDRC = (0<<PINC7)|(0<<PINC6)|(0<<PINC5);
	 	PORTC = (0<<PINC7)|(0<<PINC6)|(0<<PINC5);
	 	DDRD |=(0<<PIND4)|(0<<PIND5)|(0<<PIND6);
	 	PORTD |= (1<<PIND4)|(1<<PIND5)|(1<<PIND6);
	 	 
	lcd_init();
	EICRA |= (1<<ISC01)| (1<<ISC00)|(1<<ISC10)|(1<<ISC11)|(1<<ISC20)|(1<<ISC21); // trigger at rising edge
	//EICRB |= (1<<ISC20)|(1<<ISC21);
	EIMSK  |= (1<<INT0)|(1<<INT1)|(1<<INT2)|(1<<INT3);                   //enable interrupts 0,1,2
	//GICR |= (1<<INT2);
	sei();
	
	while(1)
	{
		if (bit_is_clear(PINF,0)){
			lcd_gotoxy(2,2);
			lcd_puts("Rotate motor 1");
			lcd_gotoxy(2,1);
			lcd_puts("                ");

		}
		if (bit_is_clear(PINF,1)){
			lcd_gotoxy(2,2);
			lcd_puts("Rotate motor 2");
			lcd_gotoxy(2,1);
			lcd_puts("                ");

			
		}
		if (bit_is_clear(PINF,2)){
			lcd_gotoxy(2,2);
			lcd_puts("Rotate motor 3");
			lcd_gotoxy(2,1);
			lcd_puts("                ");

		}
	}
}
int compare1(void){
	if (motor1.direction == clockwise){
		lcd_clear();
		lcd_puts("       ");
		lcd_gotoxy(2,1);
		lcd_puts("clk:");
		lcd_putint(count0);
	}
	if (motor1.direction == anticlockwise){
		lcd_clear();
		lcd_puts("         ");
		lcd_gotoxy(2,1);
		lcd_puts("anticlk:");
		lcd_putint(count0);
	}
}
int compare2(void){
	if (motor2.direction == clockwise){

		lcd_puts("                ");
		lcd_gotoxy(2,1);
		lcd_puts("clk:");
		lcd_putint(count1);
		
	}
	if (motor2.direction == anticlockwise){
		
		lcd_puts("                ");
		lcd_gotoxy(2,1);
		lcd_puts("anticlk:");
		lcd_putint(count1);
		
	}
}
int compare3(void){
	if (motor3.direction == clockwise){
		lcd_puts("                ");
		lcd_gotoxy(2,1);
		lcd_puts("clk:");
		lcd_putint(count2);
	}
	if (motor3.direction == anticlockwise){
		lcd_puts("                ");
		lcd_gotoxy(2,1);
		lcd_puts("anticlk:");
		lcd_putint(count2);
	}
}
ISR (INT0_vect){
	
	if (bit_is_set(PINA,0)){
		count0++;
		motor1.direction = clockwise;
		compare1();
	}
	
	else if (bit_is_clear(PINA,0)){
		count0--;
		motor1.direction = anticlockwise;
		compare1();
	}
}

ISR (INT1_vect){
	
	if (bit_is_set(PINA,1)){
		count1++;
		motor2.direction = clockwise;
		
		compare2();
		
	}
	
	else if (bit_is_clear(PINA,1)){
		count1--;
		motor2.direction = anticlockwise;
		
		compare2();
	}
}


ISR (INT2_vect){
	
	if (bit_is_set(PINA,2)){
		count2++;
		motor3.direction = clockwise;
		compare3();
		
	}
	
	else if (bit_is_clear(PINA,2)){
		count2--;
		motor3.direction = anticlockwise;
		compare3();
	}
}
// ISR (INT3_vect){
// 	
// 	if (bit_is_set(PINC,5)){
// 		count2++;
// 		motor3.direction = clockwise;
// 		compare4();
// 		
// 	}
// 	
// 	else if (bit_is_clear(PINC,5)){
// 		count2--;
// 		motor3.direction = anticlockwise;
// 		compare4();
// 	}
// }
// ISR (INT4_vect){
// 	
// 	if (bit_is_set(PINC,5)){
// 		count4++;
// 		motor5.direction = clockwise;
// 		compare4();
// 		
// 	}
// 	
// 	else if (bit_is_clear(PINC,5)){
// 		count4--;
// 		motor5.direction = anticlockwise;
// 		compare4();
// 	}
// }
// ISR (INT5_vect){
// 	
// 	if (bit_is_set(PINC,5)){
// 		count5++;
// 		motor6.direction = clockwise;
// 		compare5();
// 		
// 	}
// 	
// 	else if (bit_is_clear(PINC,5)){
// 		count5--;
// 		motor6.direction = anticlockwise;
// 		compare5();
// 	}
// }
// 
// 
