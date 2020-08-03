int buzzer_pin=8;
int ir_pin=4;
void setup() {
  // put your setup code here, to run once:
pinMode (buzzer_pin, OUTPUT);
pinMode (ir_pin, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
if(ir_pin==HIGH)
{
  digitalWrite(buzzer_pin, HIGH);
}
else 
{
  digitalWrite(buzzer_pin, LOW);
}
}
