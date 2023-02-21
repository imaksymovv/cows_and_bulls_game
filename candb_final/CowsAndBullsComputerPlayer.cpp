#include "CowsAndBullsComputerPlayer.h"

CowsAndBullsComputerPlayer::CowsAndBullsComputerPlayer(
    unsigned char n[4], std::unique_ptr<ComputerGuessingInterface> &&r)
    : CowsAndBullsPlayer(n), virtual_connection{std::move(r)} {}

void CowsAndBullsComputerPlayer::restart() { virtual_connection->restart(); }

CowsAndBullsComputerHelper CowsAndBullsComputerPlayer::computer_guessing(
    CowsAndBullsAnswer answer) {
  return virtual_connection->computer_guessing(answer);
}