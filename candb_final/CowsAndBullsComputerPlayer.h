#pragma once
#include "CowsAndBullsAnswer.h"
#include "CowsAndBullsComputerHelper.h"
#include "CowsAndBullsPlayer.h"
#include "Mixnumbers.h"

class CowsAndBullsComputerPlayer : public CowsAndBullsPlayer {
public:
    //Destructor of the class
    ~CowsAndBullsComputerPlayer();

    //Function that means that the number is guessed
    void number_guessed();

    //Funciton that generates number with already founded bulls.
    //Function returns generated computer number with already founded bulls.
    CowsAndBullsComputerHelper number_including_bulls_creating();

    //Function that guessing number
    //Function returns current computer number
    CowsAndBullsComputerHelper computer_guessing(CowsAndBullsAnswer answer);

    //Constructor that saves number which computer need to guess
    //Contructor recieves variable "n" - number, which computer need to guess
    explicit CowsAndBullsComputerPlayer(unsigned char n[4]);

private:
    unsigned char bulls_before_cows_part = 0;
    unsigned char number_of_bulls = 0;
    unsigned char number_of_bulls1 = 0;
    unsigned char memory_for_number[4];
    unsigned char memory_for_bulls[4];
    unsigned char founded_bulls[4];
    unsigned char cows_checker;
    CowsAndBullsComputerHelper previous;
    unsigned char number_of_cows = 0;
    bool number_have_bulls = false;
    bool searching_for_cows_started = false;
    bool start_substitution = false;
    bool bull_founded = false;
    bool cows_founded = false;
    unsigned char substitute = 0;
    int searching_for_bulls_index = -1;
    int index_for_substitution = -1;
    int index_when_cows_founded = -1;
    int index_when_bulls_founded = -1;
    bool false_numbers[9];
    unsigned char new_bull = 0;
    bool cow_number_substitute = false;
    bool number_includes_bull_or_cow = false;
    bool number_created = false;
    bool any_cows_or_bulls = true;
    Mixnumbers* first_number = nullptr;
    unsigned char number_doesnt_include_cORb = 0;
};