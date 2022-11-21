//
// Created by radoo on 21.11.2022.
//

#ifndef LAB4_CONSOLE_H
#define LAB4_CONSOLE_H

#include "../FiniteAutomaton/FiniteAutomaton.h"

class Console {
private:
    FiniteAutomaton finiteAutomaton;

    void printMenu();
    void printFA();
    void checkSequence();
public:
    void run();
};


#endif //LAB4_CONSOLE_H
