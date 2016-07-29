// button connected to digital A0
const int buttonPin = A0;
// Length of a dash in ms
const int dash = 300;
// length of a dot in ms
const int dot = 100;
// state of the button this iteration
byte current_button = LOW;
// previous state of the button
byte old_button = LOW;

// start of a pressed event
unsigned long int start_high;
// end of a pressed event
unsigned long int stop_high;
// start of a non-pressed event
unsigned long int start_low;
// end of a non-pressed event
unsigned long int stop_low;

// The setup() method runs once,
// when the sketch starts
void setup()
{
  // initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

byte read_button(byte pin, byte ref_value)
{
  // observed the state of the button
  byte current_button = digitalRead(pin);
  // There is a LOW -> HIGH transition // or a HIGH -> LOW transition
  if (((ref_value == LOW)
  && (current_button == HIGH)) || ((ref_value == HIGH)
  && (current_button == LOW)))
  {
  delay(5);
  // update the state of the button
  current_button = digitalRead(pin); }
  return(current_button);
}

void loop()
{
  // Read the current state
  current_button = read_button(buttonPin, old_button);
  // LOW -> HIGH transition
  if ((old_button == LOW)
  && (current_button == HIGH))
  {
    // Update timing
    start_high = millis();
    stop_low = start_high;
  }
// HIGH -> LOW transition
  if ((old_button == HIGH)
  && (current_button == LOW))
  {
  // Update timing
  stop_high = millis();
  start_low = stop_high;
  // detect dashs and dots
  if ((stop_high - start_high) >= dash)
  {
    Serial.print("-");
  }
  else
  {
    if ((stop_high - start_high) >= dot)
    {
      Serial.print(".");
    }
  }
}
old_button = current_button;
}
