#pragma once
//This structure stores current computer number and also saves previous variation of this number.
struct CowsAndBullsComputerHelper {
    unsigned char computer[4];

    CowsAndBullsComputerHelper& operator=(const CowsAndBullsComputerHelper& c);

    CowsAndBullsComputerHelper();
};