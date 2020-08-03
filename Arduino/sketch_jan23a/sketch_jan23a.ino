#define led 13
void setup() {
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(led,HIGH);
  delay(2000);
  digitalWrite(led,LOW);
  // put your main code here, to run repeatedly:

}
