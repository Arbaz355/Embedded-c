int trig=D4;
int echo=D3;
int ledR=11;
int ledG=10;
int ledB=9;

void setup() {
  // put your setup code here, to run once:
pinMode(D4, OUTPUT);
pinMode(D3,INPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);

Serial.begin(9600);
}
void loop() {
  long distance;
  digitalWrite(trig, LOW
);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  float duration=pulseIn(echo,HIGH);
  
  distance =(0.0343*duration)/2;
  Serial.println(distance);
 /* if (distance<=10)
  {
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    Serial.println("Red led in on");
  }
  else if(distance<=20)
  {
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    Serial.println("Green led in on");
  }
  else if(distance<=30)
  {
 digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    Serial.println("Blue led in on");   
  }
  
  
  

  // put your main code here, to run repeatedly:*/

}
