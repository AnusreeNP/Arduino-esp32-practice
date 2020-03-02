#include <WiFiClientSecure.h>

const char* ssid = "Anusree's iPhone";
const char* password = "aadhya12";

const char* host = "https://esp32-anu.s3.ap-south-1.amazonaws.com";
String url = "/led_control.txt";

#define LED_BUILTIN 2

const char* test_root_ca =
"-----BEGIN CERTIFICATE-----\n"
"MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ\n"
"RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD\n"
"VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX\n"
"DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y\n"
"ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy\n"
"VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr\n"
"mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr\n"
"IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK\n"
"mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu\n"
"XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy\n"
"dc93Uk3zyZAsuT3lySNTPx8kmCFcB5kpvcY67Oduhjprl3RjM71oGDHweI12v/ye\n"
"jl0qhqdNkNwnGjkCAwEAAaNFMEMwHQYDVR0OBBYEFOWdWTCCR1jMrPoIVDaGezq1\n"
"BE3wMBIGA1UdEwEB/wQIMAYBAf8CAQMwDgYDVR0PAQH/BAQDAgEGMA0GCSqGSIb3\n"
"DQEBBQUAA4IBAQCFDF2O5G9RaEIFoN27TyclhAO992T9Ldcw46QQF+vaKSm2eT92\n"
"9hkTI7gQCvlYpNRhcL0EYWoSihfVCr3FvDB81ukMJY2GQE/szKN+OMY3EU/t3Wgx\n"
"jkzSswF07r51XgdIGn9w/xZchMB5hbgF/X++ZRGjD8ACtPhSNzkE1akxehi/oCr0\n"
"Epn3o0WC4zxe9Z2etciefC7IpJ5OCBRLbf1wbWsaY71k5h+3zvDyny67G7fyUIhz\n"
"ksLi4xaNmjICq44Y3ekQEe5+NauQrz4wlHrQMz2nZQ/1/I6eYs9HRCwBXbsdtTLS\n"
"R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp\n"
"-----END CERTIFICATE-----\n";
                                 
                              

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
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

  WiFiClientSecure client;
  client.setCACert(test_root_ca);
  const int httpsPort = 443;

  if(!client.connect(host,httpsPort))
  {
    Serial.println("failed to connect client");
    //return;
  }else
  {
  Serial.println("requesting url..");
  Serial.println(url);

  //sending https request to server
  client.println(String("GET https//")+host+url+" HTTP/1.0");
  client.println(String("Host: ")+host);
  client.println("connection:close");
  client.println();

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
 /* while(client.connected())
  {
    String line = client.readStringUntil('\n');
    if(line == "\r")
    {
      Serial.println("Headers recieved");
      break;
    }
  }*/

  //if incoming bytes are available
  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
    
    if(line == "ON")
      digitalWrite(LED_BUILTIN,HIGH);
    if(line == "OFF")
      digitalWrite(LED_BUILTIN,LOW);
  }

  Serial.println();
  Serial.println("closing connection");
  //client.stop();
  }
  //delay(5000);
}
