
#define p1 4   //defining push button1  
#define p2 5   //defining push bottom2

#define LM1 13      // left motor
#define LM2 12       // left motor
#define RM1 11      // right motor
#define RM2 10      // right motor

void setup()
{
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  if(digitalRead(p1))     // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  if(digitalRead(p2))     // Reverse
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
}
