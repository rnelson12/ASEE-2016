#ifndef DRIVETRAIN_h
#define DRIVETRAIN_h

#include "Wheel.h"
#include "Types.h"
#include <Arduino.h>
#include "Configure.h"

class DriveTrain{
	
public:
	DriveTrain(int defaultRightPower, int defaultLeftPower);
	void drive(int power, State direction);
private:
  int rightPower;
  int leftPower;
};

#endif
