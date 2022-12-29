#include <iostream>
#include "CowsAndBullsComputerPlayer.h"

namespace {
    //Function that generates substitute for number. This substitute is a number that is different from all other numbers in the current number, and it is needed to help computer guess the number.
    //Function recieves variable "r" of structure CowsAndBullsComputerHelper, that includes variable "computer" to generate substitute for current number
    //Function returns substitute for current number
    unsigned char substitute_creating(CowsAndBullsComputerHelper r) {
        unsigned char substitute = 0;
        bool numbers_are_not_same = false;
        for (size_t i = 0; i < 9; i++) {
            substitute = i + 1;
            for (size_t j = 0; j < 4; j++) {
                if (substitute == r.computer[j]) {
                    numbers_are_not_same = false;
                    break;
                }
                else {
                    numbers_are_not_same = true;
                }
            }
            if (numbers_are_not_same == true) {
                break;
            }
        }
        return substitute;
    }
};

void CowsAndBullsComputerPlayer::number_guessed() {
    if (first_number != nullptr) {
        delete first_number;
        first_number = nullptr;
    }
}

CowsAndBullsComputerPlayer::~CowsAndBullsComputerPlayer() {
    if (first_number != nullptr) {
        delete first_number;
    }
}

CowsAndBullsComputerHelper CowsAndBullsComputerPlayer::number_including_bulls_creating() {
    CowsAndBullsComputerHelper r;
    unsigned int index_for_false_numbers = 0;
    for (size_t i = 0; i < 4; i++) {
        if (founded_bulls[i] == 1) {
            r.computer[i] = memory_for_bulls[i];
        }
    }
    for (size_t i = 0; i < 4; i++) {
        if (founded_bulls[i] != 1) {
            index_for_false_numbers = 0;
            if (cow_number_substitute == true) {
                for (size_t j = 0; j < 9; j++) {
                    r.computer[i] = index_for_false_numbers + 1;
                    index_for_false_numbers++;
                    if (false_numbers[j] == false && r.computer[i] != cows_checker) {
                        false_numbers[j] = true;
                        break;
                    }
                }
            }
            else {
                for (size_t j = 0; j < 9; j++) {
                    r.computer[i] = index_for_false_numbers + 1;
                    index_for_false_numbers++;
                    if (false_numbers[j] == false) {
                        false_numbers[j] = true;
                        break;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < 4; i++) {
        if (founded_bulls[i] != 1) {
            index_for_false_numbers = r.computer[i] - 1;
            false_numbers[index_for_false_numbers] = false;
        }
    }
    return r;
}

CowsAndBullsComputerHelper CowsAndBullsComputerPlayer::computer_guessing(CowsAndBullsAnswer answer) {
    CowsAndBullsComputerHelper pc_number;
    pc_number = previous;
    unsigned int index_for_false_numbers = 0;
    if (number_have_bulls == false) {
        if (answer.bulls >= 1) {
            number_have_bulls = true;
            substitute = substitute_creating(pc_number);
            if (number_doesnt_include_cORb == 0) {
                for (size_t i = 0; i < 4; i++) {
                    false_numbers[i] = false;
                }
            }
            else {
                for (size_t i = 4; i < 8; i++) {
                    false_numbers[i] = false;
                }
            }
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
        }
        else {
            if (answer.cows >= 1) {
                number_includes_bull_or_cow = true;
                if (number_doesnt_include_cORb == 0) {
                    for (size_t i = 0; i < 4; i++) {
                        false_numbers[i] = false;
                    }
                }
                else {
                    for (size_t i = 4; i < 8; i++) {
                        false_numbers[i] = false;
                    }
                }
            }
            if (number_includes_bull_or_cow == false) {
                if (any_cows_or_bulls == false) {
                    for (size_t i = 0; i < 4; i++) {
                        false_numbers[i] = true;
                    }
                    number_doesnt_include_cORb++;
                }
                for (size_t i = 0; i < 9; i++) {
                    if (false_numbers[i] != true) {
                        false_numbers[i] = false;
                    }
                }
                if (number_includes_bull_or_cow == false) {
                    for (size_t i = 0; i < 4; i++) {
                        index_for_false_numbers = 0;
                        for (size_t j = 0; j < 9; j++) {
                            pc_number.computer[i] = index_for_false_numbers + 1;
                            index_for_false_numbers++;
                            if (false_numbers[j] == false) {
                                false_numbers[j] = true;
                                break;
                            }
                        }
                    }
                    any_cows_or_bulls = false;
                    previous = pc_number;
                    return pc_number;
                }
            }
            else {
                if (first_number == nullptr) {
                    first_number = new Mixnumbers(pc_number);
                }
                if (answer.bulls < 1) {
                    pc_number = first_number->reshuffle();
                }
            }
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
            previous = pc_number;
            return pc_number;
        }
    }
    if (searching_for_bulls_index != 4) {
        if (number_of_bulls == 0) {
            number_of_bulls = answer.bulls;
        }
        if (answer.bulls < number_of_bulls) {
            memory_for_bulls[searching_for_bulls_index] = memory_for_number[searching_for_bulls_index];
            founded_bulls[searching_for_bulls_index] = 1;

            index_for_false_numbers = memory_for_bulls[searching_for_bulls_index] - 1;
            false_numbers[index_for_false_numbers] = true;
        }
        if (answer.bulls > number_of_bulls) {
            memory_for_bulls[searching_for_bulls_index] = pc_number.computer[searching_for_bulls_index];
            founded_bulls[searching_for_bulls_index] = 1;

            index_for_false_numbers = memory_for_bulls[searching_for_bulls_index] - 1;
            false_numbers[index_for_false_numbers] = true;
            new_bull++;
        }
        for (size_t i = 0; i < 4; i++) {
            pc_number.computer[i] = memory_for_number[i];
        }
        searching_for_bulls_index++;
        if (searching_for_bulls_index == 4) {
            bulls_before_cows_part = answer.bulls + new_bull;
            pc_number = number_including_bulls_creating();
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
            substitute = substitute_creating(pc_number);
            previous = pc_number;
            return pc_number;
        }
        pc_number.computer[searching_for_bulls_index] = substitute;
    }
    else {
        if (searching_for_cows_started == false) {
            number_of_bulls = answer.bulls;
            searching_for_cows_started = true;
        }
        if (answer.bulls > number_of_bulls || answer.bulls > bulls_before_cows_part) {
            bull_founded = true;
            bulls_before_cows_part = answer.bulls;
            number_of_bulls = answer.bulls;
            start_substitution = false;
            cows_founded = false;
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
        }
        if (bull_founded == true) {
            number_of_cows = 0;
            if (index_when_bulls_founded == -1) {
                number_of_bulls1 = answer.bulls;
                substitute = substitute_creating(pc_number);
            }
            for (size_t i = 0; i < 4; i++) {
                pc_number.computer[i] = memory_for_number[i];
            }
            if (answer.bulls < number_of_bulls1) {
                memory_for_bulls[index_when_bulls_founded] = pc_number.computer[index_when_bulls_founded];
                founded_bulls[index_when_bulls_founded] = 1;

                index_for_false_numbers = memory_for_bulls[index_when_bulls_founded] - 1;
                false_numbers[index_for_false_numbers] = true;
            }
            if (answer.bulls > number_of_bulls1) {
                memory_for_bulls[index_when_bulls_founded] = substitute;
                founded_bulls[index_when_bulls_founded] = 1;

                substitute = substitute_creating(pc_number);
                index_for_false_numbers = memory_for_bulls[index_when_bulls_founded] - 1;
                false_numbers[index_for_false_numbers] = true;
            }
            do {
                index_when_bulls_founded++;
                if (index_when_bulls_founded == 4) {
                    pc_number = number_including_bulls_creating();
                    for (size_t i = 0; i < 4; i++) {
                        memory_for_number[i] = pc_number.computer[i];
                    }
                    substitute = substitute_creating(pc_number);
                    bull_founded = false;
                    index_when_bulls_founded = -1;
                    previous = pc_number;
                    return pc_number;
                }
            } while (founded_bulls[index_when_bulls_founded] == 1);
            pc_number.computer[index_when_bulls_founded] = substitute;
            previous = pc_number;
            return pc_number;
        }
        if (answer.cows > 0 && start_substitution == false && bull_founded == false) {
            cows_founded = true;
        }
        if (number_of_cows > answer.cows) {
            number_of_cows = 0;
            cows_checker = memory_for_number[index_when_cows_founded];
            cow_number_substitute = true;
            do {
                pc_number = number_including_bulls_creating();
            } while (pc_number.computer[0] == cows_checker || pc_number.computer[1] == cows_checker || pc_number.computer[2] == cows_checker || pc_number.computer[3] == cows_checker);
            cow_number_substitute = false;
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
            index_when_cows_founded = -1;
            cows_founded = false;
            start_substitution = true;
        }
        if (cows_founded == true) {
            if (index_when_cows_founded == -1) {
                number_of_cows = answer.cows;
            }
            for (size_t i = 0; i < 4; i++) {
                pc_number.computer[i] = memory_for_number[i];
            }
            do {
                index_when_cows_founded++;
                if (index_when_cows_founded == 4) {
                    index_when_cows_founded = -1;
                    cows_founded = false;
                    previous = pc_number;
                    return pc_number;
                }
            } while (founded_bulls[index_when_cows_founded] == 1);
            pc_number.computer[index_when_cows_founded] = substitute;
            previous = pc_number;
            return pc_number;
        }
        if (start_substitution == true) {
            for (size_t i = 0; i < 4; i++) {
                pc_number.computer[i] = memory_for_number[i];
            }
            do {
                index_for_substitution++;
                if (index_for_substitution == 4) {
                    index_for_substitution = -1;
                    start_substitution = false;
                    previous = pc_number;
                    return pc_number;
                }
            } while (founded_bulls[index_for_substitution] == 1);
            pc_number.computer[index_for_substitution] = cows_checker;
            index_for_substitution++;
            previous = pc_number;
            return pc_number;
        }

        if (answer.cows == 0 && bull_founded == false && cows_founded == false && start_substitution == false) {
            for (size_t i = 0; i < 4; i++) {
                if (founded_bulls[i] != 1) {
                    index_for_false_numbers = pc_number.computer[i] - 1;
                    false_numbers[index_for_false_numbers] = true;
                }
            }
            pc_number = number_including_bulls_creating();
            substitute = substitute_creating(pc_number);
            for (size_t i = 0; i < 4; i++) {
                memory_for_number[i] = pc_number.computer[i];
            }
        }
    }
    previous = pc_number;
    return pc_number;
}

CowsAndBullsComputerPlayer::CowsAndBullsComputerPlayer(unsigned char n[4]) : CowsAndBullsPlayer(n) {}