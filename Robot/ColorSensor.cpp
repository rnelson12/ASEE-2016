#include "ColorSensor.h"



ColorSensor::ColorSensor()
{
  
}


ColorSensor::~ColorSensor()
{
  
}

bool ColorSensor::isRed()
{
	int currentSensorValue = 0;//TODO: get value from sensor
	if (currentSensorValue == redComparisonValue)
	{
		return true;
	}
	else {
		return false;
	}
}
