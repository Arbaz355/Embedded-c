#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
 

char auth[] = "3GrJ4CuZxxSCw18k-zIT1SQKbVfQ1qL_";
 
char ssid[] = "Akhter";
char pass[] = "Akhter@1234.";
 
#define DHTPIN D2
 

#define DHTTYPE DHT11     // DHT 11

 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
const int Led1=D6;
const int Led2=D7;
const int Led3=D8;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int distance_filled; 
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Serial.print("Temp = ");
  Serial.print(t);
  Serial.print(" Humi = ");
  Serial.println(h);
}
void ultSensor()
{
   long distance;
int distance_filled;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration=pulseIn(echoPin,HIGH);
  distance =(0.0343*duration)/2;
  distance_filled = map(distance, 21, 3, 0, 100);
  Serial.println(distance_filled);
  Serial.println(distance);
  Blynk.virtualWrite(V3, distance_filled);
  //CODE FOR LED 
  if(distance_filled==0)
  {
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
  }
   else if(distance_filled<=50)
  {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);
  }
   else
  {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
    }
}
 
void setup()
{
  
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);

 
  dht.begin();
 
  timer.setInterval(1000L, sendSensor);
  timer.setInterval(1000L, ultSensor);
    pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
   pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
