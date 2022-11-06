#include <iostream>
#include "SymbolTable/SymbolTable.h"
#include "Scanner/Scanner.h"

int main(int argc, char** argv) {
    SymbolTable symbolTable = SymbolTable();
    Scanner scanner = Scanner();

    std::string program = std::string(argv[1]), token = std::string(argv[2]);

    scanner.analyze(program, token);
}
