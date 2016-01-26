#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <EEPROM.h>
//#include <EEPROMAnything.h>
#include "Wheel.h"
#include "SensorGrid.h"
#include "Wheel.h"
#include "Types.h"
#include <Arduino.h>
#include "Configure.h"

//typedef unsigned char byte;

class DriveTrain
{
public:
  DriveTrain(int defaultLeftPower,int defaultRightPower);
	//DriveTrain(byte leftMotorForward, byte leftMotorBackward, byte rightMotorForward, byte rightMotorBackward, byte power, byte wheelRadius);
	~DriveTrain();
	void drive(byte power, State direction);
private:
	Wheel *left;
	Wheel *right;
	SensorGrid *sensors;
    int rightPower;
    int leftPower;
};

#endif
