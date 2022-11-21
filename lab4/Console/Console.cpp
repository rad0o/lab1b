//
// Created by radoo on 21.11.2022.
//

#include "Console.h"

#include <iostream>

void Console::run() {
    finiteAutomaton.initializeFromFile("FA.txt");

    int cmd;
    bool done = false;

    while(!done) {
        printMenu();
        std::cin >> cmd;

        switch (cmd) {
            case 1:
                printFA();
                break;
            case 2:
                checkSequence();
                break;
            case 0:
                done = true;
                break;
        }
    }
}

void Console::printMenu() {
    std::cout << "1 - Print FA elements\n";
    std::cout << "2 - Verify sequence\n";
}

void Console::printFA() {
    finiteAutomaton.print();
    std::cout << '\n';
}

void Console::checkSequence() {
    std::cout << "Enter sequence: ";
    std::string sequence;

    std::cin >> sequence;

    if(finiteAutomaton.checkSequence(sequence)) {
        std::cout << "The string matches the FA\n";
    } else {
        std::cout << "The string doesn't match the FA\n";
    }
}
