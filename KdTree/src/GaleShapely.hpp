#pragma once
#include <cstddef>

#ifndef NUMBER_OF_PREFERENCES

#define NUMBER_OF_PREFERENCES 10

#endif


class A
{

public:
    A();
    int last_chosen = -1;
    int preferences[NUMBER_OF_PREFERENCES];
    int inverse_preferences[NUMBER_OF_PREFERENCES];
};


class B
{

public:
    B();
    int preferences[NUMBER_OF_PREFERENCES];
    int inverse_preferences[NUMBER_OF_PREFERENCES];
};


class Stack
{
public:
    void push(int index);
    int pop();
    int getSize();

private:
    int index_of_unmatched[NUMBER_OF_PREFERENCES];
    int top = 0;
};


class GaleShapelyAlgorithm
{
public:
    GaleShapelyAlgorithm();

    void match();

    void print_matchings();
    A *getA(int index);
    B *getB(int index);


    bool all_matchings_stable();

    ~GaleShapelyAlgorithm();

private:
    A *setA[NUMBER_OF_PREFERENCES];
    B *setB[NUMBER_OF_PREFERENCES];

    // Denotes a matching from A to B where
    // The index of the array 'matching' denotes the A'th person is matched to the B'th person
    // they are bidirectionally matched
    int matchingsAtoB[NUMBER_OF_PREFERENCES];
    int matchingsBtoA[NUMBER_OF_PREFERENCES];

    Stack unmatched;
};