#pragma once
#include "CowsAndBullsComputerHelper.h"

class Mixnumbers {
public:
    //Constructor that generates all possible permutations of the number
    //Constructor recieves variable "r" of structure CowsAndBullsComputerHelper, that includes variable "computer" - computer number that needs to be permutated
    Mixnumbers(CowsAndBullsComputerHelper r);

    //Function that returns new permutation of the number
    CowsAndBullsComputerHelper reshuffle();
private:
    unsigned char all_numbers[4][24];
    int counter_for_reshuffle = 1;
};