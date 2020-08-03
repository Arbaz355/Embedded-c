#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
 #define DHTPIN 2      // Selecting the pin at which we have connected DHT11
 #define DHTTYPE DHT11 // Selecting the type of DHT sensors
 DHT dht ( DHTPIN, DHTTYPE );

void setup() {
 // put your setup code here, to run once:
Serial.begin ( 9600 ) ;
dht.begin (  ) ;   
lcd.begin();
lcd.backlight();
}

void loop() 
{
 // put your main code here, to run repeatedly:
float humidity = dht.readHumidity ( ) ;  // Declaring h a variable and storing the humidity in it.
  float temp = dht.readTemperature ( ) ;
LiquidCrystal_I2C lcd(0x3F,16,2);
int pinDHT11 = 4;
SimpleDHT11 dht11;
const int DHT11_PIN= 4;
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
