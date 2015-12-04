#include <Servo.h>
#include "DriveTrain.h"
#include "Cog.h"
#include "Configure.h"
#include "Grid.h"
#include "Types.h"

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

  debug();
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


void debug(){
  boolean runNormal=false;
  if(DEBUG){
    log("welcome to debugging!");
    log("TURN OFF DEBUGING BEFORE GOING TO COMPETE OR THE ROBOT WILL SIT AND WAIT FOR YOU TO PRESS A KEY");
    log("press c to debug the cogs.");
    log("press m to debug the motors");
    log("press r to run with verbous output");
    log("press s to debug the line following sensor and turn sensors");
    log("press u to debug the color sensors");
    log("press q to see this robot give a shit");

    while(Serial.available()==0){
      //do nothing but wait
    }
    char c=Serial.read();
    switch(c){
      case 'c':
        log("you have selected cogs! :D");
        log("If this is not what you wanted, then shut up and start over");
        delay(3000);
        break;
      case 'm':
        log("you have selected motors! :D");
        log("If this is not what you wanted, then shut up and start over");
        delay(3000);
        break;
      case 'r':
        log("you have selected normal run with verbous output! :D");
        log("If this is not what you wanted, then shut up and start over");
        delay(3000);
        log("The normal programming will begin in about 5 seconds so get ready.");
        runNormal=true;
        delay(5000);
        break;
      case 's':
        log("you have selected line following sensors! :D");
        log("If this is not what you wanted, then shut up and start over");
        delay(3000);
        break;
      case 'u':
        log("you have selected color sensors! :D");
        log("If this is not what you wanted, then shut up and start over");
        delay(3000);
        break;
      case 'q':
        log("like I give a fuck");
        delay(3000);
        break;
    };
    while(!runNormal){
      log("Debugging is over. Change the debug value to 0 to continue.");
    }
  }
}

