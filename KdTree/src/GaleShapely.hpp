#pragma once
#include <cstddef>

#ifndef NUMBER_OF_PREFERENCES

    #define NUMBER_OF_PREFERENCES 10

#endif

template <size_t T>
class A
{

    public:
        A();
        int last_chosen=-1;
        int preferences[T];
};

template <size_t T>
class B
{

    public:
        B();
        int preferences[T];
};

template <size_t T>
class Stack_of_A
{
    public:
        void push(int index);
        int pop();
        int getSize();

    private:
        int index_of_unmatched[T];
        int top=0;
};




template <size_t T>
class GaleShapelyAlgorithm
{
    public:
        GaleShapelyAlgorithm();
        ~GaleShapelyAlgorithm();

    
    private:
        A<T> *setA[T];
        B<T> *setB[T];
        Stack_of_A<T> stack_of_A;
};
