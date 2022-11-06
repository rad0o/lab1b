//
// Created by radoo on 31.10.2022.
//

#include <string>
#include <vector>

#ifndef LAB2_SYMBOLTABLE_H
#define LAB2_SYMBOLTABLE_H

class SymbolTable {
private:
    std::vector<std::string> table;

public:
    explicit SymbolTable();

    unsigned long add(std::string token);

    const std::vector<std::string> &getTable() const;
};


#endif //LAB2_SYMBOLTABLE_H
