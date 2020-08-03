int GNDPin=18; //Set Analog pin 4 as GND
int VccPin=14; //Set Analog pin 5 as VCC
int st=19;
int xPin=A1; //X axis input
int yPin=A2; //Y axis input
int zPin=A3; //Z axis input(not used)
int Q1=9,Q2=10,Q3=11,Q4=12; //Output pins to be connected to 10, 11, 12, 13 of Decoder IC
long x; //Variabe for storing X coordinates
long y; //Variabe for storing Y coordinates
long z; //Variabe for storing Z coordinates
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
}
void stop_()
{
  Serial.println("");
  Serial.println("STOP");
}
void forward()
{
  Serial.println("");
  Serial.println("up");
}
void backward()
{
  Serial.println("");
  Serial.println("down");

}
void left()
{
  Serial.println("");
  Serial.println("previous");

}
void right()
{
  Serial.println("");
  Serial.println("next");
  
}
