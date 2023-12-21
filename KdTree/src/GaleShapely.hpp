#pragma once

#ifndef NUMBER_OF_PREFERENCES

    #define NUMBER_OF_PREFERENCES 10

#endif

template <size_t T>
class A
{

    public:
        A();
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
class GaleShapelyAlgorithm
{
    public:
        GaleShapelyAlgorithm();
        ~GaleShapelyAlgorithm();

    

        A<T> *setA[T];
        B<T> *setB[T];
};
