//
// Created by radoo on 20.11.2022.
//

#include "Transition.h"
#include <regex>

Transition Transition::fromString(std::string str) {
    Transition transition;

    std::regex char_regex(R"([a-zA-Z0-9])");
    auto it = std::sregex_iterator(str.begin(), str.end(), char_regex);
    auto end = std::sregex_iterator();

    transition.state = it->str();
    it++;
    transition.symbol = it->str();
    it++;

    for(; it != end; it++) {
        transition.resulting_states.push_back(it->str());
    }

    return transition;
}

std::ostream &operator<<(std::ostream &os, const Transition &transition) {
    os << "(" << transition.state << ", " << transition.symbol << ") -> ";

    for(auto state: transition.resulting_states) {
        os << state << " ";
    }

    return os;
}

const std::string &Transition::getState() const {
    return state;
}

const std::string &Transition::getSymbol() const {
    return symbol;
}

const std::vector<std::string> &Transition::getResultingStates() const {
    return resulting_states;
}

Transition::Transition() = default;
