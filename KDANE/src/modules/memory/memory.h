#pragma once
#include <Arduino.h>

class Memory{
    private:
        unsigned int difficulty;
        unsigned int digital_solution_len = 4;
        unsigned int digital_solution_input[4];
        unsigned int digital_solution_leds[4];
        unsigned int last_btn_state[4] = {1, 1, 1, 1};
        
        // internal variables
        unsigned int acc_pos = 1;
        unsigned int internal_tick = 100;
        unsigned int internal_counter = 0;
        unsigned int permutation_rounds = 24;
        unsigned int soluion_poss[4] = {0,1,2,3};


        unsigned int solution_state = 0;
    public:
        bool solved;
        unsigned int solution_length = 8;
        unsigned int solution[8];
        Memory();
        Memory(unsigned int difficulty, 
                unsigned int digital_solution_input[],
                unsigned int digital_solution_leds[]);
        
                
        void tick();
        unsigned short int verify();
        
};