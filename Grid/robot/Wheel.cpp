#include "Wheel.h"

Wheel::Wheel(int pinNumber,int wheelOffset){
  pin=pinNumber;
  offset=wheelOffset;
}

void Wheel::setPower(int pwr){
  power=pwr;
}

