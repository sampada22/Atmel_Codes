/* 
* MotorSide.cpp
*
* Created: 7/21/2017 6:32:54 PM
* Author: Bibek Shrestha
*/


#include "MotorSide.h"

 #define ICR_TOP   3999
 #define MAX_VALUE 2800
 #define MIN_VALUE 120
 

 #define DD_F K,3
 #define DD_B K,2


 
 

 #define DD_PWM			L,3
 #define PWM_TCCRA		TCCR5A
 #define PWM_TCCRB		TCCR5B
 #define PWM_ICR		ICR5
 #define PWM_OCR		OCR5A

 #define PWM_COM0		COM5A0
 #define PWM_COM1		COM5A1

 #define PWM_WGM0		WGM50
 #define PWM_WGM1		WGM51
 #define PWM_WGM2		WGM52
 #define PWM_WGM3		WGM53
 #define PWM_CS0		CS50
 #define PWM_CS1		CS51
 #define PWM_CS2		CS52
 

 //Timer 4 for RPM calculations
 #define M_TCCRA		TCCR4A
 #define M_TCCRB		TCCR4B
 #define M_TCCRC		TCCR4C
 #define M_TIMSK		TIMSK4
 #define M_TCNT			TCNT4
 #define M_CS0			CS40
 #define M_CS1			CS41
 #define M_CS2			CS42
 #define M_TOIE			TOIE4




#include "MotorSide.h"




void MotorSide::Initialise()
{
	InitPWM();
	InitCounter();
	InitInterrupt();
	Controller.Initialise();
	LowSpeedFlag = false;
	Controller.Set_PID(0.06, 0.0076, 0.05);
	Controller.Set_Setpoint(300);
	SetForwardDirection();
	ClearCounter();
	LastRPM = 0;
	OCR = 120;
	

}

void MotorSide::InitCounter()
{
	REGISTER_SET1(M_TIMSK,M_TOIE);
	REGISTER_SET2(M_TCCRB,M_CS1,M_CS0);								//ps 64
}

void MotorSide::InitPWM()
{
	OUTPUT(DD_F);
	OUTPUT(DD_B);
	
	OUTPUT(DD_PWM);
	PWM_TCCRA	|=  ( 1 << PWM_COM1 ) | ( 1 << PWM_WGM1 );													//
	PWM_TCCRB	|=  ( 1 << PWM_WGM2 ) | ( 1 << PWM_WGM3 ) | ( 1 << PWM_CS0);													//no prescaling
	PWM_ICR		 =         ICR_TOP;
}

void MotorSide::InitInterrupt()
{
	
	PULLUP_ON(MOTORBACK_INTPIN);
	
	REGISTER_SET2(SIDEMOTOR_EICR,SIDEMOTOR_ISC1,SIDEMOTOR_ISC0);
	REGISTER_SET1(EIMSK,SIDEMOTOR_INT );
	REGISTER_SET1(EIFR ,SIDEMOTOR_INTF);

}


void MotorSide::SetForwardDirection()
{
	SET(DD_F);
	CLEAR(DD_B);

}
void MotorSide::SetReverseDirection()
{
	CLEAR(DD_F);
	SET(DD_B);
	
}

void MotorSide::StopMotor()
{
	SET(DD_F);
	SET(DD_B);
	
	SetOcrValue(MIN_VALUE);
}


void MotorSide::SetOcrValue(int x)
{
	if(x < 0)
	{
		
		//SetReverseDirection();
		//Ocr = 0 - x;
		Ocr = 0;
	}
	else
	{
		SetForwardDirection();
		Ocr	= x;
	}
	
	if(Ocr >= MAX_VALUE)
		Ocr = MAX_VALUE;
	if(Ocr <= MIN_VALUE)
		Ocr = MIN_VALUE;
	
	
	PWM_OCR		= Ocr;
}

void MotorSide::IncreaseSpeed()
{
	SetOcrValue(Ocr + 40);
}

void MotorSide::DecreaseSpeed()
{ 
	SetOcrValue(Ocr - 40);
}

void MotorSide::ClearCounter()
{
	REGISTER_CLEAR(M_TCNT);
}


