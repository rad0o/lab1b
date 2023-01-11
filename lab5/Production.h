//
// Created by radoo on 11.12.2022.
//

#ifndef LAB5_PRODUCTION_H
#define LAB5_PRODUCTION_H

#include <vector>
#include <string>

class Production {
private:
    std::string nonTerminal;
    std::vector<std::string> resultList;

public:
    Production(const std::string &nonTerminal, const std::vector<std::string> &resultList);
    Production();

    const std::string &getNonTerminal() const;

    void setNonTerminal(const std::string &nonTerminal);

    const std::vector<std::string> &getResultList() const;

    void setResultList(const std::vector<std::string> &resultList);
};


#endif //LAB5_PRODUCTION_H
