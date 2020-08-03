int led_pin=8;
int proximity_pin=4;
void setup() {
  // put your setup code here, to run once:
pinMode(led_pin, OUTPUT);
pinMode(proximity_pin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(proximity_pin==HIGH)
{
  digitalWrite(led_pin, HIGH);
  Serial.println("obstacle");
  delay(300);
}
else 
{
  digitalWrite(led_pin, LOW);
  Serial.println("No obslacle");
  delay(300);
}
int my_value=digitalRead(proximity_pin);
Serial.println(my_value);
}
