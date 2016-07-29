#define PORTB (GPIOB->ODR)
#define PINC (GPIOC->IDR)

const int row_count = 7;
const int rows[7] = {A3, A4, A5, DAC, WKP, RX, TX};
// following code from Keyboard_characters.ino
const int16_t portB_message_mask = 0b0000000011111000;
const int16_t char_patterns[13][7] = {
                        {~0b0000000001110000, //0
                         ~0b0000000010001000,
                         ~0b0000000010011000,
                         ~0b0000000010101000,
                         ~0b0000000011001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000100000, //1
                         ~0b0000000001100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000001110000},
                        {~0b0000000001110000, //2
                         ~0b0000000010001000,
                         ~0b0000000000001000,
                         ~0b0000000000110000,
                         ~0b0000000001000000,
                         ~0b0000000010000000,
                         ~0b0000000011111000},
                        {~0b0000000011111000, //3
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000000110000,
                         ~0b0000000000001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000010000, //4
                         ~0b0000000000110000,
                         ~0b0000000001010000,
                         ~0b0000000010010000,
                         ~0b0000000011111000,
                         ~0b0000000000010000,
                         ~0b0000000000010000},
                        {~0b0000000011111000, //5
                         ~0b0000000010000000,
                         ~0b0000000011110000,
                         ~0b0000000000001000,
                         ~0b0000000000001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000000111000, //6
                         ~0b0000000001000000,
                         ~0b0000000010000000,
                         ~0b0000000011110000,
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000011111000, //7
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000000100000,
                         ~0b0000000001000000,
                         ~0b0000000001000000,
                         ~0b0000000001000000},
                        {~0b0000000001110000, //8
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000,
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001110000},
                        {~0b0000000001110000, //9
                         ~0b0000000010001000,
                         ~0b0000000010001000,
                         ~0b0000000001111000,
                         ~0b0000000000001000,
                         ~0b0000000000010000,
                         ~0b0000000011100000},
                        {~0b0000000000100000, //!
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000100000,
                         ~0b0000000000000000,
                         ~0b0000000000100000},
                        {~0b0000000000100000,
                         ~0b0000000010101000, //*
                         ~0b0000000001110000,
                         ~0b0000000011111000,
                         ~0b0000000001110000,
                         ~0b0000000010101000,
                         ~0b0000000000100000},
                        {~0b0000000001010000, //#
                         ~0b0000000001010000,
                         ~0b0000000011111000,
                         ~0b0000000001010000,
                         ~0b0000000011111000,
                         ~0b0000000001010000,
                         ~0b0000000001010000}};
const int table[7][3] = {
  {'10','10','10'},
  {'10','10','10'},
  {'10','10','10'},
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

current_character = 10;

 void setup() {
   Serial.begin(9600);
   pinMode(D4, OUTPUT);
   pinMode(D3, OUTPUT);
   pinMode(D2, OUTPUT);
   pinMode(D0,OUTPUT);
   pinMode(D1,OUTPUT);
   pinMode(A3, OUTPUT);
   pinMode(A4, OUTPUT);
   pinMode(A5, OUTPUT);
   pinMode(DAC, OUTPUT);
   pinMode(WKP, OUTPUT);
   pinMode(RX, OUTPUT);
   pinMode(TX, OUTPUT);
 }

 /*inline void clean_update(_IO unit32_t &target_register, int mask, int value_to_update) {
   target_register = (target_register & ~mask) | (value_to_update & mask);
 }*/

 /*void loop() {
   for (int j = 0; j < row_count; j++) {
     PORTB = (PORTB & ~portB_message_mask) | (message[j] & portB_message_mask);
     delay(1000);
   }
 }*/
void loop() {
  int16_t pattern_read;
  const int16_t last_patterns[7] = {0, 0, 0, 0, 0, 0, 0};

  pattern_read = (PINC) & readMask;
  if(last_pattern[current_row] != pattern_read){
    if(pattern_read & 0b000100){
      Serial.print(conversion_table[current_row][0]);
      current_character = character_patterns_table[current_row][0];
    }
    if(pattern_read & 0b001000){
      Serial.print(conversion_table[current_row][1]);
      current_character = character_patterns_table[current_row][1];
    }
    if(pattern_read & 0b100000){
      Serial.print(conversion_table[current_row][2]);
      current_character = character_patterns_table[current_row][2];
    }
    if(pattern_read & 0b101100){
      Serial.print("");
    }

  }
  last_pattern[current_row] = pattern_read;




  for (int i = 0; i < 10; i++) {
    for (current_row = 0; current_row < row_count; current_row++) {
      clean_update(PORTB, portB_message_mask, clear_patterns[current_character]);
      pinMode(rows[current_row], OUTPUT);
      digitalWrite(row[current_row], HIGH);

      delayMicroseconds(200);
    }
  }
}
