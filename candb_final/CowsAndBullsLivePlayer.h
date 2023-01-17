#pragma once
#include "CowsAndBullsPlayer.h"
/*******************************************************************************
 * This is the class for live player for the "Cows and Bulls" game
 *******************************************************************************/
class CowsAndBullsLivePlayer : public CowsAndBullsPlayer {
public:
  /*******************************************************************************
   * Constructor that saves number, which computer need to guess
   *
   * Contructor recieves variable "n" - number, which computer need to guess
   *******************************************************************************/
  explicit CowsAndBullsLivePlayer(unsigned char n[4]);
};
