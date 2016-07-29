// Morse code
const int ledPin = D0; // LED connected to digital pin 0
void setup(){
  Serial.begin(9600); // USB port
  pinMode(ledPin, OUTPUT); // initialize the digital pin as an output:
}
// dot in Morse code
void dot(){
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
}
// dash in Morse code
void dash(){
  digitalWrite(ledPin, HIGH);
  delay(900);
  digitalWrite(ledPin, LOW);
  delay(300);
}
// space in Morse code
void spaceBtwL(){
  digitalWrite(ledPin, LOW);
  delay(900); //3 dots
}
void spaceBtwW(){
  digitalWrite(ledPin, LOW);
  delay(2100); // 7 dots
}

void morseCode(incoming_byte){
  switch (incoming_byte){
    case '0':
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
    break;
    case '1':
      void dot();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
    break;
    case '2':
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
    break;
    case '3':
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
    break;
    case '4':
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
    break;
    case '5':
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
    break;
    case '6':
      void dash();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
    break;
    case '7':
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
    break;
    case '8':
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
    break;
    case '9':
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dash();
      void spaceBtwP();
      void dot();
      void spaceBtwP();
    break;
    case ' ':
      void spaceBtwW();
    break;
  }
  spaceBtwL();
}

void loop(){
  byte incoming_byte;
  if (Serial.available()){
    incoming_byte = Serial.read();
    morseCode(incoming_byte);
    // Serial.write(incoming_byte);
    }
  }
