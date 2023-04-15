#include "CowsAndBullsAnswer.h"
#include "CowsAndBullsComputerHelper.h"
#include "CowsAndBullsComputerPlayer.h"
#include "CowsAndBullsLivePlayer.h"
#include "NumberGuessing.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  srand(static_cast<unsigned int>(time(NULL))); 
  CowsAndBullsAnswer p = {};
  CowsAndBullsComputerHelper t = {};
  unsigned char n[4];
  unsigned short input = 0;

  for (int i = 0; i < 4; ++i) {
    input = 1 + rand() % 9;
    n[i] = static_cast<unsigned char>(input);
    for (int j = 0; j < i; j++) {
      if (n[j] == n[i]) {
        i--;
        break;
      }
    }
  }
  CowsAndBullsComputerPlayer p1(n, std::make_unique<NumberGuessing>());
  std::cout << p1[0] << p1[1] << p1[2] << p1[3] << std::endl;

  std::cout << "try to guess computer number" << std::endl;
  bool exit = false;
  do {
    for (int i = 0; i < 4; i++) {
      std::cin >> input;
      n[i] = static_cast<unsigned char>(input);
    }

    auto answer = p1.Ask(n);
    std::cout << "cows: " << static_cast<unsigned short>(answer.cows)
              << " bulls: " << static_cast<unsigned short>(answer.bulls)
              << std::endl;
    if (answer.bulls != 4) {
      std::cout << "try again" << std::endl;
    } else {
      exit = true;
    }
  } while (!exit);
  std::cout << "you guessed it! now its computer's turn to guess" << std::endl;

  std::cout << "Enter your number" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cin >> input;
    n[i] = static_cast<unsigned char>(input);
  }
  CowsAndBullsLivePlayer p2(n);
  do {
    t = p1(p);
    for (size_t i = 0; i < 4; i++) {
      std::cout << static_cast<short>(t.computer_number[i]);
    }
    std::cout << std::endl;
    p = p2.Ask(t.computer_number);
  } while (p.bulls != 4);
  std::cout << "computer guessed your number! it is: ";
  for (size_t i = 0; i < 4; i++) {
    std::cout << static_cast<short>(t.computer_number[i]);
  }
  std::cout << std::endl;

  p1();
  p.bulls = 0;

  std::cout << "Enter your number" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cin >> input;
    n[i] = static_cast<unsigned char>(input);
  }
  CowsAndBullsLivePlayer p3(n);
  
  do {
    t = p1(p);
    for (size_t i = 0; i < 4; i++) {
      std::cout << static_cast<short>(t.computer_number[i]);
    }
    std::cout << std::endl;
    p = p3.Ask(t.computer_number);
  } while (p.bulls != 4);
  std::cout << "computer guessed your number! it is: ";
  for (size_t i = 0; i < 4; i++) {
    std::cout << static_cast<short>(t.computer_number[i]);
  }
  return 0;
}
