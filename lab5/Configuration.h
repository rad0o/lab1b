//
// Created by radoo on 12.12.2022.
//

#ifndef LAB5_CONFIGURATION_H
#define LAB5_CONFIGURATION_H

#include <stack>
#include <string>

enum PARSING_STATE {
    NORMAL,
    BACK,
    FINAL,
    ERROR
};

class Configuration {
public:
    PARSING_STATE state;
    int i;
    std::stack<std::pair<std::string, int>> workingStack;
    std::stack<std::string> inputStack;

    Configuration(PARSING_STATE state, int i, const std::stack<std::pair<std::string, int>> &workingStack,
                  const std::stack<std::string> &inputStack);
};


#endif //LAB5_CONFIGURATION_H
