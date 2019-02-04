/* 
* MzMotor.cpp
*
* Created: 7/14/2017 4:49:31 PM
* Author: Bibek Shrestha
*/




#define DD_M F,5
#define DD_B F,4


#define DD_F F,3



#define MZ_INTPIN	D,7


#define COUNTPERSAUCER 80
#define BAND		10
#define MAX_ENCODER_VALUE 1170


#include "MzMotorFront.h"




void MzMotorFront::Initialise()
{	
	OUTPUT(DD_B);
	OUTPUT(DD_F);
	OUTPUT(DD_M);
	CLEAR(DD_M);

	InitInterrupt();
	Encoder.Initialise();
	LimitFlag = !READ(MZ_INTPIN);
	VirginityFlag = true;
}


void MzMotorFront::InitInterrupt()
{
	
	PULLUP_ON(MZ_INTPIN);

}


void MzMotorFront::SetForwardDirection()
{
	SET(DD_F);
	CLEAR(DD_B);

}
void MzMotorFront::SetReverseDirection()
{
	CLEAR(DD_F);
	SET(DD_B);
	
}

void MzMotorFront::StopMotor()
{
	SET(DD_F);
	SET(DD_B);
	CLEAR(DD_M);
	
}



bool MzMotorFront::Operate(bool GoFlag)
{
	
	LimitFlag = !READ(MZ_INTPIN);
	
	
	if(GoFlag)
	{
		TargetCount += COUNTPERSAUCER;
	}
	
	
	Error = Encoder.Count - TargetCount;

	
	if( ( (!VirginityFlag) && ( Error >= BAND) ) || LimitFlag ) 
	{
		VirginityFlag = false;
		TargetCount = Encoder.Count - BAND ;
		StopMotor();
		return false;
	}
	
	else if(Encoder.Count > MAX_ENCODER_VALUE)
	{
		StopMotor();
		return false;
	}
	else
	{
		MoveUP();
	}
	
	return true;
}

void MzMotorFront::MoveUP()
{
	SetForwardDirection();
	SET(DD_M);
	
}


void MzMotorFront::MoveD()
{
	
	if(Encoder.Count > 70)
	{
		SetReverseDirection();
		SET(DD_M);
	}
	else
	{
		
		StopMotor();
	}
	TargetCount = Encoder.Count;
	
}
void MzMotorFront::PreMoveD()
{
	SetReverseDirection();
	SET(DD_M);
}








// default constructor
MzMotorFront::MzMotorFront()
{
} //Mz_MotorFront

// default destructor
MzMotorFront::~MzMotorFront()
{
} //~Mz_MotorFront
