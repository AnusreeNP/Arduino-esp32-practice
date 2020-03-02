const byte led = 32;
const byte button = 35;
int button_state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button);
  
  //if button pressed
  if(button_state == HIGH)
    digitalWrite(led,HIGH);
   else
    digitalWrite(led,LOW);
}
