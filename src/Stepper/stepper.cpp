#include "stepper.h"

Stepper::Stepper(uint8_t DIR, uint8_t STEP, bool enabledUsed = false)
{
	this->_dir_pin = DIR;
	this->_step_pin = STEP;

	pinMode(_dir_pin, OUTPUT);
	pinMode(_step_pin, STEP);

	this->_speed=1.0;
	this->_direction=false;
}


void setDirection(bool direction)
{
	this->_direction = direction;
}

bool direction()
{
	return this->_direction;
}

void setSpeed(float speed)
{
	this->_speed = speed;
}

void speed()
{
	return this->_speed;
}


