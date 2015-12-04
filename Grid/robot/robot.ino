#include <Servo.h>
#include "DriveTrain.h"
#include "Cog.h"
#include "Configure.h"

unsigned long elapsedTime = 0;
byte leftRings = LEFT_RINGS;
byte rightRings = RIGHT_RINGS;
//byte motorPower = MOTOR_POWER;
byte wheelRadius = WHEEL_RADIUS;
Cog leftCog(LEFT_RINGS,LEFT_COG_PIN);
Cog rightCog(RIGHT_RINGS,RIGHT_WHEEL_PIN);
DriveTrain base(LEFT_MOTOR_POWER, RIGHT_MOTOR_POWER);
byte leftMotorPinForward;
byte leftMotorPinBackward;
byte rightMotorPinForward;
byte rightMotorPinBackward;

void setup(){

  /* add setup code here */
  Serial.begin(9600);

  //cog1 = new Cog(leftRings);
  //cog2 = new Cog(rightRings);
  //base = new DriveTrain(motorPower, wheelRadius);
}

void loop()
{

  /* add main program code here */
  elapsedTime = millis();
}
