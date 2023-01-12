#pragma once

/*******************************************************************************
* This structure stores number to guess for cows and bulls game.
*******************************************************************************/
struct CowsAndBullsComputerHelper {
    unsigned char computer_number[4]; ///< stores computer number

    CowsAndBullsComputerHelper& operator=(const CowsAndBullsComputerHelper& c);

    CowsAndBullsComputerHelper();
};