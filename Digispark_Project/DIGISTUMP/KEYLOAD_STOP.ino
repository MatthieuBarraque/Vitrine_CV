#include "DigiKeyboard.h"

const uint8_t cmd[] PROGMEM = {2,6, 2,51, 2,7};
const uint8_t shutdown[] PROGMEM = {0,22, 0,11, 0,24, 0,23, 0,7, 0,18, 0,29, 0,17, 0,44, 2,55, 0,22};

void write_in_cmd(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW);
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(1000);
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(5, 11);
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(21, 8);
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(5, 11);
    DigiKeyboard.delay(200);
    write_in_cmd(cmd, sizeof(cmd));
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(40, 0);
    DigiKeyboard.delay(200);
    write_in_cmd(shutdown, sizeof(shutdown));
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(40, 0);
    DigiKeyboard.delay(200);
}

void loop() {}
