// this program is to key in number on console to adjust the speed of motor

const int ledPin = D0;
const int buttonPin = A0;
boolean LED_on = false;
byte current_button = LOW;
byte old_button = LOW;
byte incoming_byte;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  while (1)
  {
    if (Serial.available()) {
      incoming_byte = Serial.read();
      switch (incoming_byte){
        case '0':
          analogWrite(ledPin, 0);
        break;
        case '1':
          analogWrite(ledPin, 0.11 * 255);
        break;
        case '2':
          analogWrite(ledPin, 0.22 * 255);
        break;
        case '3':
          analogWrite(ledPin, 0.33 * 255);
        break;
        case '4':
          analogWrite(ledPin, 0.44 * 255);
        break;
        case '5':
          analogWrite(ledPin, 0.55 * 255);
        break;
        case '6':
          analogWrite(ledPin, 0.66 * 255);
        break;
        case '7':
          analogWrite(ledPin, 0.77 * 255);
        break;
        case '8':
          analogWrite(ledPin, 0.88 * 255);
        break;
        case '9':
          analogWrite(ledPin, 0.99 * 255);
        break;
      }
    }
  }
}

  /*// Read the state of the button
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
    }*/
