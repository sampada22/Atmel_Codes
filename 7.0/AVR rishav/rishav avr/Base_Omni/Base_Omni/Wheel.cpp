#include "uart.h"
#include "Wheel.h"


void Wheel::init()
{
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
	uart0_puts("Uart is working..\r\n");
	robot_rpm = 700;
	for(int i=0;i<4;i++)
	{
		velocity_motor[i] = 0;
		velocity_robot[i] = 0;
	}
	m1.Initialise(1);
	m2.Initialise(2);
	m3.Initialise(3);
	m4.Initialise(4);
}

void Wheel::init_robvel(int vel)
{
	for(int i=0;i<3;i++)
		velocity_robot[i] = vel;
}

void Wheel::get_joystick_data()
{
   char data = '0';
    
	
    if(uart0_available())
    {
        data =uart0_getc();
		
    }
	else
	{
		data ='0';
	}
	
    switch (data)
    {
	    case 'F':
		init_robvel(0);
	    velocity_robot[0] = robot_rpm;
		break;
	    case 'B':
		init_robvel(0);
	    velocity_robot[0] = -robot_rpm;
		break;
	    case 'L':
		init_robvel(0);
	    velocity_robot[1] = robot_rpm;
		break;
	    case 'R':
		init_robvel(0);
	    velocity_robot[1] = -robot_rpm;
		break;
	    case 'G':
		init_robvel(0);
	    velocity_robot[2] = robot_rpm;
		break;
	    case 'I':
		init_robvel(0);
	    velocity_robot[2] = -robot_rpm;
		break;
		case 'i':
		robot_rpm =robot_rpm+10;
		break;
		case 'd':
		robot_rpm =robot_rpm-10;
		break;
		case 'S':
		init_robvel(0);
		break;
    }
	//uart0_putint(robot_rpm);
	if (robot_rpm>700) robot_rpm =700;
	if (robot_rpm<0) robot_rpm = 0;
}

void Wheel::calculate_wheel_velocity()
{
	float coupling_matrix[4][3] = {{-0.707,0.707,1},{-0.707,-0.707,1},{0.707,-0.707,1},{0.707,0.707,1}};
    for(int i=0;i<4;i++)
    {
        velocity_motor[i] = 0;
        for(int j=0;j<3;j++)
        {
             velocity_motor[i] += velocity_robot[j] * coupling_matrix[i][j];
        }
    }
	
    for(int i=0;i<4;i++)
    {
        ocr_motor[i] = (int(249*velocity_motor[i])/(MAX_RPM));//multiply by icr_top value
		uart0_puts(" OCR: ");
		uart0_putint(ocr_motor[i]);
		//velocity_robot[i] = 0;
	  
    }
	 uart0_puts("\r\n");
}

void Wheel::update_wheel_velocity()
{
    m1.SetOcrValue(ocr_motor[0]);
    m2.SetOcrValue(ocr_motor[1]);
    m3.SetOcrValue(ocr_motor[2]);
    m4.SetOcrValue(ocr_motor[3]);
}
