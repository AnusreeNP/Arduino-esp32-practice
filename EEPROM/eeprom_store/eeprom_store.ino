#include "EEPROM.h"

int addr = 0; //eeprom first address
#define EEPROM_SIZE  1 //only 1 byte is used to store

const int led_pin = 32;
const int interrupt_pin = 25;

bool led_state = false;
volatile int interruptcounter = 0;
int no_of_interrupts = 0;

void IRAM_ATTR handler()
{
  interruptcounter++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  EEPROM.begin(EEPROM_SIZE);

  pinMode(led_pin,OUTPUT);
  pinMode(interrupt_pin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),handler,FALLING);

  led_state = EEPROM.readBool(addr);
  Serial.print("EEPROM contains:");
  Serial.println(led_state);
  digitalWrite(led_pin,led_state);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(interruptcounter > 0)
  {
    interruptcounter--;
    led_state = !led_state;
    digitalWrite(led_pin,led_state);

    EEPROM.writeBool(addr,led_state);
    EEPROM.commit();
    Serial.print("EEPROM current value :");
    Serial.println(EEPROM.readBool(addr));

    no_of_interrupts++;
    Serial.print("An interrupt has occured:");
    Serial.println(no_of_interrupts);
    
  }

}
