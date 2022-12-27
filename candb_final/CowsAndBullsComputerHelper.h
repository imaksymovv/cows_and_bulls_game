#pragma once

struct CowsAndBullsComputerHelper {
    unsigned char computer[4];
    //Function that saves previous number
    //Function recieves const reference of variable "c" of structure CowsAndBullsComputerHelper, that includes variable "computer", to save current number for the next turn
    //Спросить как называется этот конструктор!!!!!!!!!!!!!!!!
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