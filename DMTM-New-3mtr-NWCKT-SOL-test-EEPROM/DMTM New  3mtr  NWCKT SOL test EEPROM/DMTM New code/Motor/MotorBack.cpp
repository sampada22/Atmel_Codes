
/*
 * MOTORA.cpp
 *
 * Created: 2/11/2017 9:50:55 PM
 *  Author: Bibek Shrestha
 */ 



 #define ICR_TOP   3999
 #define MAX_VALUE 2800
 #define MIN_VALUE 120
 

 #define DD_F K,6
 #define DD_B K,7


 
 

 #define DD_PWM			L,5
 #define PWM_TCCRA		TCCR5A
 #define PWM_TCCRB		TCCR5B
 #define PWM_ICR		ICR5
 #define PWM_OCR		OCR5C

 #define PWM_COM0		COM5C0
 #define PWM_COM1		COM5C1

 #define PWM_WGM0		WGM50
 #define PWM_WGM1		WGM51
 #define PWM_WGM2		WGM52
 #define PWM_WGM3		WGM53
 #define PWM_CS0		CS50
 #define PWM_CS1		CS51
 #define PWM_CS2		CS52
 

 //Timer 3 for RPM calculations
 #define M_TCCRA		TCCR3A
 #define M_TCCRB		TCCR3B
 #define M_TCCRC		TCCR3C
 #define M_TIMSK		TIMSK3
 #define M_TCNT			TCNT3
 #define M_CS0			CS30
 #define M_CS1			CS31
 #define M_CS2			CS32
 #define M_TOIE			TOIE3

 #define LTP			2000
 #define UTP			2300



#include "MotorBack.h"




void MotorBack::Initialise()
{
	InitPWM();
	InitCounter();
	InitInterrupt();
	Controller.Initialise();
	LowSpeedFlag = false;
	Controller.Set_PID(0.14, 0, 1.78);
	SetForwardDirection();
	SetOcrValue(20);
	ClearCounter();
	LastRPM = 0;

}

void MotorBack::InitCounter()
{
	REGISTER_SET1(M_TIMSK,M_TOIE);
	REGISTER_SET2(M_TCCRB,M_CS1,M_CS0);						//ps 64
}

void MotorBack::InitPWM()
{
	OUTPUT(DD_F);
	OUTPUT(DD_B);
	
	OUTPUT(DD_PWM);
	PWM_TCCRA	|=  ( 1 << PWM_COM1 ) | ( 1 << PWM_WGM1 );													//
	PWM_TCCRB	|=  ( 1 << PWM_WGM2 ) | ( 1 << PWM_WGM3 ) | ( 1 << PWM_CS0);													//no prescaling
	PWM_ICR		 =         ICR_TOP;
}

void MotorBack::InitInterrupt()
{
	
	PULLUP_ON(MOTORBACK_INTPIN);
	
	REGISTER_SET2(MOTORBACK_EICR,MOTORBACK_ISC1,MOTORBACK_ISC0);
	REGISTER_SET1(EIMSK,MOTORBACK_INT );
	REGISTER_SET1(EIFR ,MOTORBACK_INTF);

}


void MotorBack::SetForwardDirection()
{
	SET(DD_F);
	CLEAR(DD_B);

}
void MotorBack::SetReverseDirection()
{
	CLEAR(DD_F);
	SET(DD_B);
	
}

void MotorBack::StopMotor()
{
	SET(DD_F);
	SET(DD_B);
	
	SetOcrValue(MIN_VALUE);
}


void MotorBack::SetOcrValue(int x)
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

void MotorBack::IncreaseSpeed()
{
	SetOcrValue(Ocr + 40);
}

void MotorBack::DecreaseSpeed()
{ 
	SetOcrValue(Ocr - 40);
}

void MotorBack::ClearCounter()
{
	REGISTER_CLEAR(M_TCNT);
}


bool MotorBack::Operate(unsigned char &rx, unsigned char &Command)
{
	
	if(IntFlag)
	{
		Overflow = 0;

		LastRPM = RPM;
		if(Count != 0)
		{
			RPM = float(15000000.f)/float(Count);
		}
		
		if( abs(LastRPM - RPM) > 1000 )
		{
			RPM = LastRPM;
		}

		
		IntFlag = false;
	}
	
	if(LowSpeedFlag)
	{
		if(Controller.setpoint > UTP)
		{
			LowSpeedFlag = false;
			Controller.Set_PID(.24, 0, 8.74);
		}
	}
	else
	{
		if(Controller.setpoint < LTP)
		{
			LowSpeedFlag = true;
			Controller.Set_PID(0.14, 0, 1.78);
		}
	}


	SetOcrValue(Ocr + Controller.Compute_PID(RPM, LowSpeedFlag));
	

/*	uart3_putint(Ocr);
	uart3_putc(' ');

	uart3_putint(0);
	uart3_putc(' ');
	uart3_putint(RPM);
	uart3_putc(' ');
	uart3_putint(Controller.setpoint);

	uart3_putc('\n');
	uart3_putc('\r');
*/

/*
	if(STATUS_DE_VALIDITY_BIT(Command))
	{
		
		
		if(STATUS_DE_INCREASE_FIRST_MOTOR_SPEED_BIT(Command))
			{
				Controller.Inc_Setpoint();
				RESET_INCREASE_FIRST_MOTOR_SPEED_BIT(Command);
			}
		else if(STATUS_DE_DECREASE_FIRST_MOTOR_SPEED_BIT(Command))
			{
				Controller.Dcr_Setpoint();
				RESET_DECREASE_FIRST_MOTOR_SPEED_BIT(Command);
			}	
	}

*/


	switch(Command)
	{
		case 'x':
			Controller.Inc_Setpoint();
			break;

		case 'z':
			Controller.Dcr_Setpoint();
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

		case '[':
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

		
		
		
		case 's':
		case 'S':
		case '.':
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
		uart0_puts("OCR:");
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
		uart0_putc(' ');
		uart0_puts(" S:");
		uart0_putint(Controller.setpoint);
		uart0_puts("\n\r");
		break;
	}	
	return false;

}















