// Motor control
const int motorEnablePin = D0;
const int leftSidePin = D1;
const int rightSidePin = D2;

const int encoderPin = A0;
boolean turn = TRUE;

// old state of the encoder
boolean old_state = LOW;
// current state of the encoder
boolean current_state = LOW;
// current transition count
int pulse_count;
// number of transition for a full turn
const int full_turn_count = 860;

void setup() {
  // configure the motor pins
  pinMode(motorEnablePin,OUTPUT);
  pinMode(leftSidePin,OUTPUT);
  pinMode(rightSidePin,OUTPUT);
  // Motor is off going forward
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  // configure the photo-transistor pin
  pinMode(encoderPin,INPUT);
   Serial.begin(9600);
}

void loop() {
  // reset the pulse counter
  pulse_count = 0;
  if (turn == TRUE) {
    forward();
  }
  else {
    backward();
  }
  /*int a = analogRead(encoderPin);*/
  /*Serial.println(a);*/
  // start the motor at 20% speed
   analogWrite(motorEnablePin,51);
  // loop until we get the correct number
  while (pulse_count < full_turn_count) {
    current_state = digitalRead(encoderPin);
    /*Serial.println(pulse_count);*/
    if (current_state != old_state) {
      pulse_count++;
      Serial.println(pulse_count);
    }
    old_state = current_state;
  }
  // switch off the motor
  analogWrite(motorEnablePin, 0);
  // wait a bit
  delay(5000);
  // reverse
  turn = !turn;
}

void forward() {
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  analogWrite(motorEnablePin, 51);
}

void backward() {
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, LOW);
  digitalWrite(rightSidePin, HIGH);
  analogWrite(motorEnablePin, 51);
}
