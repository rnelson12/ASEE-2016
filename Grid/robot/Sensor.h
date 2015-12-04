#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "Types.h"
#include "Configure.h"

class Sensor{
  public:
    Sensor(int pin);
    State getValue();
  private:
  State convertToBool(int value);
  boolean value;
  int pin;
};

#endif