bool MotorSide::Operate(unsigned char &rx, unsigned char &Command)
{
	
	if(IntFlag)
	{
		Overflow = 0;

		LastRPM = RPM;

		if(Count != 0)
		{
			RPM = float(3750000.f)/float(Count);
		}
		

		if( abs(LastRPM - RPM) > 1000 )
		{
			RPM = LastRPM;
		}

		IntFlag = false;
 
	}

	//SetOcrValue(Ocr + Controller.Compute_PID(RPM, true));
	PWM_OCR = OCR;


/*
	uart0_putint(Ocr);
	uart0_putc(' ');

	uart0_putint(0);
	uart0_putc(' ');
	uart0_putint(RPM);
	uart0_putc(' ');
	uart0_putint(Controller.setpoint);


	uart0_putc('\n');
	uart0_putc('\r');
	*/



/*
	if(STATUS_DE_VALIDITY_BIT(Command))
	{
		if(STATUS_DE_INCREASE_SECOND_MOTOR_SPEED_BIT(Command))
		{
			Controller.Inc_Setpoint();
			RESET_INCREASE_SECOND_MOTOR_SPEED_BIT(Command);
		}
		else if(STATUS_DE_DECREASE_SECOND_MOTOR_SPEED_BIT(Command))
			{
				Controller.Dcr_Setpoint();
				RESET_DECREASE_SECOND_MOTOR_SPEED_BIT(Command);
			}
	}

*/


	
	switch(Command)
	{
		case 'c':
		Controller.Inc_Setpoint();
		OCR += 10;
		if(OCR >  MAX_VALUE)
		{
			OCR = MAX_VALUE;
		}
		
		break;
		case 'v':
		Controller.Dcr_Setpoint();
		OCR -= 10;
		if(OCR < MIN_VALUE)
		{
			OCR = MIN_VALUE;
		}
		break;
	}
	



	switch(rx)
	{
		
		case 'p':
		Controller.Inc_KP();
		
		uart0_putc('P');
		uart0_putc(':');
		uart0_putint(Controller.kp*100);
		uart0_putc('\n');
		uart0_putc('\r');
		
		break;
		
		case 'i':
		Controller.Inc_KI();
		
		uart0_putc('I');
		uart0_putc(':');
		uart0_putint(Controller.ki*1000);
		uart0_putc('\n');
		uart0_putc('\r');
		break;

		case 'd':
		Controller.Inc_KD();
		
		uart0_putc('D');
		uart0_putc(':');
		uart0_putint(Controller.kd*100);
		uart0_putc('\n');
		uart0_putc('\r');
		break;

		case 'l':
		Controller.Dcr_KP();
		
		uart0_putc('P');
		uart0_putc(':');
		uart0_putint(Controller.kp*100);
		uart0_putc('\n');
		uart0_putc('\r');
		

		break;
		
		case 'o':
		Controller.Dcr_KI();
		
		uart0_putc('I');
		uart0_putc(':');
		uart0_putint(Controller.ki*1000);
		uart0_putc('\n');
		uart0_putc('\r');
		break;

		case 'f':
		Controller.Dcr_KD();
		
		uart0_putc('D');
		uart0_putc(':');
		uart0_putint(Controller.kd*100);
		uart0_putc('\n');
		uart0_putc('\r');
		break;

		case 't':
		Controller.Inc_Setpoint();
		
		uart0_putc('S');
		uart0_putc(':');
		uart0_putint(Controller.setpoint);
		uart0_putc('\n');
		uart0_putc('\r');
		
		break;

		case 'y':
		Controller.Dcr_Setpoint();
		
		uart0_putc('S');
		uart0_putc(':');
		uart0_putint(Controller.setpoint);
		uart0_putc('\n');
		uart0_putc('\r');
		
		break;

		
		//break;
		
		case 's':
		case 'S':
		StopMotor();

		uart0_puts(" A:");
		uart0_putint(Ocr);

		break;


		case 'r':
		Controller.Set_PID(0,0,0);
		break;

		case 'v':
		//	uart0_puts(" R:");
		//	uart0_putint(RPM);
		uart0_puts("Pa:");
		uart0_putint(Ocr);
		uart0_putc(' ');
		uart0_putc('P');
		uart0_putc(':');
		uart0_putint(Controller.kp*100);
		uart0_putc(' ');
		uart0_putc('I');
		uart0_putc(':');
		uart0_putint(Controller.ki*10000);
		uart0_putc(' ');
		uart0_putc('D');
		uart0_putc(':');
		uart0_putint(Controller.kd*100);
		uart0_putc('\n');
		uart0_putc('\r');
		//uart0_puts(" S:");
		//uart0_putint(Controller.setpoint);
		uart0_puts("\n\r");
		break;
	}

	return false;
}
