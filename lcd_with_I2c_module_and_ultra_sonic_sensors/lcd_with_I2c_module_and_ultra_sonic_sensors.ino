#include <LiquidCrystal.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>



int trig=13;
int echo=12;

void setup() {
 lcd.setBacklighPin(3, POSTIVE);
 lcd.setBacklight (HIGH);
 lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
 lcd.setCursor(0,1);
 lcd.print();
 lcd.print();
  delay(1000);
}
