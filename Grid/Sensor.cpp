#include "Sensor.h"

Sensor::Sensor(int sensorPin){
  pin=sensorPin;
}

State Sensor::getValue(){
  return convertToBool(analogRead(pin));
}

State Sensor::convertToBool(int value){
  if(value-10<WHITE&&value+10>WHITE){
    return WHITE;
  }else if(value-10<BLACK&&value+10>BLACK){
    return BLACK;
  }else{
    return NO_COLOR;
  }
}

