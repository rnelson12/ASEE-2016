double kp=.5;
double ki=.5;
double kd=.5;

byte left=6;
byte right=7;

int RBaseSpeed=105;
int LBaseSpeed=105;
byte RMotor=10;
byte LMotor=11;

double error=0;
double errSum=0;
double lastError=0;
int lastTime=0;
int TARGET=0;
double dErr=0;

void setup() {
  pinMode(RMotor,OUTPUT);
  pinMode(LMotor,OUTPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  Serial.begin(9600);

  delay(3000);
  analogWrite(RMotor,RBaseSpeed);
  analogWrite(LMotor,LBaseSpeed);
}

void loop() {

  /*if(l){
    analogWrite(RMotor,RBaseSpeed+30);
    analogWrite(RMotor,LBaseSpeed);
  }else if(r){
    analogWrite(RMotor,RBaseSpeed);
    analogWrite(RMotor,LBaseSpeed+30);
  }

  delayMicroseconds(10);*/
    /*unsigned long now=millis();
    unsigned long timeChange=(now-lastTime);

    error=TARGET-raw;
    errSum+=(error*timeChange);
    dErr=(error-lastError)/timeChange;

    lastError=error;
    lastTime=now;

    //TODO figure out how to write result to motors
    double result=kp*error+ki*errSum+kd*dErr;

    int RMotorSpeed=RBaseSpeed+result;
    int LMotorSpeed=LBaseSpeed-result;

    if(RMotorSpeed>130){
      RMotorSpeed=130;
    }

    if(RMotorSpeed<50){
      RMotorSpeed=50;
    }

    if(LMotorSpeed>100){
      LMotorSpeed=100;
    }

    if(LMotorSpeed<25){
      LMotorSpeed=25;
    }
    
    analogWrite(RMotor,RMotorSpeed);
    analogWrite(LMotor,LMotorSpeed);

    delayMicroseconds(10);*/
}
