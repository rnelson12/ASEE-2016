const byte pin1=2;
const byte pin2=3;

void setup() {
  pinMode(pin1,INPUT);
  pinMode(pin2,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("pin 1: ");
  Serial.println(analogRead(pin1));
  delay(1000);
}
