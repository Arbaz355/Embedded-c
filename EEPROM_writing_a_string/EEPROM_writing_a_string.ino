#include <EEPROM.h>

void setup() {

 Serial.begin(9600); 

}
void loop() {
  char buff[2];
 char arb[]="arbaz";
 int addr=0;
 for(int i=0; i<sizeof(arb);i++) //for(int i=0; i<5; i++) 
 {
  EEPROM.write(addr,arb[i]);
  addr=addr+sizeof(char);
 }
 buff[0]=EEPROM.read(addr);
}
