#include <iostream>
#include "Mixnumbers.h"

Mixnumbers::Mixnumbers(CowsAndBullsComputerHelper r) {
    for (size_t j = 0; j < 4; j++) {
        all_numbers[j][0] = r.current_computer_number[j];
    }
    for (size_t i = 1; i < 24; i++) {
        for (size_t j = 0; j < 4; j++) {
            all_numbers[j][i] = all_numbers[j][i - 1];
        }
        if (i == 5) {
            all_numbers[0][i] = all_numbers[3][i - 1];
            all_numbers[3][i] = all_numbers[0][i - 1];
        }
        if (i == 11 || i == 17) {
            all_numbers[0][i] = all_numbers[2][i - 1];
            all_numbers[2][i] = all_numbers[0][i - 1];
        }
        else if (i % 2 != 0) {
            all_numbers[1][i] = all_numbers[2][i - 1];
            all_numbers[2][i] = all_numbers[1][i - 1];
        }
        else {
            all_numbers[2][i] = all_numbers[3][i - 1];
            all_numbers[3][i] = all_numbers[2][i - 1];
        }
    }
}

CowsAndBullsComputerHelper Mixnumbers::reshuffle() {
    CowsAndBullsComputerHelper r;
    for (size_t i = 0; i < 4; i++) {
        r.current_computer_number[i] = all_numbers[i][counter_for_reshuffle];
    }
    counter_for_reshuffle++;
    return r;
}