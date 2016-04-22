byte leftMotor=11;
byte rightMotor=10;

void setup() {
  pinMode(leftMotor,OUTPUT);
  pinMode(rightMotor,OUTPUT);
}

void loop() {
  analogWrite(leftMotor,150);
  analogWrite(leftMotor,150);
}
