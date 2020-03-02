
#include <BluetoothSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

//create object for each library class
BluetoothSerial bt;
LiquidCrystal_I2C lcd(0x26,16,2);
Adafruit_BME280 bme;

//create counter for setting lcd and sensor
int lazy_counter = 0;
int row = 0;
int col = 0;

const byte max_col = 15;
const byte max_row = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bt.begin("ESP32");
  Serial.println("Device started..now pair with bluetooth");

  bme.begin(0x77);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ready to write");
  delay(20);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available())
  {
    if(col == 0 && row == 0)
      reset_lcd();

     lcd.setCursor(col,row);
     int ascii = bt.read();
     lcd.print(char(ascii));
     col++;

     if(col > max_col)
      { 
        col = 0;
        row++;
      }

      if(row > max_row)
         reset_lcd();

      if(ascii == 126)
        reset_lcd();

  }
  if(lazy_counter == 200)
  {
    sensor_value();
    lazy_counter = 0;
  }
  lazy_counter++;
  delay(50);
}

void reset_lcd()
{
  col = 0;
  row = 0;
  lcd.clear();
}

void sensor_value()
{
  const uint8_t temparr[]="Temperature: ";
  const uint8_t humarr[] = "Humidity: ";

  char temp[5];
  char hum[5];

  //convert float value in to array of characters to write one byte each into bt port
  dtostrf(bme.readTemperature(),4,2,temp);
  dtostrf(bme.readHumidity(),4,2,hum);

  bt.write(10); //new line
  bt.write(temparr,sizeof(temparr));
  for(int i = 0 ; i < sizeof(temp) ; i++)
      bt.write(temp[i]);

  bt.write(10);
  bt.write(humarr,sizeof(humarr));
  for(int i = 0;i < sizeof(hum);i++)
      bt.write(hum[i]);

  bt.write(10);

}
