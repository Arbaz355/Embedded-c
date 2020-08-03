#define tem_pin A0
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(tem_pin);
 float x=(val/1024.00)*3300;
float cell= x/10;
Serial.print("Temperature:   ");
Serial.print(cell);
Serial.print("*C");
Serial.println();
delay(400);
float tem=(cell*9/5)+32;
Serial.print("Temprature in Far: ");
Serial.print(tem);
Serial.print("*F");
Serial.println();
delay(650);
}
