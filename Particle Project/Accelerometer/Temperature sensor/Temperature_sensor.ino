const int TC74_address = 0b1001000;

void setup() {
  // open the serial port
  Serial.begin(9600);
  // Start the I2C module
  Wire.begin();
}

void loop() {
  // start a transmission to the TC74
  Wire.beginTransmission(TC74_address);
  // request register 0
  Wire.write((byte)0);
  // issue the request
  Wire.endTransmission();
  // prepare to receive on byte
  Wire.requestFrom(TC74_address, 1);
  // wait for the data to be ready
  while(!Wire.available());
  // print the temperature
  Serial.println(Wire.read(),DEC);
  delay(1000);
}
