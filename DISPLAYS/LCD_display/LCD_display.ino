


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
 
}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.setCursor(0,0);
  lcd.print("Hello World");

  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Second Row");

  delay(2000);
  lcd.setCursor(12,1);
  lcd.print("4");

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Back light ON");
  //lcd.backlight();

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Back light OFF");
  lcd.noBacklight();

  delay(2000);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("scroll");

  for(int i=0;i<5;i++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }
  
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Demo finished");
  delay(3000);
  
  lcd.clear();

  delay(2000);


}
