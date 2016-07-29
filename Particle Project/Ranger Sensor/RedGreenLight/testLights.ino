// constants definition
// const int ledPin = D0; // LED connected to digital pin 7
const int GreenPin = D2;
const int RedPin = D3;
// The setup() method runs once, when the sketch starts
void setup(){
// initialize the digital pin as an output:
  pinMode(GreenPin, OUTPUT);
  pinMode(RedPin, OUTPUT);
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop(){
  digitalWrite(GreenPin, HIGH);
  delay(1500);
  digitalWrite(RedPin, HIGH);
  delay(1000);
}
