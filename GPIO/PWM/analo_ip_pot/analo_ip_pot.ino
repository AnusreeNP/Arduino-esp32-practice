const byte pot = 15;
const byte led = 32; //pwm pin were led s attached

void setup() {
  // put your setup code here, to run once:
  ledcAttachPin(led,0);//assign led to a channel
  ledcSetup(0,4000,12);

}

void loop() {
  // put your main code here, to run repeatedly:
  ledcWrite(0,analogRead(pot));//set led brightness

}
