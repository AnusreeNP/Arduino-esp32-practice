#include <WiFi.h>

const char* ssid = "Anusree's iPhone";
const char* password = "aadhya12";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);
  Serial.println();

  Serial.print("connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  if(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.print("connected to ");
  Serial.println(ssid);

  delay(500);
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
