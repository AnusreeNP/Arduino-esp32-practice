
#include <Arduino.h>
#include <uSevenSegmentLib.h>
#include <uTimerLib.h>

int pins[8] = {33,32,19,18,5,27,14,4};
int mux[1] = {15};

uSevenSegmentLib sevenSegments(1,pins,mux);

int i = 0;



void setup() {
  // put your setup code here, to run once:
  sevenSegments.set(i);
  sevenSegments.attachInterrupt();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  i = i + 1;
  sevenSegments.set(i);
}
