#include <Wire.h>
#include "sensorbar.h"

SensorBar bar(0x44);
byte kp=1;
byte ki=1;
byte kd=1;

int error=0;
int errSum=0;
int lastError=0;
int lastTime=0;
int TARGET=24;
int dErr=0;

void setup() {
  delay(5000);
  bar.setBarStrobe();
  bar.clearInvertBits();
  bar.begin();
  pinMode(,OUTPUT);
  pinMode(,OUTPUT);
}

void loop() {
  uint8_t raw=bar.getPosition();

    unsigned long now=millis();
    unsigned long timeChange=(now-lastTime);

    error=TARGET-raw;
    errSum+=(error*timeChange);
    dErr=(error-lastError)/timeChange;

    lastError=error;
    lastTime=now;

    //TODO figure out how to write result to motors
    int result=kp*error+ki*errSum+kd*dErr;
    
}
