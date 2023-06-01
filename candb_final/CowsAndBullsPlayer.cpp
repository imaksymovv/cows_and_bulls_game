#include "CowsAndBullsPlayer.h"

CowsAndBullsAnswer CowsAndBullsPlayer::Ask(unsigned char num[4]) const {
  CowsAndBullsAnswer counter = {};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {//std::count, std::find, std::distance
      if (num[i] == this->number[j]) {
        if (j == i) {
          counter.bulls++;
        } else {
          counter.cows++;
        }
      }
    }
  }
  return counter;
}

unsigned int CowsAndBullsPlayer::operator[](size_t index) const {
  return number[index];
}

CowsAndBullsPlayer::CowsAndBullsPlayer(unsigned char n[4])
    : number{n[0], n[1], n[2], n[3]} {}
