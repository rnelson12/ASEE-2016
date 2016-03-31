#include "ColorSensor.h"



ColorSensor::ColorSensor()
{
  RGB_sensor.init();
}


ColorSensor::~ColorSensor()
{
  
}

bool ColorSensor::isRed()
{
	unsigned int red=RGB_sensor.readRed();
	if (red == RED)
	{
		return true;
	}
	else {
		return false;
	}
}
