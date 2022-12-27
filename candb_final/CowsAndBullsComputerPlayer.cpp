#include <iostream>
#include "CowsAndBullsComputerPlayer.h"

void CowsAndBullsComputerPlayer::number_guessed() {
    if (first_number != nullptr) {
        delete first_number;
        first_number = nullptr;
    }
}