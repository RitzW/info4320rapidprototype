// Read A0 and report its value on the terminal 10 times per second
// const int ledPin = A0; // LED connected to A0
// The setup() method runs once, when the sketch starts
int res;
const int PIN = D0;
void setup(){
// initialize the digital pin as an output:
  pinMode(PIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
    /*res = analogRead(A0);
    Serial.print(res);
    delay(1000);
    Serial.print("\n");*/
    tone(PIN, 50, 500);

    // noTone(PIN);
  }
  // digitalWrite(ledPin, HIGH);
