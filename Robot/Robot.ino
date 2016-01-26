#include<EEPROM.h>
//#include "EEPROMAnything.h"
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
