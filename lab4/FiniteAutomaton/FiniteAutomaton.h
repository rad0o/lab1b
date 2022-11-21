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

    std::string getTransitionDestination(std::string state, std::string symbol);
    bool isFinalState(std::string state);

public:
    FiniteAutomaton();

    void initializeFromFile(std::string filename);
    bool checkSequence(std::string sequence);
    void print();
};


#endif //LAB4_FINITEAUTOMATON_H
