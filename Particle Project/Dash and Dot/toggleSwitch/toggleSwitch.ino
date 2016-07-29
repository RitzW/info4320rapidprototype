// this program is to use switch to activiate motor

const int ledPin = D1;
const int buttonPin = A1;
boolean LED_on = false;
byte current_button = LOW;
byte old_button = LOW;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  while (1) // Fast loop…
  {
    // Read the state of the button
    current_button = digitalRead(buttonPin);
    if ((old_button == LOW)
      && (current_button == HIGH)) {
      // LOW to HIGH transition:
      // we toggle the LED state
      LED_on = !LED_on;
    }
    // remember the state of the button
    old_button = current_button;

    if (LED_on == true) {
      digitalWrite(ledPin, HIGH);
    }else {
        digitalWrite(ledPin, LOW);
      }
    }
  }
