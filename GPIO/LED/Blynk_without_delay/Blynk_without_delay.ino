
 
//Declare the global variable
int num = 0;

void setup() {
  // put your setup code here, to run once:

  //Set the led as output pn
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Increment the variable up to a limit
   if(num++ < 1000000)
   {  
   
    //Glow the led till value reaches limit
    digitalWrite(LED_BUILTIN,HIGH);
   }
   if(num++ > 1000000)
   {
    //Once the value become greater than limit turn off led
    digitalWrite(LED_BUILTIN,LOW);
   }
   //turn off led up to some value after that reset the variable
   if(num == 10000000)
   {
    num = 0;
   }
}
