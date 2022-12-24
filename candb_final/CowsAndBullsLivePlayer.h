#pragma once
#include "CowsAndBullsPlayer.h"

class CowsAndBullsLivePlayer : public CowsAndBullsPlayer {
public:
    //Constructor that saves number, which player need to guess
    explicit CowsAndBullsLivePlayer(unsigned char n[4]) : CowsAndBullsPlayer(n) {}
};
