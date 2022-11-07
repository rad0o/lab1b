//
// Created by radoo on 31.10.2022.
//

#include "Scanner.h"


Scanner::Scanner() {}

void Scanner::analyze(std::string &program_input, std::string &token_input) {
    std::ifstream program_file, token_file;
    std::ofstream pif_file, st_file;
    program_file.open(program_input);
    token_file.open(token_input);

    std::string line;
    std::string program_string;
    int lineNo = 1;

    while (std::getline(program_file, line, '\n')) {
        std::vector<std::string> tokens = tokenize(line);

        for (const auto &token: tokens) {
//            std::cout << token << '\n';
            unsigned long index;
            switch (classifyToken(token)) {
                case RESERVED_WORD:
                case OPERATOR:
                case SEPARATOR:
                    PIF.emplace_back(token, 0);
                    break;
                case IDENTIFIER:
                    index = symbolTable.add(token);
                    PIF.emplace_back("id", index);
                    break;
                case INT_CONSTANT:
                case STRING_CONSTANT:
                case BOOL_CONSTANT:
                case FLOAT_CONSTANT:
                case CHARACTER_CONSTANT:
                    index = symbolTable.add(token);
                    PIF.emplace_back("const", index);
                    break;
                case UNCLASSIFIED:
                    std::cout << "Error on line " << lineNo << ": unclassifiable token " << token << '\n';
                    break;
            }
        }
        lineNo++;
    }

    program_file.close();
    token_file.close();
    pif_file.open("PIF.out");
    st_file.open("ST.out");

    auto st = symbolTable.getTable();
    for(int i = 1; i < st.size(); i++) {
        st_file << i << " " << st[i] << '\n';
    }

    for(const auto& pair: PIF) {
        pif_file << '(' << pair.first << ", " << pair.second << ")\n";
    }

    pif_file.close();
    st_file.close();
}

std::vector<std::string> Scanner::tokenize(std::string &program_string) {
    std::vector<std::string> tokens;

    std::regex regex_separators(
            R"((('.')|("[^"]*")|(^(==)|^(!=)|^(<=)|^(>=)|([^=\+\-\/\*%\{\}\[\]\(\)<>:;,\n\s]))+|((==)|(!=)|(<=)|(>=)|[=\+\-\/\*%\{\}\[\]\(\)<>:;,])))");

    std::regex_iterator<std::string::iterator> regex_it(program_string.begin(), program_string.end(), regex_separators);
    std::regex_iterator<std::string::iterator> rend;

    while (regex_it != rend) {
        tokens.push_back(regex_it->str());
        regex_it++;
    }

    return tokens;
}

TokenType Scanner::classifyToken(const std::string &token) {
    auto it = std::find(this->reservedWords.begin(), this->reservedWords.end(), token);
    if (it != reservedWords.end()) {
        return RESERVED_WORD;
    } else if (std::regex_match(token, regex_operator)) {
        return OPERATOR;
    } else if (std::regex_match(token, regex_separator)) {
        return SEPARATOR;
    } else if (std::regex_match(token, regex_bool_const)) {
        return BOOL_CONSTANT;
    } else if (std::regex_match(token, regex_int_const)) {
        return INT_CONSTANT;
    } else if (std::regex_match(token, regex_string_const)) {
        return STRING_CONSTANT;
    } else if (std::regex_match(token, regex_float_const)) {
        return FLOAT_CONSTANT;
    } else if (std::regex_match(token, regex_char_const)) {
        return CHARACTER_CONSTANT;
    } else if (std::regex_match(token, regex_identifier)) {
        return IDENTIFIER;
    }

    return UNCLASSIFIED;
}

