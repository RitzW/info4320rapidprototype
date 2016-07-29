// constants definition
const int ledPin = D0; // LED connected to digital pin 7
// The setup() method runs once, when the sketch starts
void setup(){
// initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop(){
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
