const byte LSM303D_address = 0b011110;
const byte MULTI_READ = 0b10000000;
const byte CTRL1 = 0x20;
const byte ACC_ALL_AXIS = 0b00000111;
const byte ACC_REFRESH_100Hz = 0b01100000;
const byte OUT_X_L_A = 0x28;
const byte OUT_Y_L_A = 0x2A;
const byte OUT_Z_L_A = 0x2C;

void setup() {
  // open the serial port
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(LSM303D_address);
  Wire.write(CTRL1);
  Wire.write(ACC_REFRESH_100Hz| ACC_ALL_AXIS);
  Wire.endTransmission();
}

void loop() {
  int16_t acc_x;
  Wire.beginTransmission(LSM303D_address);
  Wire.write(OUT_X_L_A | MULTI_READ);
  Wire.endTransmission();
  Wire.requestFrom((int)LSM303D_address, 2);
  while(Wire.available() < 2);
  // low byte
  acc_x = Wire.read();
  // high byte shifted by 8 positions to left
  acc_x = (Wire.read() << 8) | acc_x ;
  // print
  Serial.print("X = ");
  // scale is 2G (see CTRL2)
  Serial.println((2.0*acc_x)/0x7FFF);
  // wait a bit
  delay(500);
}
