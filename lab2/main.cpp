#include <iostream>
#include "SymbolTable.h"

int main() {
    SymbolTable symbolTable = SymbolTable();

    std::string token = "token";
    std::string token1 = "token1";

    int ind1 = symbolTable.add(token);
    int ind2 = symbolTable.add(token1);
    int ind3 = symbolTable.add(token);

    std::cout << ind1 << " " << ind2 << " " << ind3;
}
