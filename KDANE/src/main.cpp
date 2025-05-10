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
#include "modules/memory/memory.h"
#include <modules/cables/cables.h>


Hieroglyphs first_game;
Passwords second_game;
Memory third_game;
Cables fourth_game;
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
  // second_game = Passwords(2,0,0);

  // unsigned int digital_solution_input[4] = {5,6,7,8};
  // unsigned int digital_solution_leds[3]={2,3,4};
  // third_game = Memory(2,digital_solution_input,digital_solution_leds);

  unsigned int digital_solution_input = 9;
  unsigned int analog_pins[4]={0,1,2,3};
  fourth_game = Cables(digital_solution_input,analog_pins);


//   char buff1[40];
//   sprintf(buff1, "sol: %d %d %d %d %d %d %d %d", third_game.solution[0],
//     third_game.solution[1],
//     third_game.solution[2],
//     third_game.solution[3],
//     third_game.solution[4],
//     third_game.solution[5],
//     third_game.solution[6],
//     third_game.solution[7]);
// Serial.write(buff1);
}


void loop() {
  // first_game.tick();
  // unsigned short int state = first_game.verify();
  //second_game.tick();
  //unsigned short int state = second_game.verify();
  // third_game.tick();
  // unsigned short int state = third_game.verify();
  // if (state == 2)
  //   Serial.write("Game solved!\n");
  // if (state == 1)
  //   Serial.write("Inccorrect Value!\n");
  fourth_game.tick();
  char buff1[40];
  sprintf(buff1, "sol: %d\n", fourth_game.servo_pos);
  Serial.write(buff1);
}
