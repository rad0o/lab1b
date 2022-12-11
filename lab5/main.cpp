#include <iostream>
#include "Grammar.h"
#include "Production.h"

int main() {
    Grammar grammar;
    std::string fname = "g1.txt";
    grammar.readFromFile(fname);

    auto terminals = grammar.getTerminals(), nonTerminals = grammar.getNonTerminals();
    auto prods = grammar.getProductions();

    std::cout << "Terminals:\n";
    for(auto & terminal : terminals) {
        std::cout << terminal << '\n';
    }
    std::cout << '\n';

    std::cout << "Non-terminals:\n";
    for(auto & nonTerminal : nonTerminals) {
        std::cout << nonTerminal << '\n';
    }
    std::cout << '\n';

    std::cout << "Productions:" << '\n';
    for(const auto& prodPair: prods) {
        for(const auto& prod: prodPair.second) {
            std::cout << prod.getNonTerminal() << " -> ";
            auto resultList = prod.getResultList();

            for (const auto &res: resultList) {
                std::cout << res << " ";
            }
            std::cout << '\n';
        }
    }

    return 0;
}
