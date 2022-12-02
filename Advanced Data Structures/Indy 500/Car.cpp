// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// raparks

#include "Car.h"
//constructor
Car::Car()
{
	
}
//constructor with attributes
Car::Car(std::string name, int speed, int control, int lapNumber)
{
	name_ = name;
	speed_ = speed;
	control_ = control;
	lapNumber_ = lapNumber;
}
//creation of destructor
Car::~Car() 
{
	
}
//accessor methods/functions
void Car::setName(std::string name)
{
	name_ = name;
	
}
std::string Car::getName()
{
	return name_;
}
void Car::setSpeed(int speed)
{
	speed_ = speed;
}
int Car::getSpeed()
{
	return speed_;
}
void Car::setControl(int control)
{
	control_ = control;
}
int Car::getControl()
{
	return control_;
}
void Car::setLapNum(int lapNumber)
{
	lapNumber_ = lapNumber;
}
int Car::getLapNum()
{
	return lapNumber_;
}

	
	