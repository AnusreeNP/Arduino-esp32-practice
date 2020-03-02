
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

//generate uuid for service,caharacteristics-https://www.uuidgenerator.net

#define SERVICE_UUID  "d56cc823-92dc-4680-b939-76b70b9301f3"
#define CHAR1_UUID  "d4ed6cc9-4bc2-40ff-8dc8-0d114db4039e"
#define CHAR2_UUID  "de97b833-79e3-4c10-b3a7-ab6c6d8fe3dd"

class MyCallback1:public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pChar)
  {
    std::string value = pChar->getValue();
    if(value.length() > 0)
    {
      Serial.print("New value of char1 : ");
      for(int i = 0 ;i < value.length(); i++)
        Serial.print(value[i]);
        Serial.println();
    }
  }
};

class MyCallback2:public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pChar)
  {
    std::string value = pChar->getValue();
    if(value.length() > 0)
    {
      Serial.print("New value of char2 : ");
      for(int i = 0 ;i < value.length(); i++)
        Serial.print(value[i]);
        Serial.println();
    }
  }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BLEDevice::init("ESP32");

  //create ble server
  BLEServer *pServer = BLEDevice::createServer();

  //create ble service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  //create characteristics
  BLECharacteristic *pChar1 = pService->createCharacteristic(CHAR1_UUID,BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  BLECharacteristic *pChar2 = pService->createCharacteristic(CHAR2_UUID,BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

  //server perform action on client requests
  pChar1->setCallbacks(new MyCallback1());
  pChar1->setValue("Hello World char1");
  
  pChar2->setCallbacks(new MyCallback2());
  pChar2->setValue("Hello World char2");

  pService->start();
  BLEAdvertising *pAdv = pServer->getAdvertising();
  pAdv->start();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);

}
