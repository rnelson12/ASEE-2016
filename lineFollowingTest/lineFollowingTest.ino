#include <Wire.h>
#include "sensorbar.h"

SensorBar bar(0x3E);
double kp=1;
double ki=0;
double kd=0;

int LBaseSpeed=65;//105;
int RBaseSpeed=45;//75;
byte RReverse=10;
byte LReverse=12;
byte RMotor=9;
byte LMotor=11;

void setup() {
  pinMode(RMotor,OUTPUT);
  pinMode(LMotor,OUTPUT);
  pinMode(RReverse,OUTPUT);
  pinMode(LReverse,OUTPUT);
  Serial.begin(9600);
  bar.setBarStrobe();
  bar.clearInvertBits();
  if(bar.begin()){
    Serial.print("ready");
  }else{
    Serial.print("not ready");
  }
  delay(2000);
}
byte i = 0;
void loop() {
  uint8_t raw=bar.getRaw();

  /*for(int i=0;i<7;i++){
    Serial.print(bitRead(raw,i));
  }
  Serial.println();
  delay(500);
  analogWrite(RMotor,i);
  analogWrite(RMotor,0);
  delay(100);
  i +=1;
  Serial.println(i);*/
  if(bitRead(raw,2)||bitRead(raw,1)||bitRead(raw,0)){
    //turn right
    analogWrite(RMotor,RBaseSpeed);
    analogWrite(LMotor,LBaseSpeed+30);
    //Serial.println("Right");
  }else if(bitRead(raw,5)||bitRead(raw,6)||bitRead(raw,7)){
    //turn left
    analogWrite(RMotor,RBaseSpeed+30);
    analogWrite(LMotor,LBaseSpeed);
    //Serial.println("Left");
  }else if(bitRead(raw,3)||bitRead(raw,4)){
    analogWrite(RMotor,RBaseSpeed);
    analogWrite(LMotor,LBaseSpeed);
  }

    delayMicroseconds(10000);
}
