#include "src/Stepper/stepper.h"

#define motor_dir_pin 3
#define motor_step_pin 4
#define L_SW 8
#define R_SW 9
#define Limit_SW 5

#define MOTOR_RPM 1

Stepper motor (motor_dir_pin, motor_step_pin);

void setup()
{
	motor.setSpeed(MOTOR_RPM);
	pinMode(L_SW, INPUT);
	pinMode(R_SW, INPUT);
	pinMode(Limit_SW, INPUT);

}

void loop()
{
	if (digitalRead(L_SW)==HIGH)
	{
		motor.run(50, false);
	}
	else if (digitalRead(R_SW)==HIGH)
	{
		motor.run(50, true);
	}
	delay(10);
	
}
