#include <Servo.h>


const byte servopin = 12;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servo.attach(servopin);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i=0;i<=180;i++)
  {
    servo.write(i);
    Serial.println(i);
    delay(20);
  }

  for(i=180;i>=0;i--)
  {
    servo.write(i);
    Serial.println(i);
    delay(20);  
  }
}
