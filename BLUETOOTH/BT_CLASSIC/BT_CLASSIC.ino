#include <BluetoothSerial.h>

BluetoothSerial bt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bt.begin("Esp32_test");
  Serial.println("Device started..now pair with bluetooth");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    bt.write(Serial.read());
  }

  if(bt.available())
  {
    Serial.write(bt.read());
  }
  delay(20);
}
