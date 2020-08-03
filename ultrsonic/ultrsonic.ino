//#include <NewPing.h>
#include <Servo.h>
int trigPin=8;
int echoPin = 9;
#define MAX_DISTANCE 200
#define MAX_SPEED 190
#define MAX_SPEED_OFFSET 20
//NewPing sonar(trigPin, echoPin,MAX_DISTANCE);
int motorPin1= 3;
int motorPin2= 4;  
int motorPin3= 5; //REVerse motion of Right motor
int motorPin4= 6; 
Servo myservo; 
boolean goesForward=false;
int distance=100;
int speedSet=0;
void setup()
{
  int readPing;
  myservo.attach(10);
  myservo.write(115);
  delay(2000);
  distance=readPing;
  delay(50);
  distance=readPing;
  delay(50);
  distance=readPing;
  delay(50);
   distance=readPing;
  delay(50);
    pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  int distanceR=0;
  int distanceL=0;
  int readPing;
    if(distance<=15)
    {
      moveStop();
      delay(100);
      moveBackward();
      delay(300);
      moveStop();
      delay(200);
      distanceR=lookRight();
      delay(200);
      distanceL=lookLeft();
      delay(200);
      if(distanceR>distanceL)
      {
        turnRight();
        moveStop();
      }
      else
      {
        turnRight();
        moveStop();
      }
    }
    else
    {
      moveForward();
    }
    distance=readPing;
    }
    int lookRight()
    {
      int readPing;
      myservo.write(50);
      delay(500);
      int distance= readPing;
      delay(100);
      myservo.write(115);
      return distance;
    }
    int lookLeft()
    {
      int readPing;
      myservo.write(50);
      delay(500);
      int distance= readPing;
      delay(100);
      myservo.write(115);
      return distance;
    }
    void moveForward() {                         
  digitalWrite(motorPin1,HIGH );
  digitalWrite(motorPin2,LOW);
  digitalWrite(motorPin3,HIGH);
  digitalWrite(motorPin4,LOW);
  return;
}
void moveBackward() {
 digitalWrite(motorPin1,LOW);
 digitalWrite(motorPin2,HIGH);
 digitalWrite(motorPin3,LOW);
 digitalWrite(motorPin4,HIGH);
}
void moveStop(){
 digitalWrite(motorPin1,LOW);
 digitalWrite(motorPin2,LOW);
 digitalWrite(motorPin3,LOW);
 digitalWrite(motorPin4,LOW);                         //wait after stopping
 return;
}

void turnLeft () {
 digitalWrite(motorPin1,HIGH);       //use the combination which works for you
 digitalWrite(motorPin2,LOW);      //right motor rotates forward and left motor backward
 digitalWrite(motorPin3,LOW);
 digitalWrite(motorPin4,HIGH);
 return;
}
void turnRight () {
 digitalWrite(motorPin1,LOW);       //use the combination which works for you
 digitalWrite(motorPin2,HIGH);    //left motor rotates forward and right motor backward
 digitalWrite(motorPin3,HIGH);
 digitalWrite(motorPin4,LOW);                           
 return;
}
void readPing()
{
  long distance,duration;
  digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 duration=pulseIn(echoPin,HIGH);
 distance=(duration*340)/20000;
}
 
