#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bool status = bme.begin(0x77);
  Serial.println(status);
  

  if(!status)
  {
    Serial.println("Check wiring");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  printvalues();
  delay(1000);

}

void printvalues()
{
  Serial.print("Temperature:");
  Serial.print(bme.readTemperature());
  Serial.println("*c");

  Serial.print("Pressure:");
  Serial.print(bme.readPressure()/100.0F);
  Serial.println("hpa");

  Serial.print("Altitude:");
  Serial.print(bme.readAltitude(1013.25));
  Serial.println("m");

  Serial.print("Humidity:");
  Serial.print(bme.readHumidity());
  Serial.println("%");

  Serial.println();
  
}
