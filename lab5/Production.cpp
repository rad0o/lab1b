//
// Created by radoo on 11.12.2022.
//

#include "Production.h"

Production::Production(const std::string &nonTerminal, const std::vector<std::string> &resultList) : nonTerminal(
        nonTerminal), resultList(resultList) {}

const std::string &Production::getNonTerminal() const {
    return nonTerminal;
}

void Production::setNonTerminal(const std::string &nonTerminal) {
    Production::nonTerminal = nonTerminal;
}

const std::vector<std::string> &Production::getResultList() const {
    return resultList;
}

void Production::setResultList(const std::vector<std::string> &resultList) {
    Production::resultList = resultList;
}

Production::Production() {

}
