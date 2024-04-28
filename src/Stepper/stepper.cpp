#include "stepper.h"

Stepper::Stepper(uint8_t DIR, uint8_t STEP)
{
	this->_dir_pin = DIR;
	this->_step_pin = STEP;

	pinMode(this->_dir_pin, OUTPUT);
	pinMode(this->_step_pin, STEP);

	digitalWrite(this->_dir_pin, LOW);
	digitalWrite(this->_step_pin, LOW);

	this->_speed=1.0;
	this->_direction=false;
	this->_enableUsed=false;
	this->_isEnabled=true;
}


void Stepper::setDirection(bool direction)
{
	if (_direction)
	{
		digitalWrite(this->_dir_pin, HIGH);
	}
	else
	{
		digitalWrite(this->_dir_pin, LOW);
	}
	this->_direction = direction;
}

bool Stepper::direction()
{
	return this->_direction;
}

void Stepper::setSpeed(uint8_t speed)
{
	this->_speed = speed;
	_MICROSECONDS_PER_MICROSTEP = (1000000/(STEPS_PER_REV * MICROSTEPS_PER_STEP)/(speed / 60));

}

uint8_t Stepper::speed()
{
	return this->_speed;
}

void Stepper::setEnablePin(uint8_t enablePin)
{
	this->_enable_pin = enablePin;
	this->_enableUsed = true;
}

void Stepper::enable()
{
	if (_enableUsed)
	{
		pinMode(this->_enable_pin, LOW);
		this->_isEnabled=true;
	}

}

void Stepper::disable()
{
	if (_enableUsed)
	{
		pinMode(this->_enable_pin, HIGH);
		this->_isEnabled=false;
	}
}

bool Stepper::isEnabled()
{
	return this->_isEnabled;
}


void Stepper::step()
{
	digitalWrite(this->_step_pin, HIGH);
	delayMicroseconds(_MICROSECONDS_PER_MICROSTEP / 2);
	digitalWrite(this->_step_pin, LOW);
	delayMicroseconds(_MICROSECONDS_PER_MICROSTEP / 2);
}

void Stepper::run(long steps, bool dir)
{
	this->setDirection(dir);
	for (int i = 0; i < steps; i++)
	{
		this->step();
	}
}