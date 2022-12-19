//
// Created by radoo on 12.12.2022.
//

#include "Configuration.h"

Configuration::Configuration(PARSING_STATE state, int i, const std::stack<std::pair<std::string, int>> &workingStack,
                             const std::stack<std::string> &inputStack) : state(state), i(i),
                                                                          workingStack(workingStack),
                                                                          inputStack(inputStack) {}
