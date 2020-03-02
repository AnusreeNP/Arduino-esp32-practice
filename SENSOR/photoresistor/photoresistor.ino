const byte gpio = 35;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //analogSetWidth(9);//set the resolution of adc to 9 bits,default 12 bits

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(gpio));
  delay(500);

}
