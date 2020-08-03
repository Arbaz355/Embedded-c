#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
const int sensor=A0; 
float tempc;  // temperature in degree Celsius
float tempf;  // temperature in Fahreinheit 
float vout;  
void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
lcd.begin(16,2);  
  delay(500);
}
void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; 
tempf=(vout*1.8)+32;
lcd.setCursor(0,0);
lcd.print("in DegreeC= ");
lcd.print(tempc);
lcd.setCursor(0,1);
lcd.print("in Fahrenheit=");
lcd.print(tempf);
}
