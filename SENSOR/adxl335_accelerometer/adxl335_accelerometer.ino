
const byte x = 34;
const byte y = 39;
const byte z = 36;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(x));
  Serial.print("\t");

  Serial.print(analogRead(y));
  Serial.print("\t");

  Serial.print(analogRead(z));
  Serial.print("\n");

  delay(5000);

  

}
