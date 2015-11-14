#include "Drivetrain.h"



Drivetrain::Drivetrain(byte leftMotorForward, byte leftMotorBackward, byte rightMotorForward, byte rightMotorBackward, byte power, byte wheelRadius)
{
	leftWheel = new Wheel(leftMotorForward, leftMotorBackward, power, wheelRadius);
	rightWheel = new Wheel(rightMotorForward, rightMotorBackward, power, wheelRadius);
	sensors = new Grid();
}

Drivetrain::~Drivetrain()
{
	delete leftWheel;
	delete rightWheel;
	delete sensors;
	leftWheel = nullptr;
	rightWheel = nullptr;
	sensors = nullptr;
}

void Drivetrain::drive(byte power, direction)
{
	byte leftPower;
	byte rightPower;
	//Calculate how much power to each wheel from direction


	leftWheel->setPower(leftPower);
	rightWheel->setPower(rightPower);
}
