#pragma once
#include "CowsAndBullsAnswer.h"
/*******************************************************************************
 * Basic class for players of the "Cows and Bulls" game
 *******************************************************************************/
class CowsAndBullsPlayer {
public:
  /*******************************************************************************
   * Function that analyses the number and determinants the number of bulls and
   *cows.
   *
   * Function recieves variable "num" - number of one of the players
   *
   * Function returns the number of bulls and cows
   *******************************************************************************/
  CowsAndBullsAnswer Ask(unsigned char num[4]) const;

  unsigned int operator[](size_t index) const;

protected:
  /*******************************************************************************
   * Constructor that saves number, which current player need to guess
   *
   * Constructor recieves "n" - number of one of the players
   *******************************************************************************/
  explicit CowsAndBullsPlayer(unsigned char n[4]);

private:
  CowsAndBullsPlayer() = delete;
  unsigned char number[4]; ///< stores hidden number
};