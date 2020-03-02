const int led = 33;//pwm pin where led is connected
int brightness = 0;
int fade = 5;

void setup() {
  // put your setup code here, to run once:
  ledcAttachPin(led,0);//assign pin to channel
  ledcSetup(0,12000,8);//channel,frequency,resolution
}

void loop() {
  // put your main code here, to run repeatedly:
  ledcWrite(0,brightness);
  brightness = brightness + fade;
  if(brightness <= 0 || brightness >= 255)
  {
    fade = -fade;
  }
  delay(30);
 }
