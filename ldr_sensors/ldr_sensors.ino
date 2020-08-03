int sensorPin = A0;   
int sensorValue = 0;  

void setup() {
  pinMode(2, OUTPUT); 
}

void loop() {

  sensorValue = analogRead(sensorPin);    
  Serial.print(sensorValue); 
  
  if(sensorValue < 200) 
  digitalWrite(2,HIGH); 
  
  else 
  digitalWrite(2,LOW); 
  
  delay(100);                  
}
