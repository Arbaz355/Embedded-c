#include <LiquidCrystal.h>
#include <DHT.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  delay(1000);
}

void loop() {
float humidity = dht.readHumidity ( ) ;  // Declaring h a variable and storing the humidity in it.
  float temp = dht.readTemperature ( ) ;
LiquidCrystal_I2C lcd(0x3F,16,2);
int pinDHT11 = 10;
SimpleDHT11 dht11;
const int DHT11_PIN= 10;
lcd.setCursor(0, 0);
lcd.print("Temp:       "); 
lcd.print(SimpleDHT.temperature,0);
lcd.print(char(223));
lcd.print("C");
lcd.setCursor(0, 1);
lcd.print("Humidity:   ");
lcd.print(DHT.humidity,0); lcd.print("  %");
delay(200);

}

