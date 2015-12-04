#include <Servo.h>
#include "DriveTrain.h"
#include "Cog.h"
#include "Configure.h"
#include "Grid.h"
#include "Sensor.h"

unsigned long elapsedTime = 0;
Cog leftCog(LEFT_RINGS,LEFT_COG_PIN);
Cog rightCog(RIGHT_RINGS,RIGHT_WHEEL_PIN);
DriveTrain base(LEFT_MOTOR_POWER, RIGHT_MOTOR_POWER);
Grid grid;
byte power=50;
State path[]={TURN_RIGHT,FORWARD,TURN_RIGHT,TURN_RIGHT,TURN_LEFT,FORWARD};
byte i=0;

void setup(){

  pinMode(START_BUTTON,INPUT);
  Serial.begin(9600);
  grid.begin();
  log("Setup and ready to go");
  log("Waiting for switch");
  while(digitalRead(START_BUTTON)==LOW){
    //do nothing while waiting for start button
  }
}

void loop()
{
  //first things first, we should probably check the line and adjust?
  //or maybe check line then see if we need to turn then adjust?
  State lineCheck=grid.checkLine();
  State turnStatus=grid.calculateTurn();
  if(turnStatus!=FORWARD||turnStatus!=CONTINUE){
    //needs to turn also check to see if it is time to drop a ring
    base.drive(power,turnStatus);
  }else{
    if(lineCheck==ADJUST_LEFT){
      
    }else if(lineCheck==ADJUST_RIGHT){
      
    }else if(RETURN_TO_NORMAL){
      //if we add 10% to the motors we have to take it off here...or not...
    }
  }
  elapsedTime = millis();
}

void log(String message){
  if(DEBUG){
    Serial.println(message);
  }
}

