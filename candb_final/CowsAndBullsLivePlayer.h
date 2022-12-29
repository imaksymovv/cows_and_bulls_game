#pragma once
#include "CowsAndBullsPlayer.h"
//This class includes all needed methods for player to guess computer's number.
class CowsAndBullsLivePlayer : public CowsAndBullsPlayer {
public:
    //Constructor that saves number, which player need to guess
    //Contructor recieves variable "n" - number, which player need to guess
    explicit CowsAndBullsLivePlayer(unsigned char n[4]);
};
