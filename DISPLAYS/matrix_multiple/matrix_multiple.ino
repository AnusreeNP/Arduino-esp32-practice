#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int CSpin = 5;

Max72xxPanel matrix = Max72xxPanel(CSpin,1,4);

void setup() {
  // put your setup code here, to run once:
  matrix.setIntensity(2);
  matrix.fillScreen(LOW);
  matrix.setPosition(0,0,0);
  matrix.setPosition(1,1,0);
  matrix.setPosition(2,2,0);
  matrix.setPosition(3,3,0);

}

void loop() {
  // put your main code here, to run repeatedly:
  //animatepixcel();
  animateletter();

}

void animatepixcel()
{
  int i;
  for(i=0;i<32;i++)
  {
    matrix.drawPixel(4,i,HIGH);
    matrix.write();
    delay(60);
    matrix.drawPixel(4,i,LOW);
    matrix.write();
  }

  for(i=31;i>-1;i--)
  {
    matrix.drawPixel(4,i,HIGH);
    matrix.write();
    delay(60);
    matrix.drawPixel(4,i,LOW);
    matrix.write();   
  }
}

void animateletter()
{
  int i;
  for(i=0;i<32;i++)
  {
    matrix.drawChar(0,i,'A',HIGH,LOW,1);
    matrix.write();
    delay(20);
    matrix.drawChar(0,i,'A',LOW,LOW,1);
    matrix.write();
  }

  for(i=31;i>-1;i--)
  {
    matrix.drawChar(0,i,'A',HIGH,LOW,1);
    matrix.write();
    delay(20);
    matrix.drawChar(0,i,'A',LOW,LOW,1);
    matrix.write();
  }
}
