
const byte dac = 25;
int value;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  //generate triangular wave
  /*for(value = 0; value < 255; value++)
    dacWrite(25,value);

  for(value = 255; value < -1; value--)
    dacWrite(25,value);*/

    //generate sine wave
    for(int deg = 0 ;deg < 360 ;deg++)
      dacWrite(25,int(128 + 80 * (sin(deg * PI/180))));

}
