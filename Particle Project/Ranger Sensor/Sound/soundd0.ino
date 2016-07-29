// Read A0 and report its value on the terminal 10 times per second
const int ledPin = D0; // LED connected to A0
// The setup() method runs once, when the sketch starts

void setup(){
// initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
    tone(ledPin, 100, 500);
    delay(200);
  }
  // digitalWrite(ledPin, HIGH);
