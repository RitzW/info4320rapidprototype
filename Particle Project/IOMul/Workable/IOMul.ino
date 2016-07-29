#define PORTB (GPIOB->ODR)
#define PINC (GPIOC->IDR)

const int row_count = 7;
const int rows[7] = {A3, A4, A5, DAC, WKP, RX, TX};
const int col_count = 5;
const int col[5] = {D0, D1, D2, D3, D4};
int current_character;
int current_row;
int pattern_read;
int last_pattern[4];
const int16_t read_Mask = 0b101100;
const int16_t portB_message_mask = 0b0000000011111000;
const int16_t char_patterns[13][7] = { // [col][row]
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

const byte chartable[7][3] =
{{10,10,10},
{10,10,10},
{10,10,10},
{1,2,3},
{4,5,6},
{7,8,9},
{11,0,12}};

const int table[7][3] = {
  {'10','10','10'},
  {'10','10','10'},
  {'10','10','10'},
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

void setup(){
  Serial.begin(9600);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop(){
  for(int j = 0; j < 4; j++) {
    pinMode(rows[3+j], OUTPUT);
    digitalWrite(rows[3+j], HIGH);
    current_row = 3+j;
    pattern_read = PINC & read_Mask;

    if(last_pattern[current_row] != pattern_read) {
      if(pattern_read & 0b000100) {
        current_character = chartable[current_row][0];
      }
      if(pattern_read & 0b001000) {
        current_character = chartable[current_row][1];
      }
      if(pattern_read & 0b100000) {
        current_character = chartable[current_row][2];
      }
      if(pattern_read & 0b101100) {
        Serial.print("");
      }
    }
    last_pattern[current_row] = pattern_read;
    digitalWrite(rows[3+j], LOW);
    pinMode(rows[3+j], INPUT);

    for(int j=0; j< row_count; j++){
      PORTB = (PORTB & ~ portB_message_mask | char_patterns[current_character][j] & portB_message_mask);
      pinMode(rows[j], OUTPUT);
      digitalWrite(rows[j], HIGH);
      delay(1);
      digitalWrite(rows[j], LOW);
      pinMode(rows[j], INPUT);
    }
  }
}
