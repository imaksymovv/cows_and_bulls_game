#pragma once
#include "CowsAndBullsAnswer.h"
#include "CowsAndBullsComputerHelper.h"
#include "Mixnumbers.h"

/*******************************************************************************
 * This is the class that allows computer to guess the number
 *******************************************************************************/
class Number_guessing {
 public:
  ~Number_guessing();

  /*******************************************************************************
   * Function that deletes memory for variable "first number"
   *******************************************************************************/
  void memory_cleaner();

  /*******************************************************************************
  * Funciton that generates number with already founded bulls and not used
  numbers
  *
  * Function returns generated computer number with already founded bulls.
  /*******************************************************************************/
  CowsAndBullsComputerHelper number_including_bulls_creating();

  /*******************************************************************************
   * This function analyzes number of cows and bulls for current number, then
   *changing this number and returns it.
   *
   * Function returns current computer number
   *
   * Function recieves "answer", that includes the number of cows and bulls for
   *current number
   *******************************************************************************/
  CowsAndBullsComputerHelper computer_guessing(CowsAndBullsAnswer answer);

 private:
  unsigned char bulls_before_cows_part =
      0;  ///< stores the number of bulls on the start
  unsigned char number_of_bulls =
      0;  ///< stores the number of bulls after at least 1 bulls founded
  unsigned char amount_of_bulls =
      0;  ///< stores the number of bulls when bull is detected
  unsigned char memory_for_number[4];   ///< saves the previous state of the
                                        ///< computer number before changing it
  unsigned char memory_for_bulls[4];    ///< stores already founded bulls
  unsigned char founded_bulls[4];       ///< stores placement of each bull
  unsigned char cows_checker;           ///< stores founded cow
  CowsAndBullsComputerHelper previous;  ///< stores number before return
  unsigned char number_of_cows = 0;     ///< stores number of cows
  bool number_have_bulls =
      false;  ///< when the bull in the first number is detected, becomes true
  bool searching_for_cows_started =
      false;  ///< when searching for the first bulls is ended, becomes true
  bool start_substitution = false;  ///< when the cow is detected, becomes true
  bool bull_founded = false;        ///< when the bull is detected, becomes true
  bool cows_founded = false;        ///< when the cow appears, becomes true
  unsigned char substitute = 0;     ///< substitute for computer number
  int searching_for_bulls_index =
      -1;  ///< index for the loop looking for the bulls
  int index_for_substitution =
      -1;  ///< index for the loop in which the number is substituted
  int index_when_cows_founded =
      -1;  ///< index for the loop looking for the cows
  int index_when_bulls_founded =
      -1;  ///< index for the loop loking for the bulls in first number
  bool false_numbers[9];  ///< array that stores "true" for incorrect numbers,
                          ///< and "false" for other numbers
  bool new_bull =
      false; /**<if during the search for a bull in the first number, the
                substitute turns out to be a bull, this variable becomes true*/

  bool cow_number_substitute = false; /**< becomes true to show that number need
                                      to be created without cows_checker in it*/

  bool number_includes_bull_or_cow =
      false;  ///< becomes true when bulls or cows in the first number are
              ///< detected
  bool any_cows_or_bulls = true;  ///< if the first number doesn't contains any
                                  ///< cows or bulls, becomes false
  Mixnumbers<CowsAndBullsComputerHelper, unsigned char> *first_number = nullptr;
  /**< performs permutations for number and return them*/

  bool number_doesnt_include_cORb =
      false; /**< needs to fill false_numbers with false after generating first
                  number*/
};