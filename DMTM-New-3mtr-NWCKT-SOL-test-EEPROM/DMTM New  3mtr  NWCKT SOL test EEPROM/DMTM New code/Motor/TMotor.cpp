/*
 * MOTORA.cpp
 *
 * Created: 2/11/2017 9:50:55 PM
 *  Author: Bibek Shrestha
 */ 




 #define DD_F		K,0
 #define DD_B		K,1

 
 #define DD_M		H,4
 

 #define DD_HOMELIMIT	C,5

 #define FL_INTPIN		C,7



#include "TMotor.h"
#include "MzMotorBack.h"
#include "MzMotorFront.h"


extern MzMotorFront MagazineFront;
extern MzMotorBack MagazineBack;


void TMotor::Initialise()
{
	
	InitLimitSwitch();
	SetForwardDirection();



	OUTPUT(DD_B);
	OUTPUT(DD_F);
	OUTPUT(DD_M);

	

	Status = NOTGOINGANYWHERE;
	Position = HOMEPOSITION;

	LastState = true;
	LimitFlag = true;
	ChangeFlag = false;
	ShouldStop = true;
	
	ReadyFlag = false;
	EnableControl = false;
	MoveBackward();

}



void TMotor::InitLimitSwitch()
{
	PULLUP_ON(FL_INTPIN);
	PULLUP_ON(DD_HOMELIMIT);
	
}


void TMotor::SetForwardDirection()
{
	SET(DD_F);
	CLEAR(DD_B);

}

void TMotor::SetReverseDirection()
{
	CLEAR(DD_F);
	SET(DD_B);
	
}

void TMotor::StopMotor()
{
	SET(DD_F);
	SET(DD_B);
	
	CLEAR(DD_M);
}


void TMotor::MoveForward()
{
	SetForwardDirection();
	SET(DD_M);
}

void TMotor::MoveBackward()
{
	SetReverseDirection();
	SET(DD_M);
}



void TMotor::ControlLogic()
{
	
	
	switch(Status)
	{
		case GOING_UP:
		if(LimitFlag)
		{

			MoveBackward();
			//SetReverseDirection();
			//SetOcrValue(1000);
					
		}
		break;

		case GOING_MID:
		if(LimitFlag)
		{

			StopMotor();

		}
		break;

		case GOING_HOME:
		if(LimitFlag)
		{
			StopMotor();
			
			MagazineFront.Operate(true);
			MagazineBack.Operate(true);

			
		}
		break;

		case GOING_MID_BACK:
		if(LimitFlag)
		{
			MoveBackward();
			//SetReverseDirection();
			//SetOcrValue(1000);
		}
		break;
		
	}

}


void TMotor::ProcessInput(unsigned char Rx)
{
	
	if( Rx == 't' )
	{

		if(Status == NOTGOINGANYWHERE)
		{
			if(Position == MIDPOSITION)
			{
				MoveForward();
				//SetForwardDirection();
				//SetOcrValue(1000);
			
			}
			else if( (Position == HOMEPOSITION) && ReadyFlag)
			{
				MoveForward();
				//SetForwardDirection();
				//SetOcrValue(1000);
			
				
			}
			
		}
	}

}



void TMotor::UpdateStatus()
{
	
	if(ChangeFlag )
	{
		
		if(Position)
		{
			
			if(Position == HOMEPOSITION)
			{
				
				Position = NONPOSITION;
				Status = GOING_MID;
				
			}
			else if(Position == MIDPOSITION)
			{
				Position = NONPOSITION;
				Status = GOING_UP;
			
			}
			else if(Position == UPPOSITION)
			{
				Position = NONPOSITION;
				Status = GOING_MID_BACK;
			
			}
			else if (Position == MIDBACKPOSITION)
			{
				Position = NONPOSITION;
				Status   = GOING_HOME;
	
			}

		}
		else if(Status)
		{
			
			if (Status == GOING_MID)
			{
				Position = MIDPOSITION;
				Status = NOTGOINGANYWHERE;
				
			}
			else if(Status == GOING_MID_BACK)
			{
				Position = MIDBACKPOSITION;
				Status = NOTGOINGANYWHERE;
				
			}
			else if(Status == GOING_UP)
			{
				Position = UPPOSITION;
				Status = NOTGOINGANYWHERE;
				
			}
			else if(Status == GOING_HOME)
			{
				Position = HOMEPOSITION;
				Status = NOTGOINGANYWHERE;
				
			}
		}
		
		
	}
	ChangeFlag = false;
	
}


void TMotor::DoNothing()
{
	uart0_puts("This is nothing\n\r");
	uart3_puts("This is nothing\n\r");
}





bool TMotor::Operate( unsigned char Rx )
{	
	
	if(EnableControl)
	{
		LimitFlag = READ(FL_INTPIN);
		ChangeFlag = (LastState != LimitFlag);
		LastState = LimitFlag ;

		
		if(MagazineFront.LimitFlag && MagazineBack.LimitFlag)
		{
			ReadyFlag = true;
		}
		else
		{
			ReadyFlag = false;
		}



		ProcessInput(Rx);
		ControlLogic();
		UpdateStatus();

	}
	else
	{	

		if(!READ(DD_HOMELIMIT))
		{
			EnableControl = true;
			Position = HOMEPOSITION;
			Status   = NOTGOINGANYWHERE;
			StopMotor();
		}
		else
		{
			MoveBackward();
		}
	}

	

	return true;

}







