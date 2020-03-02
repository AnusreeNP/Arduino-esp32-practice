// https://github.com/makuna/Rtc
//wiki-https://datasheetsmaxmintegrated.com/en/ds/DS3231.pdf

//for normal hardware wire
#include <Wire.h>
#include <RtcDS1307.h>
RtcDS1307<TwoWire>Rtc(Wire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("compiled");
  Serial.println(__DATE__);
  Serial.println(__TIME__);
  
  Rtc.Begin();

  RtcDateTime compiled = RtcDateTime(__DATE__,__TIME__);
  printDateTime(compiled);

  if(!Rtc.IsDateTimeValid())
  {
    if(Rtc.LastError()!=0)
    {
      Serial.print("Rtc communication error:");
      Serial.println(Rtc.LastError());
    }else
    {
      //2 causes
      //1.device not started
      //2.battery failure
      Serial.println("Rtc lost confidence");
      Rtc.SetDateTime(compiled);
    }
  }

  if(!Rtc.GetIsRunning())
    {
      Serial.println("Rtc is not actively running");
      Rtc.SetIsRunning(true);
    }

    RtcDateTime now = Rtc.GetDateTime();
    if(now < compiled)
    {
      Serial.println("Rtc is older than compile time");
      Rtc.SetDateTime(compiled);
    }
    else if(now > compiled)
    {
      Serial.println("Rtc is newer than compile time");
    }else if(now == compiled)
    {
      Serial.println("rtc and compile time remains same");
    }
    
    Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Serial.println();
  delay(10000);

}
#define count(a) sizeof(a)/sizeof(a[0])

void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];
  snprintf_P(datestring,count(datestring),PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
  dt.Month(),
  dt.Day(),
  dt.Year(),
  dt.Hour(),
  dt.Minute(),
  dt.Second());

  Serial.println(datestring);
  
}
