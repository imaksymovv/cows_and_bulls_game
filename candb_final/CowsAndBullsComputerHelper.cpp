#include "CowsAndBullsComputerHelper.h"

CowsAndBullsComputerHelper& CowsAndBullsComputerHelper::operator=(const CowsAndBullsComputerHelper& c)
{
    for (size_t i = 0; i < 4; ++i)
    {
        this->computer_number[i] = c.computer_number[i];
    }
    return *this;
}

CowsAndBullsComputerHelper::CowsAndBullsComputerHelper() {}