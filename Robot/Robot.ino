#include<EEPROM.h>
//#include <EEPROMAnything.h>
#include <Drivetrain.h>
#include <Cog.h>
#incude <Arduino.h>
#include "Configure.h"
#include <Servo.h>

typedef unsigned char byte;
unsigned long elapsedTime = 0;
Cog *cog1;
Cog *cog2;
DriveTrain *base;
byte leftRings = 6;
byte rightRings = 6;
byte leftMotorPinForward;
byte leftMotorPinBackward;
byte rightMotorPinForward;
byte rightMotorPinBackward;
byte motorPower = 255;
byte wheelRadius = 10

void setup()
{

  /* add setup code here */
	Serial.begin(9600);

	cog1 = new Cog(leftRings);
	cog2 = new Cog(rightRings);
	base = new DriveTrain(leftMotorPinForward, leftMotorPinBackward, rightMotorPinForward, rightMotorPinBackward, motorPower, wheelRadius);
}

void loop()
{

  /* add main program code here */
	elapsedTime = millis();
}
