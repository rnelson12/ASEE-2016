#include "Wheel.h"

Wheel::Wheel(int forwardPin,int backPin,int wheelOffset){
  pin=forwardPin;
  offset=wheelOffset;
  reversePin=backPin;
  pinMode(pin,OUTPUT);
  pinMode(reversePin,OUTPUT);
}

void Wheel::setPower(int pwr){
  if(bitRead(pwr,15)==1){
    //write to the reverse pin
    power=pwr*-1;
    //may need a maping function here because pwr may be a percent...
  }else{
    power=pwr;
    
  }
}

