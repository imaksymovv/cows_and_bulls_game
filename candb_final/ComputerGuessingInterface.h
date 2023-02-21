#pragma once
#include "CowsAndBullsComputerHelper.h"
#include "CowsAndBullsAnswer.h"

class ComputerGuessingInterface {
 public:
  virtual void restart() = 0;
  
  virtual CowsAndBullsComputerHelper computer_guessing(
      CowsAndBullsAnswer answer) = 0;
};