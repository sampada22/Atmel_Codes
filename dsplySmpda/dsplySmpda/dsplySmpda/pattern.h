				/*
 * pattern.h
 *
 * Created: 11/21/2017 3:13:13 AM
 * Author : Rishav
 */ 

 #ifndef F_CPU
	#define F_CPU 16000000UL
#endif /*F_CPU*/
 
 #ifndef PATTERN_H
  #define PATTERN_H

void get_pattern(char character, uint8_t delay_time);
void blank_pattern(uint8_t delay_time);
void delay(uint8_t delay_time); // Delay in ms

#endif /*PATTERN_H*/