//
// Created by radoo on 31.10.2022.
//

#include "SymbolTable.h"

unsigned long SymbolTable::add(std::string &token) {
    auto it = std::find(this->table.begin(), this->table.end(), token);
    if(it != this->table.end()) {
        return it - this->table.begin();
    } else {
        this->table.push_back(token);
        return this->table.size() - 1;
    }
}

SymbolTable::SymbolTable() {
    this->table = std::vector<std::string>();
}
