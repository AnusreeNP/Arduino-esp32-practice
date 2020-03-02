

#define COUNT 11  //0123456789.
const byte symbols[COUNT] =
{
  B00111111, //0
  B00000110, //1
  B01011011, //2
  B01001111, //3
  B01100110, //4
  B01101101, //5
  B01111101, //6
  B00000111, //7
  B01111111, //8
  B01101111, //9
  B10000000, //.
};

const byte pins[] = {33,32,19,18,5,27,14,4};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0 ;i < 8 ;i++)
  {
    pinMode(pins[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0 ;i<COUNT ;i++)
  {
    writeleds(symbols[i]);
    delay(2000);
  }

}

void writeleds(const byte symbols)
{
  for(int i = 0 ;i < 8; i++)
  {
    digitalWrite(pins[i],bitRead(symbols,i));
  }

}
