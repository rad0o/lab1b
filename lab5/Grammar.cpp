//
// Created by radoo on 11.12.2022.
//

#include "Grammar.h"

const std::vector<std::string> &Grammar::getTerminals() const {
    return terminals;
}

void Grammar::setTerminals(const std::vector<std::string> &terminals) {
    Grammar::terminals = terminals;
}

const std::vector<std::string> &Grammar::getNonTerminals() const {
    return nonTerminals;
}

void Grammar::setNonTerminals(const std::vector<std::string> &nonTerminals) {
    Grammar::nonTerminals = nonTerminals;
}

const std::map<std::string, std::vector<Production>> &Grammar::getProductions() const {
    return productions;
}

void Grammar::setProductions(const std::map<std::string, std::vector<Production>> &productions) {
    Grammar::productions = productions;
}

std::vector<std::string> split(const std::string &str, const std::string &delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void Grammar::readFromFile(std::string &filename) {
    std::ifstream file;
    file.open(filename);

    std::string line;

    std::map<std::string, bool> isTerminal;

    while (std::getline(file, line, '\n')) {
        if (!line.empty()) {
            auto tokens = split(line, " ");

            isTerminal[tokens[0]] = false;

            std::vector<std::string> resultList;

            for (int i = 2; i < tokens.size(); i++) {
                resultList.push_back(tokens[i]);
                if (isTerminal.find(tokens[i]) == isTerminal.end()) {
                    isTerminal[tokens[i]] = true;
                }
            }

            Production production(tokens[0], resultList);

            productions[tokens[0]].push_back(production);
        }
    }

    file.close();

    for (const auto &sym: isTerminal) {
        if (sym.second) {
            terminals.push_back(sym.first);
        } else nonTerminals.push_back(sym.first);
    }
}

bool Grammar::isTerminal(const std::string &symbol) {
    return std::find(this->terminals.begin(), this->terminals.end(), symbol) != terminals.end();
}


