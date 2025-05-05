/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
*/

#include <Arduino.h>
#include "modules/hieroglyphs/hieroglyphs.h"
#include "modules/passwords/passwords.h"


Hieroglyphs first_game;
Passwords second_game;
int val = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  // pierwszy przycisk w kolejności -> ostatni przycisk w kolejności
  //unsigned int solution_pins[4] = {2, 3, 4, 6};
  //first_game = Hieroglyphs(2, solution_pins, 0, 0);
  

  //najpierw rows potem cols
  // byte colPins[] = {6, 7, 8, 9}; 
  // byte rowPins[] = {5, 4, 3, 2};
  second_game = Passwords(2,0,0);


//   char buff1[40];
//   sprintf(buff, "sol: %d %d %d %d", first_game.button_press_time[0],
//     first_game.button_press_time[1],
//     first_game.button_press_time[2],
//     first_game.button_press_time[3]);
// Serial.write(buff);
}


void loop() {
  // first_game.tick();
  // unsigned short int state = first_game.verify();
  second_game.tick();
  unsigned short int state = second_game.verify();
  if (state == 2)
    Serial.write("Game solved!\n");
  if (state == 1)
    Serial.write("Inccorrect Value!\n");


}
