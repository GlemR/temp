#pragma once
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>


class Passwords {
private:
    unsigned int difficulty;

    // pins
    unsigned int display_sda;
    unsigned int display_scl;
    unsigned int numRows = 4;
    unsigned int numCols = 4;
    // internal variables
    unsigned int acc_pos;
    unsigned int solution_state = 0;
    unsigned int cursor_pos = 0;
    char answer[9] = "NNNNNNNN";


public:
    bool solved;
    unsigned long lastKeyTime = 0;
    unsigned long keyCooldown = 100; // 1000 milliseconds = 1 second
    bool waiting = false;
    bool resta=false;
    unsigned int solution_length = 8;
    char solution[9] = "~&[}(]i>";

    // caharcters used in the keypad
    // to be fixed
    char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
      };
    byte colPins[4] = {6, 7, 8, 9}; 
    byte rowPins[4] = {5, 4, 3, 2};
    Keypad keypadObj = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);
    // up to this it's getting declared twice but it works so it's ok for now
    Passwords();
    Passwords(unsigned int difficulty,
              unsigned int display_sda = 0,
              unsigned int display_scl = 0);
    void tick();
    unsigned short int verify();
};
