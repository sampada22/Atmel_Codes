/* 
* MzMotorBack.cpp
*
* Created: 7/15/2017 8:27:19 AM
* Author: Bibek Shrestha
*/


#define DD_M F,0


#define DD_B F,1
#define DD_F F,2

#define MZ_INTPIN		G,1




#define COUNTPERSAUCER	80
#define BAND			10
#define MAX_ENCODER_VALUE 1170


#include "MzMotorBack.h"


void MzMotorBack::Initialise()
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



void MzMotorBack::InitInterrupt()
{
	
	PULLUP_ON(MZ_INTPIN);

}


void MzMotorBack::SetForwardDirection()
{
	SET(DD_F);
	CLEAR(DD_B);

}
void MzMotorBack::SetReverseDirection()
{
	CLEAR(DD_F);
	SET(DD_B);
	
}

void MzMotorBack::StopMotor()
{

	SET(DD_F);
	SET(DD_B);
	CLEAR(DD_M);

}



bool MzMotorBack::Operate(bool GoFlag)
{
	
	LimitFlag = !READ(MZ_INTPIN);


	if(GoFlag)
	{
		TargetCount += COUNTPERSAUCER;
	}


	Error = Encoder.Count - TargetCount;

	
	if( (  ( !VirginityFlag ) && ( Error >= BAND) ) || LimitFlag ) 
	{
		VirginityFlag = false;
		TargetCount = Encoder.Count - BAND;
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


void MzMotorBack::MoveUP()
{
	
	
	SetForwardDirection();
	SET(DD_M);

}



void MzMotorBack::MoveD()
{
	
	if(Encoder.Count > 50)
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

void MzMotorBack::PreMoveD()
{
	SetReverseDirection();
	SET(DD_M);
}




























// default constructor
MzMotorBack::MzMotorBack()
{
} //MzMotorBack

// default destructor
MzMotorBack::~MzMotorBack()
{
} //~MzMotorBack
