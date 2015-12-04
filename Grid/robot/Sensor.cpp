#include "Sensor.h"

Sensor::Sensor(int sensorPin){
  pin=sensorPin;
}

State Sensor::getValue(){
  return convertToBool(analogRead(pin));
}

State Sensor::convertToBool(int value){
  if(value-10<WHITE_VALUE&&value+10>WHITE_VALUE){
    return WHITE;
  }else if(value-10<BLACK_VALUE&&value+10>BLACK_VALUE){
    return BLACK;
  }else{
    return NO_COLOR;
  }
}

