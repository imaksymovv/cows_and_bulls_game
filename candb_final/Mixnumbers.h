#pragma once
#include "CowsAndBullsComputerHelper.h"

/*******************************************************************************
* This is the class that doing permutations for the number
*******************************************************************************/
template<class T, class U, class V>
class Mixnumbers {
public:

    /*******************************************************************************
    * Constructor recieves "r", that includes computer number that needs to be permutated
    *******************************************************************************/
    Mixnumbers(T r);

    /*******************************************************************************
    * Function that returns new permutation of the number
    *******************************************************************************/
    T reshuffle();
private:
    U all_numbers[4][24]; ///< stores permutations for the number
    V counter_for_reshuffle = 1; ///< counter for returning all permutations
};