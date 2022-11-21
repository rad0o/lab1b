//
// Created by radoo on 20.11.2022.
//

#ifndef LAB4_FINITEAUTOMATON_H
#define LAB4_FINITEAUTOMATON_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../Transition/Transition.h"

class FiniteAutomaton {
private:
    std::vector<std::string> states;
    std::vector<std::string> alphabet;
    std::vector<Transition> transitions;
    std::string initial_state;
    std::vector<std::string> final_states;

    bool existsTransition(std::string state1, std::string state2);

public:
    FiniteAutomaton();

    void initializeFromFile(std::string filename);
    bool checkSequence(std::string sequence);
    bool isFinalState(std::string state);
    void print();
};


#endif //LAB4_FINITEAUTOMATON_H
