

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int CSpin = 5;

Max72xxPanel matrix = Max72xxPanel(CSpin,1,1);//1*1 matrix

void setup() {
  // put your setup code here, to run once:
  matrix.setIntensity(4);//brightness btw 0-15
  matrix.fillScreen(LOW);//x,y,color
  //matrix.drawChar(0,0,'a',HIGH,LOW,1);
  matrix.drawCircle(3,3,3,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //animatepixel();

}

void animatepixel()
{
  matrix.fillScreen(LOW);
  int i;
  for(i=0;i<8;i++)
  {
    matrix.drawPixel(i,3,HIGH);
    matrix.write();
    delay(20);
    matrix.drawPixel(i,3,LOW);
    matrix.write();
  }
  for(i=7;i>=0;i--)
  {
  matrix.drawPixel(i,3,HIGH);
  matrix.write();
  delay(20);
  matrix.drawPixel(i,3,LOW);
  matrix.write();
  }
}
