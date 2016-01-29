#include "Wheel.h"

Wheel::Wheel(byte motorForward, byte motorBackward, byte radius, byte power)
{
	_motorPinForward = motorForward;
	_motorPinBackward = motorBackward;
	_radius = radius;
	_power = power;
}

Wheel::~Wheel()
{
}

void Wheel::setPower(byte powerValue)
{
	_power = powerValue;
}

int Wheel::calculateDistance()
{
	return 0;
}
