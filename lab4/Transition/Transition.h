//
// Created by radoo on 20.11.2022.
//

#ifndef LAB4_TRANSITION_H
#define LAB4_TRANSITION_H

#include <vector>
#include <string>
#include <ostream>

class Transition {
private:
    std::string state;
    std::string symbol;
    std::vector<std::string> resulting_states;

public:
    explicit Transition();

    static Transition fromString(std::string str);

    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);

    const std::string &getState() const;

    const std::string &getSymbol() const;

    const std::vector<std::string> &getResultingStates() const;
};


#endif //LAB4_TRANSITION_H
