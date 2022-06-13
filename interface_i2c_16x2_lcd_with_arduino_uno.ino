#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int sensorValue = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{

	lcd.begin();


	lcd.backlight();
	lcd.clear();
	lcd.setCursor(4,0);
	
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("  Proba 1.0");
    

  sensorValue = analogRead(A0);
  Serial.println(sensorValue);

lcd.setCursor(0,1);
lcd.print(sensorValue);
lcd.setCursor(4,1);
lcd.print("Sensor Value");

  for (int positionCounter = 0; positionCounter < analogRead(A0); positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < analogRead(A0); positionCounter--) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }

  delay(500);
  lcd.clear();
}
