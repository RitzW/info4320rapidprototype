#define PORTB (GPIOB->ODR)
#define PINB (GPIOB->IDR)

// PORTB = (PORTB & ~MASK) | (0b00101000 & MASK)
const int scanning_patterns_mask = 0b00111000;
const int scanning_patterns_count = 6;
const int scanning_patterns[6] = {0b00001000,
  0b00010000, 0b00011000, 0b00100000, 0b00101000, 0b00110000
};

void setup() {
  Serial.begin(9600);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

/*inline void clean_update(_IO unit32_t &target_register, int mask, int value_to_update) {
  target_register = (target_register & ~mask) | (value_to_update & mask);
}*/

void loop() {
  for (int j = 0; j < scanning_patterns_count; j++) {
    PORTB = (PORTB & ~scanning_patterns_mask) | (scanning_patterns[j] & scanning_patterns_mask);
    delay(1000);
  }
}
