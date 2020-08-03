int trig=A0;
int echo=A1;
int motorPin1= 3;
int motorPin2= 4;  
int motorPin3= 5; //REVerse motion of Right motor
int motorPin4= 6;
void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
pinMode(9,INPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
Serial.begin(9600);
}

void loop() {
  long distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  float duration=pulseIn(echo,HIGH);
  
  distance =(0.432*duration)/2;
  if(distance<=15)
 {
  digitalWrite(motorPin1,HIGH );
  digitalWrite(motorPin2,LOW);
  digitalWrite(motorPin3,HIGH);
  digitalWrite(motorPin4,LOW);
  Serial.print("hello");
  delay(50);
 }
 if(distance>15)
 {
  Serial.println("not available");  
  digitalWrite(motorPin1,HIGH);      
 digitalWrite(motorPin2,LOW);      //right motor rotates forward and left motor backward
 digitalWrite(motorPin3,LOW);
 digitalWrite(motorPin4,HIGH);
 } 
}
