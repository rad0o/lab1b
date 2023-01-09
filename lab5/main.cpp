#include <iostream>
#include "Grammar.h"
#include "Tests/Tests.h"
#include "Production.h"

void read_input(const std::string& filename, std::vector<std::string>& a) {
    std::ifstream file;
    file.open(filename);

    std::string line;

    std::map<std::string, bool> isTerminal;

    while (std::getline(file, line, '\n')) {
        if (!line.empty()) {
            a.push_back(line);
        }
    }

    file.close();
}

int main() {
    Tests::testAll();

    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;

    std::stack<std::string> input_stack;
    input_stack.push("S");

    std::vector<std::string> input;

    read_input("seq.txt", input);

    Configuration configuration(NORMAL, 0, working_stack, input_stack);

    std::string parsing_result = DescendentRecursiveParser::parse(configuration, grammar, input);

    if(parsing_result == "ERROR") {
        std::cout << "Error";
    } else {
        std::cout << "Sequence accepted:\n";
        std::cout << DescendentRecursiveParser::build_string_of_productions(configuration, grammar);
    }

    return 0;
}
