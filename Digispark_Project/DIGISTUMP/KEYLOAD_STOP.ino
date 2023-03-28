#include "DigiKeyboard.h"

// CMD
const uint8_t cmd[] PROGMEM = {2,6, 2,51, 2,7};
// shutdown /r
const uint8_t shutdown[] PROGMEM = {0,22, 0,11, 0,24, 0,23, 0,7, 0,18, 0,29, 0,17, 0,44, 2,55, 0,22};

void write_in_cmd(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed
    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(5, 11); // GUI SHIFT CTRL B
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(21, 8); // GUI R
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(5, 11); // GUI SHIFT CTRL B
    DigiKeyboard.delay(200);
    write_in_cmd(cmd, sizeof(cmd)); // STRING CMD
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200);
    write_in_cmd(shutdown, sizeof(shutdown)); // STRING shutdown /r
    DigiKeyboard.delay(200);
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(200);
}

void loop() {}
