const int lamp=3;
const int buzzer=4;
const int ignition=5;
const int seat_belt=6;
void setup() 
{
  pinMode (lamp, OUTPUT);
  pinMode (buzzer, OUTPUT);
  pinMode(ignition,INPUT);
  pinMode (seat_belt, INPUT);
}

void loop() 
{
  int key=digitalRead (ignition);
  int belt=digitalRead (seat_belt);
  if(key==LOW && belt==HIGH)
  {
    digitalWrite(lamp,HIGH);
    digitalWrite (buzzer,HIGH);
  }
  if(key==LOW && belt==LOW)
  {
    digitalWrite(lamp, LOW);
    digitalWrite(buzzer,LOW);
  }
}
