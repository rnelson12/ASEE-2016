#include "Sensor.h"

Sensor::Sensor(int sensorPin){
  pin=sensorPin;
}

State Sensor::getValue(){
  return convertToBool(analogRead(pin));
}

State Sensor::convertToBool(int value){
  if(value-10<42&&value+10>42){
    return WHITE;
  }else if(value-10<1020&&value+10>1020){
    return BLACK;
  }else{
    return NO_COLOR;
  }
}

