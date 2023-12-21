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

    for (int i = 0; i < T; i++)
    {
        this->inverse_preferences[this->preferences[i]] = i;
    }
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
    for (int i = 0; i < T; i++)
    {
        this->inverse_preferences[this->preferences[i]] = i;
    }
}
template class B<NUMBER_OF_PREFERENCES>;

template <size_t T>
void Stack<T>::push(int index)
{
    this->index_of_unmatched[this->top] = index;
    this->top++;
}

template <size_t T>
int Stack<T>::pop()
{
    this->top--;
    return this->index_of_unmatched[this->top];
}

template <size_t T>
int Stack<T>::getSize()
{
    return this->top;
}

template class Stack<NUMBER_OF_PREFERENCES>;

template <size_t T>
GaleShapelyAlgorithm<T>::GaleShapelyAlgorithm()
{
    for (int i = 0; i < T; i++)
    {
        this->setA[i] = new A<T>();
        this->setB[i] = new B<T>();
        this->unmatched.push(i);
        this->matchingsAtoB[i] = -1;
        this->matchingsBtoA[i] = -1;
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

template <size_t T>
void GaleShapelyAlgorithm<T>::match()
{

    while (this->unmatched.getSize() != 0)
    {
        int a = this->unmatched.pop();
        int b = this->setA[a]->preferences[this->setA[a]->last_chosen++];
        if (this->matchingsBtoA[b] == -1)
        {
            this->matchingsAtoB[a] = b;
            this->matchingsBtoA[b] = a;
        }
        else // some other pair exists
        {
            if (this->setB[b]->inverse_preferences[a] > this->setB[b]->inverse_preferences[this->matchingsBtoA[b]]) // if b prefers a to its current match
            {
                this->unmatched.push(this->matchingsBtoA[b]);
                this->matchingsAtoB[a] = b;
                this->matchingsBtoA[b] = a;
                
            }
            else
            {
                this->unmatched.push(a);
            }
        }
    }
}

template class GaleShapelyAlgorithm<NUMBER_OF_PREFERENCES>;