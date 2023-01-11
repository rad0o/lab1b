//
// Created by radoo on 12.12.2022.
//

#ifndef LAB5_TESTS_H
#define LAB5_TESTS_H

#include "../Configuration.h"
#include "../DescendentRecursiveParser.h"
#include "../Grammar.h"
#include "../Production.h"

class Tests {
public:
    static void testAll();
    static void testExpand();
    static void testAdvance();
    static void testMomentaryInsuccess();
    static void testBack();
    static void testAnotherTry1();
    static void testAnotherTry2();
    static void testAnotherTry3();
    static void testSuccess();
};


#endif //LAB5_TESTS_H
