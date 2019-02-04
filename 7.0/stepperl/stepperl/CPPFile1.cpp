/*
 * CPPFile1.cpp
 *
 * Created: 1/22/2018 6:42:31 AM
 *  Author: Sampada Dhakal
 */ 
#define F_CPU 16000000UL

#include<avr/io.h>
#include<util/delay.h>
#include "stepperchalaune.h"

void stepper_init(){
	DstepperDirPort |=(1<<DstepperDirPin);
	DstepperStepPort|= (1<<DstepperStepPin);	
}

void stepper_turnCLK(int n){
	int i = 0;
	PstepperDirPort |=(1<<PstepperDirPin);
	
	for (i = 0; i<n; i++){
		PstepperStepPort ^= (1<<PstepperStepPin);
		_delay_ms(50);
	}
	
}
void stepper_turnANTICLK(int n){
	int i = 0;
	PstepperDirPort |=(0<<PstepperDirPin);
	
	for (i = 0; i<n; i++){
		PstepperStepPort ^= (1<<PstepperStepPin);
		_delay_ms(50);
	}
	
}

