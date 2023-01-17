#pragma once

/*******************************************************************************
* This is the class that doing permutations for the number
*******************************************************************************/
template<class T, class U>
class Mixnumbers {
public:

    /*******************************************************************************
    * Constructor recieves "r", that includes computer number that needs to be permutated
    *******************************************************************************/
    Mixnumbers(T r) {
        for (size_t j = 0; j < 4; j++) {
            all_numbers[j][0] = r.computer_number[j];
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

    /*******************************************************************************
    * Function that returns new permutation of the number
    *******************************************************************************/
    T reshuffle(){
    CowsAndBullsComputerHelper r;
    for (size_t i = 0; i < 4; i++) {
        r.computer_number[i] = all_numbers[i][counter_for_reshuffle];
    }
    counter_for_reshuffle++;
    return r;
}
private:
    U all_numbers[4][24]; ///< stores permutations for the number
    int counter_for_reshuffle = 1; ///< counter for returning all permutations
};