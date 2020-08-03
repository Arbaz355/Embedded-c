int GNDPin=18; //Set Analog pin 4 as GND
int VccPin=14; //Set Analog pin 5 as VCC
int st=19;
int xPin=A1; //X axis input
int yPin=A2; //Y axis input
int zPin=A3; //Z axis input(not used)
int Q1=9,Q2=10,Q3=11,Q4=12; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC
long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
long z;//Variabe for storing Z coordinates
int a;
int b;
int c;
int d;

void setup()
{
  Serial.begin(9600);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(Q4,OUTPUT);
  pinMode(GNDPin, OUTPUT);
  pinMode(st, OUTPUT);
  pinMode(VccPin, OUTPUT);
  digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(st, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
}
void loop()
{
  x = analogRead(xPin); //Reads X coordinates
  y = analogRead(yPin); //Reads Y coordinates
  z = analogRead(zPin); //Reads Z coordinates (Not Used)
    if(x<340)      // Change the value for adjusting sensitivity  
      forward();
    else if(x>400) // Change the value for adjusting sensitivity
      backward();
    else if(y>400) // Change the value for adjusting sensitivity
      right();
    else if(y<340) // Change the value for adjusting sensitivity
      left();
    else
      stop_();
      int a=digitalRead(5);
      int b=digitalRead(4);
      int c=digitalRead(3);
      int d=digitalRead(2);
      if(a&&c==HIGH)
      {
        Serial.println("yeah!!!");
        }
}
void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,LOW);
}
void forward()
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}
void backward()
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
void left()
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(Q1,LOW);
  digitalWrite(Q2,HIGH);
  digitalWrite(Q3,HIGH);
  digitalWrite(Q4,LOW);
}
void right()
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(Q1,HIGH);
  digitalWrite(Q2,LOW);
  digitalWrite(Q3,LOW);
  digitalWrite(Q4,HIGH);
}
