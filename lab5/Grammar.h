//
// Created by radoo on 11.12.2022.
//

#ifndef LAB5_GRAMMAR_H
#define LAB5_GRAMMAR_H

#include "Production.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <map>

class Grammar {
private:
    std::vector<std::string> terminals, nonTerminals;
    std::map<std::string, std::vector<Production>> productions;

public:
    const std::vector<std::string> &getTerminals() const;

    void setTerminals(const std::vector<std::string> &terminals);

    const std::vector<std::string> &getNonTerminals() const;

    void setNonTerminals(const std::vector<std::string> &nonTerminals);

    const std::map<std::string, std::vector<Production>> &getProductions() const;

    void setProductions(const std::map<std::string, std::vector<Production>> &productions);

    void readFromFile(std::string& filename);
};


#endif //LAB5_GRAMMAR_H
