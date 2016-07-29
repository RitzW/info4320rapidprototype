Servo myservo;
// potentiometer
// analog pin used to connect the potentiometer
int input_pin = A0;
// Pin to control the servo
const int servo_pin = D0;
// variable to read the value from the analog pin
int val;
void setup()
{
  // initialize the input_pin as an output:
  pinMode(input_pin, INPUT);
  // initialize the button pin as an input:
  // pinMode(buttonPin, INPUT);
  // attaches the servo on pin 9 to the servo object
  myservo.attach(servo_pin);
}

void loop()
{
  // reads the value of the potentiometer (value between 0 and 1023)
  val = analogRead(input_pin);
  // scale it to use it with the servo (value between 0 and 180)
  val = map(val, 0, 4095, 0, 110);
  // sets the servo position according to the scaled value
  myservo.write(val);
  // waits for the servo to get there
  delay(15);
}
