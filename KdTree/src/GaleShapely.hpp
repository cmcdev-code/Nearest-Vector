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
        int inverse_preferences[T];
};

template <size_t T>
class B
{

    public:
        B();
        int preferences[T];
        int inverse_preferences[T];
};

template <size_t T>
class Stack
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

        void match();

        void print_matchings();

        ~GaleShapelyAlgorithm();
    
    private:
        A<T> *setA[T];
        B<T> *setB[T];

        //Denotes a matching from A to B where 
        //The index of the array 'matching' denotes the A'th person is matched to the B'th person
        //they are bidirectionally matched
        int matchingsAtoB[T];
        int matchingsBtoA[T];

        Stack<T> unmatched;

};