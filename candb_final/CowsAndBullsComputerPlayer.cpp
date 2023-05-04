#include "CowsAndBullsComputerPlayer.h"

CowsAndBullsComputerPlayer::CowsAndBullsComputerPlayer(
    unsigned char n[4], std::unique_ptr<ComputerGuessingInterface> &&r)
    : CowsAndBullsPlayer(n), guessing_methods{std::move(r)} {}

void CowsAndBullsComputerPlayer::restart() { guessing_methods->restart(); }

CowsAndBullsComputerHelper CowsAndBullsComputerPlayer::computer_guessing(
    CowsAndBullsAnswer answer) {
  return guessing_methods->computer_guessing(answer);
}

  CowsAndBullsComputerHelper CowsAndBullsComputerPlayer::operator()(
    CowsAndBullsAnswer answer) {
  return computer_guessing(answer);
}

    void CowsAndBullsComputerPlayer::operator()() { restart(); }