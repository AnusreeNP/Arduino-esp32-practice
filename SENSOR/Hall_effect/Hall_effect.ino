
int value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = hallRead(); //read the value from halleffect sensor
  Serial.println(value);
 }
