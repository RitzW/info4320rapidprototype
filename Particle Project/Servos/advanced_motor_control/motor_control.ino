// Pin
const int enable_pin = D0;
const int set1_pin = D1;
const int set2_pin = D2;
int pwm;
char incoming;
// Set up
void setup(){
  pinMode(enable_pin, OUTPUT);
  pinMode(set1_pin, OUTPUT);
  pinMode(set2_pin, OUTPUT);
  Serial.begin(9600);
}
// enable/ disable
void start() {
  if (incoming = 'o') {
    pinMode(enable_pin, HIGH);
  }
  if (incoming = 's') {
    pinMode(enable_pin, LOW);
  }
}
// forward setting
void forward_setting() {
  if 
}
// Reverse setting
void reverse_setting() {

}

void loop() {
  if (Serial.available) {

  }
}
