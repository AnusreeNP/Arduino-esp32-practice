const byte led_pin = 32;
bool led_state = false;

const byte interrupt_pin = 25;
volatile int interruptcounter = 0;
long noofinterrupts = 0;

long debouncing = 1000;
volatile long lastmicros = 0;

void IRAM_ATTR isr()
{
  if(long(micros()) - lastmicros >= debouncing * 1000)
  {
  interruptcounter++;
  lastmicros = micros();
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  pinMode(interrupt_pin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),isr,FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(interruptcounter > 0)
  {
    interruptcounter--;
    
    digitalWrite(led_pin,led_state);
    led_state = !led_state;

    noofinterrupts++;
    Serial.print("An interrupt has occured,Total:");
    Serial.println(noofinterrupts);
  }
 }
