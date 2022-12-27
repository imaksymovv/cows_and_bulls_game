#pragma once
#include "CowsAndBullsAnswer.h"

class CowsAndBullsPlayer {
public:
    //Function that returns number of bulls and cows 
    //Function recieves variable "num" - number of one of the players
    CowsAndBullsAnswer Ask(unsigned char num[4]) const {
        CowsAndBullsAnswer counter = { };
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (num[i] == this->number[j]) {
                    if (j == i) {
                        counter.bulls++;
                    }
                    else {
                        counter.cows++;
                    }
                }
            }
        }
        return counter;
    }
    //overloaded operator
    unsigned int operator[](size_t index) const {
        return number[index];
    }
protected:
    explicit CowsAndBullsPlayer(unsigned char n[4]) :
        number{ n[0], n[1], n[2], n[3] } {}
private:
    CowsAndBullsPlayer() = delete;
    unsigned char number[4];
};