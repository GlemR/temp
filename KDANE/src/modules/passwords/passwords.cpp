#pragma once
#include "modules/passwords/passwords.h"

LiquidCrystal_I2C lcd2(0x3F, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

Passwords::Passwords() {};
Passwords::Passwords(unsigned int difficulty, 
                     unsigned int display_sda = 0,
                     unsigned int display_scl = 0) {

    this->difficulty=difficulty;
    this->display_sda = display_sda;
    this->display_scl = display_scl;
    this->solved = false;
    //set the keymap

    lcd2.init();
    lcd2.backlight();

    for (unsigned int i = 0; i < this->solution_length; i++) {
        lcd2.setCursor(i, 0);        
        lcd2.write(this->solution[i]);
    }
    // here again the keypad is getting declared twice but it works so it's ok for now
    char keys[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
      };
      byte colPins[] = {6, 7, 8, 9}; 
      byte rowPins[] = {5, 4, 3, 2};

    Keypad keypadObj = Keypad(makeKeymap(keys), rowPins, colPins, this->numRows, this->numCols);


}



void Passwords::tick(){

    if (solved)
    return;

    if(!waiting) // creating small delay to avoid any noise
    {
        char key = keypadObj.getKey();
        if (key)
        {   
            lcd2.setCursor(cursor_pos,1);
            lcd2.write(key);
            answer[cursor_pos]=key;
            cursor_pos+=1;
            lastKeyTime = millis();
            waiting = true;
        }
    }
    if (waiting && (millis() - lastKeyTime >= keyCooldown)) {
        waiting = false;
    }
}

unsigned short int Passwords::verify(){
    // return:
    // 0 - no actions performed
    // 1 - incorrect solution
    // 2 - game solved

    if (this->solved)
        return 0;

    if (cursor_pos==this->solution_length) {
        if (strcmp(answer, solution) == 0) {
            this->solved = true;
            return 2;
        }
        else {
            lcd2.clear();
            for (unsigned int i = 0; i < this->solution_length; i++) {
                lcd2.setCursor(i, 0);        
                lcd2.write(this->solution[i]);
            }
            cursor_pos=0;
            return 1;
        }
    }
    return 0;   
}