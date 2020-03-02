
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

unsigned long timer = 0;
long pre_millis = 0;
long interval = 1000;

#define noofsec(_time_) (_time_)%60
#define noofmin(_time_) (_time_)%3600

Adafruit_7segment clockdisplay = Adafruit_7segment();//created object of adafruit 7 seg class

bool blinkcolon = false;

void setup() {
  // put your setup code here, to run once:
  clockdisplay.begin(0x70);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - pre_millis > interval)
  {
    pre_millis = millis();
    timer++;
    blinkcolon = !blinkcolon;
  }
  printTimer();
}

void printTimer()
{
  int min = noofmin(timer);
  int sec = noofsec(timer);

  clockdisplay.print(min*100+sec,DEC);

  if(min < 10)
    clockdisplay.writeDigitNum(0,0);
  if(min < 1)
    clockdisplay.writeDigitNum(1,0);
   if(sec < 10)
    clockdisplay.writeDigitNum(3,0);

   clockdisplay.drawcolon(blinkcolon);
   clockdisplay.writeDisplay();
    
}
