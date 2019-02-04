#ifndef WHEEL_H
#define WHEEL_H



/*#incli*/
#include "uart.h"
#include "Motor.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

//#define PI           3.141592
#define MAX_RPM		   700							//In RPM	
//#define Duty_cycle     15                           //In percentage
//#define ROBOT_RPM      ((700*Duty_cycle)/100)      //In RPM
//#define Wheel_Radius 0.067                        //In meter
//#define MAX_VEL      MAX_RPM/(2*PI*Wheel_Radius)  //In m/s


class Wheel
{
     private:
     float velocity_robot[4];
	 uint16_t robot_rpm;
	 float velocity_motor[4];
     uint16_t ocr_motor[4];
        Motor m1,m2,m3,m4;


    public:

        

        void init();
		void init_robvel(int vel);
        void get_joystick_data();
        void calculate_wheel_velocity();
        void update_wheel_velocity();

};

#endif // WHEEL_H
