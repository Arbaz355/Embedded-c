const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
long distance;
int distance_filled;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration=pulseIn(echoPin,HIGH);
  
  distance =(0.0343*duration)/2;
  //Serial.println(distance);
 distance_filled = map(distance, 33, 5, 0, 100);
   Serial.println(distance_filled);
  delay(200);                                 
}
