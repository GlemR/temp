#pragma once
#include "modules/memory/memory.h"

Memory::Memory() {};
Memory::Memory(unsigned int difficulty, 
    unsigned int digital_solution_input[],
    unsigned int digital_solution_leds[]) {


    this->difficulty=difficulty;
    this->solved = false;

    // set digital pins 
    unsigned int digital_input_size = sizeof(this->digital_solution_input) / sizeof(this->digital_solution_input[0]); 
    for (int i=0; i < digital_input_size; i++) {
        this->digital_solution_input[i] = digital_solution_input[i];
        pinMode(digital_solution_input[i], INPUT_PULLUP);
    }

    // set digital pins for LEDs
    for (int i=0; i < digital_input_size; i++) {
        this->digital_solution_leds[i] = digital_solution_leds[i];
        pinMode(digital_solution_leds[i], OUTPUT);
    }

    // red - 0 ; green - 1 ; blue - 2 ; yellow - 3

    for (unsigned int i=0; i < this->solution_length; i++) {
        // choose random colors for the solution
        int random_index = random(0, this->digital_solution_len); delay(10);
        this->solution[i] = soluion_poss[random_index];
    }
}

void Memory::tick()
{
    if (solved)
    return;

    for(unsigned int i = 0;i<acc_pos;i++)
    {
        for(unsigned int j = 0;j<=i;j++)
        {
            digitalWrite(digital_solution_leds[solution[j]],HIGH);
            delay(100);
            digitalWrite(digital_solution_leds[solution[j]],LOW);
        }

    }
}

unsigned short int Memory::verify()
{
     // return:
    // 0 - game not solved
    // 1 - incorrect solution
    // 2 - game solved

    if (this->solved)
        return 0;   

    
}