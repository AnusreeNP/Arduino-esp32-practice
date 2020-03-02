
const byte led_pin = 32;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(touchRead(13));
  if(touchRead(13) < 20)
    digitalWrite(led_pin,HIGH);
  else
    digitalWrite(led_pin,LOW);
  delay(500);
}
