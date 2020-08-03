#include <dht11.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D2,D3,D5,D6);
#define DHT11PIN D4

dht11 DHT11;

void setup()
{
  Serial.begin(9600);
 lcd.begin(16,2);
    lcd.setCursor(0,0);
}

void loop()
{
   float hum=DHT11.humidity;
     float temp=DHT11.temperature;
  Serial.println();

  int chk = DHT11.read(DHT11PIN);
  lcd.print("TEMP");

lcd.print(temp);

      lcd.setCursor(0,0);
lcd.print("HUM");
lcd.print(hum);
  Serial.print("Humidity (%): ");
  Serial.println(hum);

  Serial.print("Temperature (C): ");
  Serial.println(temp);

  delay(2000);

}
