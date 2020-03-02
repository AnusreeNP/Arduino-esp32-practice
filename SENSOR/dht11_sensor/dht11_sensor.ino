
#include "SimpleDHT.h"

int dhtpin = 32;//io pin where data pin of sensor is connected
SimpleDHT11 dht11(dhtpin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = 0;
  float humidity = 0;

  int err = SimpleDHTErrSuccess;
  if((err = dht11.read2(&temp,&humidity,NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read dht11 failed,err =");
    Serial.println(err);
    delay(2000);
    return;
  }

  Serial.println("sample ok");
  Serial.print((float)temp);
  Serial.println("*c");
  Serial.print((float)humidity);
  Serial.println("RH%");

  delay(2500);

}
