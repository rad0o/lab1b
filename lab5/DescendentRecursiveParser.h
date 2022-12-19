//
// Created by radoo on 12.12.2022.
//

#ifndef LAB5_DESCENDENTRECURSIVEPARSER_H
#define LAB5_DESCENDENTRECURSIVEPARSER_H

#include <vector>
#include <string>
#include "Grammar.h"
#include "Configuration.h"

class DescendentRecursiveParser {
public:
    static void expand(Configuration& config, Grammar grammar, const std::vector<std::string>& input);
    static void advance(Configuration& config, const Grammar& grammar, const std::vector<std::string>& input);
    static void momentary_insuccess(Configuration& config, Grammar grammar, const std::vector<std::string>& input);
    static void back(Configuration& config, Grammar grammar, const std::vector<std::string>& input);
    static void another_try(Configuration& config, Grammar grammar, const std::vector<std::string>& input);
    static void success(Configuration& config, const Grammar& grammar, const std::vector<std::string>& input);
    static void parse(Configuration& config, Grammar& grammar, std::vector<std::string>& input);
};


#endif //LAB5_DESCENDENTRECURSIVEPARSER_H
