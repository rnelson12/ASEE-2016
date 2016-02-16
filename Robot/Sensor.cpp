#include "Sensor.h"

Sensor::Sensor(int sensorPin) {
	pin = sensorPin;
}

Sensor::~Sensor()
{
}

State Sensor::getValue() {
	return convertToBool(analogRead(pin));
}

State Sensor::convertToBool(int value) {
	if (value - 10<WHITE_STATE&&value + 10>WHITE_STATE) {
		return WHITE_STATE;
	}
	else if (value - 10<BLACK&&value + 10>BLACK) {
		return BLACK_STATE;
	}
	else {
		return NO_COLOR;
	}
}
