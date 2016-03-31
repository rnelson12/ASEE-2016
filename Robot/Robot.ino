#include<EEPROM.h>
#include "DriveTrain.h"
#include "Cog.h"
#include <Arduino.h>
#include "Configure.h"
#include <Servo.h>
#include <Wire.h>

unsigned long elapsedTime = 0;
Cog *cog1;
Cog *cog2;
DriveTrain *base;
const byte moveSize=8;
State moves[8];
State RIGHT_MOVES[]={TURN_LEFT,TURN_LEFT,FORWARD,TURN_LEFT,TURN_LEFT,TURN_LEFT,TURN_RIGHT,FORWARD,TURN_RIGHT};
State LEFT_MOVES[]={TURN_LEFT,TURN_RIGHT,FORWARD,TURN_RIGHT,TURN_RIGHT,TURN_RIGHT,TURN_LEFT,FORWARD,TURN_LEFT};

void setup()
{

  /* add setup code here */
	Serial.begin(9600);

	cog1 = new Cog(LEFT_RINGS,RIGHT_COG_PIN);
	cog2 = new Cog(RIGHT_RINGS,LEFT_COG_PIN);
	base = new DriveTrain(RIGHT_MOTOR_POWER,LEFT_MOTOR_POWER);

  if(!ROBOT_DIRECTION){
    memcpy( RIGHT_MOVES, moves, moveSize);
  }else{
    memcpy( LEFT_MOVES, moves, moveSize);
  }

  if(DEBUG){
    debug();
  }
  log("Starting normal startup");
}

void loop()
{

  //check the line using a method from the grid.
  //then adjust using the adjustment method in drivetrain
  //then turn using the drive method in drivetrain

  /*State upcomingTurn=base->sensors->calculateTurn();
  if(upcommingTurn==moves[i]){
    base->drive(MAX_POWER,moves[i]);
    i++;
  }
	elapsedTime = millis();*/
}

void debug(){
  boolean runNormal=false;
  if(DEBUG){
    log("welcome to debugging!");
    log("TURN OFF DEBUGING BEFORE GOING TO COMPETE OR THE ROBOT WILL SIT AND WAIT FOR YOUR SORRY ASS TO PRESS A KEY");
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
      log("Debugging is over. Change the DEBUG value to 0 to continue.");
    }
  }
}

void log(String message){
  if(DEBUG){
    Serial.println(message);
  }
}
