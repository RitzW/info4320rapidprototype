// Read A0 and report its value on the terminal 10 times per second
// const int ledPin = A0; // LED connected to A0
// The setup() method runs once, when the sketch starts
void setup(){
// initialize the digital pin as an output:
// pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

int res;
void loop(){
    res = analogRead(A0);
    Serial.print(res);
    delay(1000);
    Serial.print("\n");
  }
  // digitalWrite(ledPin, HIGH);
