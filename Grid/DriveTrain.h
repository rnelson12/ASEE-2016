#ifndef DRIVETRAIN
#define DRIVETRAIN

#include "Types.h"
#include <Arduino.h>
#include "Config.h"

class DriveTrain{
	
public:
	DriveTrain(int defaultRightPower, int defaultLeftPower);
	void drive(int power, State direction);
private:
	Wheel left;
	Wheel right;
};

#endif