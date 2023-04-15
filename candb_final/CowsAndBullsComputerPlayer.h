#pragma once
#include "CowsAndBullsPlayer.h"
#include "NumberGuessing.h"
#include "ComputerGuessingInterface.h"

/*******************************************************************************
 * This is the class for computer player for the "Cows and Bulls" game
 *******************************************************************************/
class CowsAndBullsComputerPlayer : public CowsAndBullsPlayer {
 public:
  void operator()() { 
	  restart();
  }

  void restart();

  CowsAndBullsComputerHelper operator()(CowsAndBullsAnswer answer) { 
	  return computer_guessing(answer);
  }

  CowsAndBullsComputerHelper computer_guessing(CowsAndBullsAnswer answer);
  /*******************************************************************************
   * Constructor that recieves number that the computer's opponent need to guess
   *
   * Contructor recieves variable "n" - number that the computer's opponent need
   *to guess
   *******************************************************************************/
CowsAndBullsComputerPlayer(unsigned char n[4], std::unique_ptr<ComputerGuessingInterface>&& r);

private:
std::unique_ptr<ComputerGuessingInterface> guessing_methods;
};