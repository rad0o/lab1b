//
// Created by radoo on 12.12.2022.
//

#include "Tests.h"

void Tests::testAll() {
    Tests::testExpand();
    Tests::testAdvance();
    Tests::testMomentaryInsuccess();
    Tests::testBack();
    Tests::testAnotherTry1();
    Tests::testAnotherTry2();
    Tests::testAnotherTry3();
    Tests::testSuccess();
}

void Tests::testExpand() {
    // given: (q, 0, {}, {S})
    // expected: (q, 0, {S0}, {a, S, b, S})

    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;

    std::stack<std::string> input_stack;
    input_stack.push("S");

    std::vector<std::string> input;
    input.push_back("c");

    Configuration configuration(NORMAL, 0, working_stack, input_stack);


    DescendentRecursiveParser::expand(configuration, grammar, input);

    auto S0 = configuration.workingStack.top();

    assert(S0.first == "S" && S0.second == 0);

    assert(configuration.inputStack.top() == "a");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "b");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.empty());
}

void Tests::testAdvance() {
    // given: (q, 0, {S0}, {a, S, b, S}), input: {a, c}
    // expected: (q, 1, {S0, a}, {S, b, S}), input: {a, c}

    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("S", 0));

    std::stack<std::string> input_stack;
    input_stack.push("S");
    input_stack.push("b");
    input_stack.push("S");
    input_stack.push("a");

    std::vector<std::string> input;
    input.push_back("a");
    input.push_back("c");

    Configuration configuration(NORMAL, 0, working_stack, input_stack);

    DescendentRecursiveParser::advance(configuration, grammar, input);

    assert(configuration.workingStack.top().first == "a");
    configuration.workingStack.pop();
    assert(configuration.workingStack.top().first == "S");
    assert(configuration.workingStack.top().second == 0);
    configuration.workingStack.pop();
    assert(configuration.workingStack.empty());
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "b");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.empty());
}

void Tests::testMomentaryInsuccess() {
    // given: (q, 0, {S0}, {a, S, b, S}), input: {c}
    // expected: (b, 1, {S0}, {a, S, b, S}), input: {c}
    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("S", 0));

    std::stack<std::string> input_stack;
    input_stack.push("S");
    input_stack.push("b");
    input_stack.push("S");
    input_stack.push("a");

    std::vector<std::string> input;
    input.push_back("c");

    Configuration configuration(NORMAL, 0, working_stack, input_stack);

    DescendentRecursiveParser::momentary_insuccess(configuration, grammar, input);

    assert(configuration.state == BACK);
}

void Tests::testBack() {
    // given: (b, 1, {S0, a}, {S, b, S}), input: {a, c}
    // expected: (b, 0, {S0}, {a, S, b, S})
    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("S", 0));
    working_stack.push(std::make_pair("a", 0));

    std::stack<std::string> input_stack;
    input_stack.push("S");
    input_stack.push("b");
    input_stack.push("S");

    std::vector<std::string> input;
    input.push_back("a");
    input.push_back("c");

    Configuration configuration(BACK, 1, working_stack, input_stack);

    DescendentRecursiveParser::back(configuration, grammar, input);

    assert(configuration.i == 0);
    assert(configuration.workingStack.top().first == "S");
    assert(configuration.workingStack.top().second == 0);
    configuration.workingStack.pop();
    assert(configuration.workingStack.empty());
    assert(configuration.inputStack.top() == "a");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "b");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.empty());
}

void Tests::testAnotherTry1() {
    // given: (b, 1, {S0}, {a, S, b, S, c}), input: {c}
    // expected: (q, 1, {S1}, {a, S, c})
    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("S", 0));

    std::stack<std::string> input_stack;
    input_stack.push("c");
    input_stack.push("S");
    input_stack.push("b");
    input_stack.push("S");
    input_stack.push("a");

    std::vector<std::string> input;
    input.push_back("c");

    Configuration configuration(BACK, 1, working_stack, input_stack);

    DescendentRecursiveParser::another_try(configuration, grammar, input);

    assert(configuration.state == NORMAL);
    assert(configuration.i == 1);
    assert(configuration.workingStack.top().first == "S");
    assert(configuration.workingStack.top().second == 1);
    configuration.workingStack.pop();
    assert(configuration.workingStack.empty());
    assert(configuration.inputStack.top() == "a");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.top() == "c");
    configuration.inputStack.pop();
    assert(configuration.inputStack.empty());
}

void Tests::testAnotherTry2() {
    // given: (b, 1, {c, S2}, {c}), input: {c}
    // expected: (b, 1, {c}, {S})
    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("c", 0));
    working_stack.push(std::make_pair("S", 2));

    std::stack<std::string> input_stack;
    input_stack.push("c");

    std::vector<std::string> input;
    input.push_back("c");

    Configuration configuration(BACK, 1, working_stack, input_stack);

    DescendentRecursiveParser::another_try(configuration, grammar, input);

    assert(configuration.state == BACK);
    assert(configuration.i == 1);
    assert(configuration.workingStack.top().first == "c");
    configuration.workingStack.pop();
    assert(configuration.workingStack.empty());
    assert(configuration.inputStack.top() == "S");
    configuration.inputStack.pop();
    assert(configuration.inputStack.empty());
}

void Tests::testAnotherTry3() {
    // given: (b, 0, {c, S2}, {c}), input: {c}
    // expected: (e, 0, {c, S2}, {c}), input: {c}

    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("c", 0));
    working_stack.push(std::make_pair("S", 2));

    std::stack<std::string> input_stack;
    input_stack.push("c");

    std::vector<std::string> input;
    input.push_back("c");

    Configuration configuration(BACK, 0, working_stack, input_stack);

    DescendentRecursiveParser::another_try(configuration, grammar, input);

    assert(configuration.state == ERROR);
}

void Tests::testSuccess() {
    // given: (b, 2, {c, S2}, {}), input: {c, a}
    // expected: (f, 2, {c, S2}, {})

    std::string fname = "g1.txt";
    Grammar grammar;
    grammar.readFromFile(fname);

    std::stack<std::pair<std::string, int>> working_stack;
    working_stack.push(std::make_pair("c", 0));
    working_stack.push(std::make_pair("S", 2));

    std::stack<std::string> input_stack;

    std::vector<std::string> input;
    input.push_back("c");
    input.push_back("a");

    Configuration configuration(BACK, 2, working_stack, input_stack);

    DescendentRecursiveParser::success(configuration, grammar, input);

    assert(configuration.state == FINAL);
}
