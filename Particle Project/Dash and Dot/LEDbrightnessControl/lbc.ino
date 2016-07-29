
const int ledPin = D0; // LED connected to digital pin 0
byte incoming_byte;
void setup(){
  Serial.begin(9600); // USB port
  pinMode(ledPin, OUTPUT); // initialize the digital pin as an output:
}
void loop(){
  if (Serial.available()){
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
    // Serial.write(incoming_byte);
    }
  }
