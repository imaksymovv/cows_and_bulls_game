#pragma once

/*******************************************************************************
* This structure stores number to guess for cows and bulls game.
*******************************************************************************/
struct CowsAndBullsComputerHelper {
    unsigned char current_computer_number[4]; ///< stores current computer number

    CowsAndBullsComputerHelper& operator=(const CowsAndBullsComputerHelper& c);

    CowsAndBullsComputerHelper();
};