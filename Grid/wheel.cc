#include "Wheel.h"

Wheel::Wheel(int pin,int wheelOffset){
	pin=pin;
	offset=wheelOffset;
}

void Wheel::setPower(int newPower){
	power=newPower
	analogWrite(pin,(power+offset));
}