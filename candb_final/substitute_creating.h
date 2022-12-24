#pragma once
#include "CowsAndBullsComputerHelper.h"

//Function that generates substitute for number
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