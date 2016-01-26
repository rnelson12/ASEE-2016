#include<EEPROM.h>
//#include <EEPROMAnything.h>
#include "DriveTrain.h"
#include "Cog.h"
#include <Arduino.h>
#include "Configure.h"
#include <Servo.h>

//typedef unsigned char byte;
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
byte wheelRadius = 10;

void setup()
{

  /* add setup code here */
	Serial.begin(9600);

	cog1 = new Cog(leftRings,RIGHT_COG_PIN);
	cog2 = new Cog(rightRings,LEFT_COG_PIN);
	base = new DriveTrain(RIGHT_MOTOR_POWER,LEFT_MOTOR_POWER);
}

void loop()
{

  /* add main program code here */
	elapsedTime = millis();
}
