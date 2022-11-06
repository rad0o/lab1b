//
// Created by radoo on 31.10.2022.
//

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include "../SymbolTable/SymbolTable.h"

#ifndef LAB2_SCANNER_H
#define LAB2_SCANNER_H

enum TokenType {
    RESERVED_WORD,
    OPERATOR,
    SEPARATOR,
    IDENTIFIER,
    INT_CONSTANT,
    STRING_CONSTANT,
    BOOL_CONSTANT,
    FLOAT_CONSTANT,
    CHARACTER_CONSTANT,
    UNCLASSIFIED
};

class Scanner {
private:
    SymbolTable symbolTable;
    std::vector<std::pair<std::string, int>> PIF;
    std::vector<std::string> reservedWords {"Integer", "Character", "Boolean", "String", "Float", "Array", "read", "print", "for", "endfor", "if", "endif", "do", "break", "else"};

    std::regex regex_operator = std::regex(R"([\+\-\/\*%=<>]|(<=)|(==)|(>=))");
    std::regex regex_separator = std::regex(R"([\{\}\[\]\(\)<>:;,])");
    std::regex regex_identifier = std::regex(R"([a-zA-Z][a-zA-Z0-9]*)");
    std::regex regex_int_const = std::regex(R"([+-]?[0-9]+)");
    std::regex regex_string_const = std::regex(R"("[^"]*")");
    std::regex regex_bool_const = std::regex(R"((TRUE)|(FALSE))");
    std::regex regex_float_const = std::regex(R"([+-]?[0-9]+.[0-9]+)");
    std::regex regex_char_const = std::regex(R"(('.'))");

    std::vector<std::string> tokenize(std::string& program_string);
    TokenType classifyToken(const std::string& token);

public:
    Scanner();

    void analyze(std::string &program_input, std::string &token_input);

};


#endif //LAB2_SCANNER_H
