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
