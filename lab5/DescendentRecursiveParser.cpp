//
// Created by radoo on 12.12.2022.
//

#include "DescendentRecursiveParser.h"

void DescendentRecursiveParser::expand(Configuration &config, Grammar grammar,
                                       const std::vector<std::string> &input) {
    if (!grammar.isTerminal(config.inputStack.top())) {
        std::string A = config.inputStack.top();
        config.inputStack.pop();

        config.workingStack.push(std::make_pair(A, 0));

        auto Ai = grammar.getProductions();
        auto y1 = Ai[A][0];

        for (int i = y1.getResultList().size() - 1; i >= 0; i--) {
            config.inputStack.push(y1.getResultList()[i]);
        }
    }
}

void DescendentRecursiveParser::advance(Configuration &config, const Grammar &grammar,
                                        const std::vector<std::string> &input) {
    if (config.inputStack.top() == input[config.i]) {
        std::string terminal = config.inputStack.top();
        config.inputStack.pop();
        config.workingStack.push(std::make_pair(terminal, 0));
        config.i++;
    }
}

void DescendentRecursiveParser::momentary_insuccess(Configuration &config, Grammar grammar,
                                                    const std::vector<std::string> &input) {
    if (grammar.isTerminal(config.inputStack.top()) && config.inputStack.top() != input[config.i]) {
        config.state = BACK;
    }
}

void
DescendentRecursiveParser::back(Configuration &config, Grammar grammar, const std::vector<std::string> &input) {
    if (grammar.isTerminal(config.workingStack.top().first)) {
        std::string a = config.workingStack.top().first;
        config.workingStack.pop();

        config.i--;
        config.inputStack.push(a);
    }
}

void DescendentRecursiveParser::another_try(Configuration &config, Grammar grammar,
                                            const std::vector<std::string> &input) {
    if (!grammar.isTerminal(config.workingStack.top().first)) {
        auto prods = grammar.getProductions();
        auto Aj = config.workingStack.top();
        config.workingStack.pop();

        if (Aj.second < prods[Aj.first].size() - 1) {
            config.state = NORMAL;
            config.workingStack.push(std::make_pair(Aj.first, Aj.second + 1));

            for (int i = 0; i < prods[Aj.first][Aj.second].getResultList().size(); i++) {
                config.inputStack.pop();
            }

            auto Aj1prods = prods[Aj.first][Aj.second + 1].getResultList();

            for (int i = Aj1prods.size() - 1; i >= 0; i--) {
                config.inputStack.push(Aj1prods[i]);
            }
        } else if (config.i != 0) {
            for (int i = 0; i < prods[Aj.first][Aj.second].getResultList().size(); i++) {
                config.inputStack.pop();
            }

            config.inputStack.push(Aj.first);
        } else {
            config.state = ERROR;
        }
    }
}

void DescendentRecursiveParser::success(Configuration &config, const Grammar &grammar,
                                        const std::vector<std::string> &input) {
    if (config.i == input.size() && config.inputStack.empty()) {
        config.state = FINAL;
    }
}

void DescendentRecursiveParser::parse(Configuration &config, Grammar &grammar, std::vector<std::string> &input) {
    while (config.state != FINAL && config.state != ERROR) {
        if (config.state == NORMAL) {
            if (config.i == input.size() && config.inputStack.empty()) {
                success(config, grammar, input);
            } else if (!grammar.isTerminal(config.inputStack.top())) {
                expand(config, grammar, input);
            } else if (config.inputStack.top() == input[config.i]) {
                advance(config, grammar, input);
            } else momentary_insuccess(config, grammar, input);
        } else if (config.state == BACK) {
            if(grammar.isTerminal(config.workingStack.top().first)) {
                back(config, grammar, input);
            } else {
                another_try(config, grammar, input);
            }
        }
    }

    if(config.state == ERROR) {
        std::cout << "Error";
    } else {
        std::cout << "Sequence accepted";
    }
}

