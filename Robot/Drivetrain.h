#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <EEPROM.h>
#include <EEPROMAnything.h>
#include <Wheel.h>
#include <Grid.h>

typedef unsigned char byte;

class Drivetrain
{
public:
	Drivetrain(byte leftMotorForward, byte leftMotorBackward, byte rightMotorForward, byte rightMotorBackward, byte power, byte wheelRadius);
	~Drivetrain();
	void drive(byte power, enum direction);
private:
	Wheel *leftWheel;
	Wheel *rightWheel;
	Grid *sensors;
};

#endif