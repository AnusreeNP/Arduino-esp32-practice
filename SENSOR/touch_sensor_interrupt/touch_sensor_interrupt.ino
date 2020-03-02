const byte led_pin = 32;
int threshold = 20;

bool touch4detected = false;

void gottouch()
{
  touch4detected = true;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  touchAttachInterrupt(T4,gottouch,threshold);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(touch4detected)
  {
    digitalWrite(led_pin,HIGH);
    Serial.println("Touch detected");
    touch4detected = false;
    delay(500);
    digitalWrite(led_pin,LOW);
  }

}
