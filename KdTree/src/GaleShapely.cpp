#include "GaleShapely.hpp"
#include <algorithm>
#include <random>

template <size_t T>
A<T>::A()
{
    for (int i = 0; i < T; i++)
    {
        this->preferences[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(this->preferences, this->preferences + T, g);
}
template class A<NUMBER_OF_PREFERENCES>;

template <size_t T>
B<T>::B()
{
    for (int i = 0; i < T; i++)
    {
        this->preferences[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(this->preferences, this->preferences + T, g);
}
template class B<NUMBER_OF_PREFERENCES>;

template <size_t T>
GaleShapelyAlgorithm<T>::GaleShapelyAlgorithm()
{
    for (int i = 0; i < T; i++)
    {
        this->setA[i] = new A<T>();
        this->setB[i] = new B<T>();
    }
}

template <size_t T>
GaleShapelyAlgorithm<T>::~GaleShapelyAlgorithm()
{
    for (int i = 0; i < T; i++)
    {
        delete this->setA[i];
        delete this->setB[i];
    }
}

template class GaleShapelyAlgorithm<NUMBER_OF_PREFERENCES>;