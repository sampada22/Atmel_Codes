/*
 * pov_2.cpp
 *
 * Created: 11/20/2017 5:17:00 AM
 * Author : Sampada Dhakal21211
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "pattern.h"


int main(void)
{  
     


																							

	
		
   
    while (1) 
    {

                get_pattern('A',1);			
	        blank_pattern(5);

		get_pattern('D',1);
		blank_pattern(5);

		get_pattern('A',1);
		blank_pattern(5);

		get_pattern('P',1);
		blank_pattern(5);

		get_pattern('M',1);
		blank_pattern(5);

		get_pattern('A',1);
		blank_pattern(5);

		get_pattern('S',1);
		blank_pattern(5);
}

}

