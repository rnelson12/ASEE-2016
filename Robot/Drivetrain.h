#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Wheel.h"
#include "Wheel.h"
#include "Types.h"
#include "Configure.h"

class DriveTrain
{
public:
  DriveTrain(int defaultLeftPower,int defaultRightPower);
	//DriveTrain(byte leftMotorForward, byte leftMotorBackward, byte rightMotorForward, byte rightMotorBackward, byte power, byte wheelRadius);
	void drive(byte power, State direction);
private:
	Wheel *left;
	Wheel *right;
    int rightPower;
    int leftPower;
};

#endif
