#pragma once
#include "CowsAndBullsPlayer.h"
#include "NumberGuessing.h"

/*******************************************************************************
 * This is the class for computer player for the "Cows and Bulls" game
 *******************************************************************************/
class CowsAndBullsComputerPlayer : public CowsAndBullsPlayer,
                                   public NumberGuessing {
 public:
  /*******************************************************************************
   * Constructor that recieves number that the computer's opponent need to guess
   *
   * Contructor recieves variable "n" - number that the computer's opponent need
   *to guess
   *******************************************************************************/
  explicit CowsAndBullsComputerPlayer(unsigned char n[4]);
};