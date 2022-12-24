#pragma once

struct CowsAndBullsComputerHelper {
    unsigned char computer[4];
    CowsAndBullsComputerHelper& operator=(const CowsAndBullsComputerHelper& c)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            this->computer[i] = c.computer[i];
        }
        return *this;
    }

    CowsAndBullsComputerHelper()
    {}
};