const byte LSM303D_address = 0b011110;
const byte MULTI_READ = 0b01000000;
const byte READ = 0b10000000;
const byte CTRL1 = 0x20;
const byte ACC_ALL_AXIS = 0b00000111;
const byte ACC_REFRESH_100Hz = 0b01100000;

const byte CTRL5 = 0x24;
const byte MAG_REFRESH_100Hz = 0b00010100;
const byte CTRL7 = 0x26;
const byte MAG_CONTINUOUS = 0b00000000;

const byte OUT_X_L_A = 0x28;
const byte OUT_Y_L_A = 0x2A;
const byte OUT_Z_L_A = 0x2C;
const byte OUT_X_L_M = 0x08;
const byte OUT_Y_L_M = 0x0A;
const byte OUT_Z_L_M = 0x0C;
const byte CS_pin = D0;

void setup()
{
  // init
  Serial.begin(9600);

  pinMode(CS_pin,OUTPUT);
  digitalWrite(CS_pin,HIGH);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV32);
  SPI.begin();

  digitalWrite(CS_pin,LOW);
  SPI.transfer(CTRL1);
  SPI.transfer(ACC_REFRESH_100Hz | ACC_ALL_AXIS);
  digitalWrite(CS_pin,HIGH);

  digitalWrite(CS_pin,LOW);
  SPI.transfer(CTRL5);
  SPI.transfer(MAG_REFRESH_100Hz);
  digitalWrite(CS_pin,HIGH);

  digitalWrite(CS_pin,LOW);
  SPI.transfer(CTRL7);
  SPI.transfer(MAG_CONTINUOUS);
  digitalWrite(CS_pin,HIGH);
}
void loop()
{
  int16_t acc_x;
  int16_t acc_y;
  int16_t acc_z;
  int16_t mag_x;
  int16_t mag_y;
  int16_t mag_z;

  digitalWrite(CS_pin,LOW);
  SPI.transfer(READ | OUT_X_L_A | MULTI_READ);
  //low byte
  acc_x = SPI.transfer(0);
  //high byte shigted by 8 positions to left
  acc_x |= SPI.transfer(0) << 8 ;

  acc_y = SPI.transfer(0);
  acc_y |= SPI.transfer(0) << 8 ;

  acc_z = SPI.transfer(0);
  acc_z |= SPI.transfer(0) << 8 ;
  digitalWrite(CS_pin,HIGH);
  //print
  Serial.print("X = ");
  Serial.print((2.0*acc_x)/0x7FFF);
  Serial.print(", ");

  Serial.print("Y = ");
  Serial.print((2.0*acc_y)/0x7FFF);
  Serial.print(", ");

  Serial.print("Z = ");
  Serial.println((2.0*acc_z)/0x7FFF);

  digitalWrite(CS_pin,LOW);
  SPI.transfer(READ | OUT_X_L_M | MULTI_READ);
  mag_x = SPI.transfer(0);
  mag_x |= SPI.transfer(0) << 8 ;

  mag_y = SPI.transfer(0);
  mag_y |= SPI.transfer(0) << 8 ;

  mag_z = SPI.transfer(0);
  mag_z |= SPI.transfer(0) << 8 ;
  digitalWrite(CS_pin,HIGH);

  Serial.print("X_mag = ");
  Serial.print((2.0*mag_x)/0x7FFF);
  Serial.print(", ");

  Serial.print("Y_mag = ");
  Serial.print((2.0*mag_y)/0x7FFF);
  Serial.print(", ");

  Serial.print("Z_mag = ");
  Serial.println((2.0*mag_z)/0x7FFF);

//wait a bit
  delay(500);
}
