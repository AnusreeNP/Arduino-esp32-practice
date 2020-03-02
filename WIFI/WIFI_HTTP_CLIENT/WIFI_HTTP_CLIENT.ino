#include <WiFi.h>

const char* ssid = "Anusree's iPhone";
const char* password = "aadhya12";

const char* host = "esp32-anu.s3.ap-south-1.amazonaws.com";
String url = "/esp32.txt";

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
  delay(5000);
  Serial.print("connecting to:");
  Serial.println(host);

  WiFiClient client;
  const int httpPort = 80;

  while(!client.connect(host,httpPort))
  {
    Serial.println("failed to connect client");
    return;
  }

  Serial.println("requesting url..");
  Serial.println(url);

  //sending http request to server
  client.print(String("GET ")+url+" HTTP/1.1\r\n"
                       +"Host:"+host+"\r\n"+
                       "connection:close\r\n\r\n");

  unsigned long timeout = millis();
  while(client.available()==0)
  {
    if(millis()-timeout>5000)
    {
      Serial.println("client timed out");
      client.stop();
      return;
    }
  }

  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
 }
