// This program is for design project
// Pins for RED/GREEN/BLUE Triple Color LED
const int redPin = D0;
const int greenPin = D1;
const int bluePin = D2;
// Pins for motor
// analogWrite() works only on pins D0, D1, A0, A1, A4, A5, A6, A7, RX and TX.
const int motorEnablePin = A4;
const int leftSidePin = A5;
const int rightSidePin = D3;
// Ranger sensor
const int SensorPin = A0;
int sensores1;
int sensores2;

void setup() {
  // initialize the LED pin as an output:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // configure the motor pins
  pinMode(motorEnablePin, OUTPUT);
  pinMode(leftSidePin, OUTPUT);
  pinMode(rightSidePin, OUTPUT);
  // Motor is off going forward
  analogWrite(motorEnablePin, 0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  // configure the photo-transistor pin
  pinMode(SensorPin, INPUT);
  // initialize the button pin as an input:
  // pinMode(buttonPin, INPUT);
  // Set up serial communication
  Serial.begin(9600);
}
// motor moves forward
void forward() {
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, HIGH);
  digitalWrite(rightSidePin, LOW);
  analogWrite(motorEnablePin, 51);
}
// motor moves backward
void backward() {
  analogWrite(motorEnablePin,0);
  digitalWrite(leftSidePin, LOW);
  digitalWrite(rightSidePin, HIGH);
  analogWrite(motorEnablePin, 51);
}
// change LED brightness
void brightness(int lightPin, int num) {
  int ext = map(num, 0, 3465, 0, 255);
  analogWrite(lightPin, ext);
}

void loop() {
  // analogWrite(motorEnablePin, 51);
  // read and print Ranger sensor
  sensores1 = analogRead(SensorPin);
  int ss1 = constrain(sensores1, 630, 4095);
  sensores1 = map(ss1, 630, 4095, 4095, 630);
  Serial.print("sensores1:");
  Serial.print(sensores1);
  Serial.print("\n");
  delay(500);
  sensores2 = analogRead(SensorPin);
  int ss2 = constrain(sensores2, 630, 4095);
  sensores2 = map(ss2, 630, 4095, 4095, 630);
  Serial.print("sensores2:");
  Serial.print(sensores2);
  Serial.print("\n");
  int diff = sensores1 - sensores2;
  Serial.print("diff:");
  Serial.print(diff);
  Serial.print("\n");

  if (diff < 0) {
    // LED red ;
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);
    brightness(redPin, -diff);
    forward();
    delay(500);
  }
  else if (diff > 0) {
    // LED green ; hand up
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, HIGH);
    brightness(greenPin, diff);
    backward();
    delay(500);
  }
  else {
    // LED blue ; motor still
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(bluePin, HIGH);
    analogWrite(motorEnablePin,0);
    delay(500);
  }
}
