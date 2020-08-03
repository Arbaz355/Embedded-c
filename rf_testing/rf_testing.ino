#define rfTransmitPin 4 
#define ledPinn 13

#define rfReceivePin A0

#define ledPin 13

unsigned int data = 0;

const unsigned int upperThreshold = 70;

const unsigned int lowerThreshold = 50;

void setup() {

pinMode(rfTransmitPin, OUTPUT);

pinMode(ledPinn, OUTPUT);

pinMode(ledPin, OUTPUT);

Serial.begin(9600);

}

void loop() {

for (int i=4000; i>5; i=i-(i/3)) {

digitalWrite(rfTransmitPin, HIGH);

digitalWrite(ledPinn, HIGH);

digitalWrite(rfTransmitPin,LOW);

digitalWrite(ledPinn, LOW);

}

data=analogRead(rfReceivePin);

if (data>upperThreshold) {

digitalWrite(ledPin, LOW);

Serial.println(data);

}

if(data<lowerThreshold) {

digitalWrite(ledPin, HIGH);

Serial.println(data);

}

}
