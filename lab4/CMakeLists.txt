cmake_minimum_required(VERSION 3.23)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp FiniteAutomaton/FiniteAutomaton.cpp FiniteAutomaton/FiniteAutomaton.h Transition/Transition.cpp Transition/Transition.h Console/Console.cpp Console/Console.h)
