// string val[];

void setup(){
  Serial.begin(9600); // <baud_speed> = 9600
}

/*void main(){
  if (Serial.available() == True){
    val[] = Serial.read();
    Serial.write(val) // Serial.write(buf, len);
  }
}*/

void loop(){
  byte incoming_byte;
  if (Serial.available() > 0){
    incoming_byte = Serial.read();
    Serial.write(incoming_byte); // Serial.write(buf, len);
  }
}
// when you receive a code, it is not a letter.
// if(input == "1")
// the input should be character
