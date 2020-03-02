
int speed1 = 21;
int direction1 = 2;

bool direction = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(direction1,OUTPUT);

  ledcAttachPin(speed1,0);
  ledcSetup(0,4000,8);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(direction1,direction);

  ledcWrite(0,100);
  delay(1000);
  ledcWrite(0,155);
  delay(1000);
  ledcWrite(0,255);
  delay(1000);

  direction = !direction;

  ledcWrite(0,0);

}
