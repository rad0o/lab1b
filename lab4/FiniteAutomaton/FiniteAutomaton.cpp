//
// Created by radoo on 20.11.2022.
//

#include "FiniteAutomaton.h"

FiniteAutomaton::FiniteAutomaton() {}

void FiniteAutomaton::initializeFromFile(std::string filename) {
    std::ifstream file;
    file.open(filename);

    std::string line;

    while(std::getline(file, line, '\n')) {
        if(line == "#") {
            break;
        }
        states.push_back(line);
    }
    while(std::getline(file, line, '\n')) {
        if(line == "#") {
            break;
        }
        alphabet.push_back(line);
    }
    while(std::getline(file, line, '\n')) {
        if(line == "#") {
            break;
        }
        transitions.push_back(Transition::fromString(line));
    }
    std::getline(file, line, '\n');
    initial_state = line;
    std::getline(file, line, '\n');
    while(std::getline(file, line, '\n')) {
        final_states.push_back(line);
    }
}

void FiniteAutomaton::print() {
    std::cout << "States: ";
    for(const auto& state: states) {
        std::cout << state << " ";
    }
    std::cout << '\n' << "Alphabet: ";
    for(const auto& symbol: alphabet) {
        std::cout << symbol << " ";
    }
    std::cout << '\n' << "Transitions: ";
    for(const auto& transition: transitions) {
        std::cout << transition << '\n';
    }
    std::cout << "Initial state: " << initial_state << '\n';
    std::cout << "Final states: ";
    for(const auto& state: final_states) {
        std::cout << state << " ";
    }
}

bool FiniteAutomaton::checkSequence(std::string sequence) {
    auto current_state = initial_state;

    for(int i = 0; i < sequence.size(); i++) {
        auto symbol = sequence.substr(i, 1);
        current_state = getTransitionDestination(current_state, symbol);
    }

    if(!isFinalState(current_state)) {
        return false;
    }

    return true;
}
bool FiniteAutomaton::isFinalState(std::string state) {
    return std::find(final_states.begin(), final_states.end(),state) != final_states.end();
}

std::string FiniteAutomaton::getTransitionDestination(std::string state, std::string symbol) {
    for(const auto& transition: transitions) {
        if(transition.getState() == state && transition.getSymbol() == symbol) {
            return transition.getResultingStates()[0];
        }
    }
    return "";
}
