//https://www.bananarobotics.com/shop/How-to-use-the-HG7881-(L9110)-Dual-Channel-Motor-Driver-Module

//motor A is the right motor
const byte motorAPin=10;
const byte motorAPWM=11;
const byte motorBPin=6;
const byte motorBPWM=5;

const int BLACK=1;
const int WHITE=0;

const byte CONTINUE=0;
const byte ADJUST_LEFT=1;
const byte ADJUST_RIGHT=2;
const byte TURN_RIGHT=3;
const byte TURN_LEFT=4;
const byte NORMALIZE=5;
const byte ROUND_ABOUT=6;
byte turn=CONTINUE;

const byte left=2;
const byte right=3;

byte rightMotorPower=50;
byte leftMotorPower=50;

void setup() {
  pinMode(motorAPin,OUTPUT);
  pinMode(motorAPWM,OUTPUT);
  pinMode(motorBPin,OUTPUT);
  pinMode(motorBPWM,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftRead=digitalRead(left);
  int rightRead=digitalRead(right);

  if(leftRead==BLACK&&rightRead==WHITE){
      //adjust right
      turn=ADJUST_LEFT;
  }else if(rightRead==BLACK&&leftRead==WHITE){
      //adjust left
      turn=ADJUST_RIGHT;
  }else if(rightRead==WHITE&&leftRead==WHITE){
    turn=CONTINUE;
  }else if(rightRead==BLACK&&leftRead==BLACK){
    turn=CONTINUE;
  }

  drive(turn);
  delay(10);
}

void drive(byte turnType){
  switch(turnType){
    case ADJUST_LEFT:
    rightMotorPower=20;
    leftMotorPower=13;
      break;
    case ADJUST_RIGHT:
    leftMotorPower=25;
    rightMotorPower=10;
      break;
    case CONTINUE:
      rightMotorPower=20;
      leftMotorPower=25;
  }

  int mappedLeft=map(leftMotorPower,0,100,0,250);
  int mappedRight=map(rightMotorPower,0,100,0,250);

  digitalWrite(motorAPin,LOW);
  analogWrite(motorAPWM,mappedRight);

  digitalWrite(motorBPin,LOW);
  analogWrite(motorBPWM,mappedLeft);
}

