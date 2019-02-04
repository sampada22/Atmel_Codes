/*
 * stepperchalaune.h
 *
 * Created: 1/22/2018 6:41:18 AM
 *  Author: Sampada Dhakal
 */ 


#ifndef STEPPERCHALAUNE_H_
#define STEPPERCHALAUNE_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define PstepperDirPort PORTA
#define PstepperDirPin PINA1
#define PstepperStepPort PORTA
#define PstepperStepPin PINA0

#define DstepperDirPort DDRA
#define DstepperDirPin PINA1
#define DstepperStepPort DDRA
#define DstepperStepPin PINA0

void stepper_init();
void stepper_turnCLK(int );
void stepper_turnANTICLK(int );





#endif
 /* ST)
EPPERCHALAUNE_H_ */