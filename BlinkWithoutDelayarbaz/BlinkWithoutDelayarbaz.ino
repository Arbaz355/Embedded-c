int led_green=4;
int led_yellow=5;
int led_red=6;
void setup ()
{
  pinMode (led_green,OUTPUT);
  pinMode (led_yellow,OUTPUT);
  pinMode (led_red,OUTPUT);
}
void loop ()
{
  digitalWrite (led_green,HIGH);
  delay(500);
  digitalWrite (led_green,LOW);
  delay(1000);
  digitalWrite (led_yellow,HIGH);
  delay(500);
  digitalWrite (led_yellow,LOW);
  delay(1000);
  digitalWrite (led_red,HIGH);
  delay(500);
  digitalWrite (led_red,LOW);
  delay(1000);
}

