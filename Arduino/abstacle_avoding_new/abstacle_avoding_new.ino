int trigPin=8;
int echoPin = 9;
int fwdright= 3;
int revright = 4;  
int revleft= 5; //REVerse motion of Right motor
int fwdleft = 6;      
      
       //ForWarD motion of Right motor
int c = 0;
 
void setup() {
  //Serial.begin(9600); 
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // put your setup code here, to run once:
 
}
 
void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
  
  if((distance>10))
 {
  digitalWrite(3,HIGH);                               //       If you dont get proper movements of your robot,
   digitalWrite(4,LOW);                               //        then alter the pin numbers
   digitalWrite(5,LOW);                               //
   digitalWrite(6,LOW);                              //
 }
 
  else if(distance<10)  
 {
   digitalWrite(3,LOW);
   digitalWrite(4,HIGH);
   digitalWrite(5,LOW);                                  //HIGH
   digitalWrite(6,HIGH);
                                            
 }
 
}
