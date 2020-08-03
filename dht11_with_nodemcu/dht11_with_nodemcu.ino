#include <DHT.h>
#define dht11_pin D5
DHT dht;
void setup() {
  // put your setup code here, to run once:
pinMode(D1,INPUT);
Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
int k= dht.read11(dht11_pin);
float temp= dht.temprature;
float hum= dht.humidity;
Serial.println(temp);
Serial.println(hum);
delay(500);
}
