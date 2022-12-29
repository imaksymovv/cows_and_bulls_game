#pragma once
#include "CowsAndBullsAnswer.h"
//This class includes all methods to help both players give answers about number of bulls and cows.
class CowsAndBullsPlayer {
public:
    //Function that analyses current player number and returns number of bulls and cows. 
    //Function recieves variable "num" - number of one of the players
    CowsAndBullsAnswer Ask(unsigned char num[4]) const;

    //overloaded operator
    unsigned int operator[](size_t index) const;
protected:
    explicit CowsAndBullsPlayer(unsigned char n[4]);
private:
    CowsAndBullsPlayer() = delete;
    unsigned char number[4];
};