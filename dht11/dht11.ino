
#include <DHT.h>

//Constants
#define DHT11_PIN D2     // DHT 22  (AM2302) - what pin we're connected to

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int chk = dht.read11(DHT11_PIN);
    //Read data and store it to variables hum and temp
    hum = dht.humidity;
    temp= dht.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); //Delay 2 sec.
}
