#pragma once
#include "CowsAndBullsComputerHelper.h"

/*******************************************************************************
* This is the class that doing permutations for the number
*******************************************************************************/
class Mixnumbers {
public:

    /*******************************************************************************
    * Constructor recieves "r", that includes "current_computer_number" - computer number that needs to be permutated
    *******************************************************************************/
    Mixnumbers(CowsAndBullsComputerHelper r);

    /*******************************************************************************
    * Function that returns new permutation of the number
    *******************************************************************************/
    CowsAndBullsComputerHelper reshuffle();
private:
    unsigned char all_numbers[4][24]; ///< stores permutations for the number
    int counter_for_reshuffle = 1; ///< counter for returning all permutations
};