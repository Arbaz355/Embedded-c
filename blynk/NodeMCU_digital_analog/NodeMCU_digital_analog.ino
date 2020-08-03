#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "SKoS0pSCQYlktZoSNoHBQ0OKUTSohxre";

char ssid[] = "ESPServer_RAJ";
char pass[] = "RAJ@12345";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

