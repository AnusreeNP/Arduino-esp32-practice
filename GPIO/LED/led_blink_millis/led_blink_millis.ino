
const int led = 33;
int led_state = LOW;
unsigned long previousmillis = 0; //last updated time of led state
const long interval = 1000;//interval at which led blink

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentmillis = millis();
  if((currentmillis - previousmillis) >= interval)
  {
    previousmillis = currentmillis;

    if(led_state == LOW)
    {
      led_state = HIGH;
    }
    else
    {
      led_state = LOW;
    }

    digitalWrite(led,led_state);
  }

}
