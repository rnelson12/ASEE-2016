byte leftMotor=11;
byte rightMotor=10;

void setup() {
  delay(5000);
  pinMode(leftMotor,OUTPUT);
  pinMode(rightMotor,OUTPUT);
  analogWrite(leftMotor,150);//75
  analogWrite(rightMotor,210);//105
}

void loop() {

}
