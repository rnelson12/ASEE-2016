#include <Servo.h>

Servo dropper;
Servo swing;

byte trigger=2;

void setup() {
  dropper.attach(3);
  swing.attach(4);
  pinMode(6,INPUT);
  Serial.begin(9600);

  swing.write(0);
  dropper.write(90);
  delay(2000);
  swing.write(90);
  delay(2000);
  dropper.write(180);
}

void loop() {
  boolean signal=digitalRead(trigger);
  Serial.println(signal);
  if(signal){
    dropper.write(90);
    
  }

  delay(20);
}
