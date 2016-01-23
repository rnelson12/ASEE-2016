#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Wheel.h"
#include "Grid.h"
#include "Wheel.h"
#include "Types.h"
#include <Arduino.h>
#include "Configure.h"

typedef unsigned char byte;

class Drivetrain
{
public:
	Drivetrain(byte leftMotorForward, byte leftMotorBackward, byte rightMotorForward, byte rightMotorBackward, byte power, byte wheelRadius);
	~Drivetrain();
	void drive(byte power, State direction);
private:
	Wheel *left;
	Wheel *right;
	Grid *sensors;
    int rightPower;
    int leftPower;
};

#endif
