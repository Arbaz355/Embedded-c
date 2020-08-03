#include <Servo.h>
#include <AFMotor.h>
int trigPin=A0;
int echoPin = A1;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo myservo; 
int distance=100;
int speedSet=0;
void setup()
{
  myservo.attach(10);
   pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
}

void loop() {
  long duration, distance;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 distance = (duration/29)/2;
Serial.println(duration);
    if(distance<=15)
    {
     int distanceR=lookLeft();
      delay(100);
     int distanceL=lookRight();
      delay(200);
      if(distanceR>distanceL)
      {
        turnLeft();
      }
      else
      {
        turnRight();
      }
    }
    else
    {
      moveForward();
    }
    }
    int lookRight()
    {
      myservo.write(180);
      delay(500);
     int passdistanceL=getdistance();
      delay(100);
     return passdistanceL;
    }
    int lookLeft()
    {
      myservo.write(90);
      delay(500);
      int passdistanceR=getdistance();
      delay(100);
     
      return passdistanceR;
    }
  void moveForward() { 
   motor1.run(FORWARD);
   motor2.run(FORWARD);
                            
 
}
void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
 
}
void moveStop(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
                     //wait after stopping
}

void turnLeft () {
 motor2.run(FORWARD);
 motor1.run(RELEASE);
  
 
}
void turnRight () {
  motor2.run(RELEASE);
  motor1.run(FORWARD);
                        
}
int getdistance()
{
    long duration, distance;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 return distance;
  }
 
