#include "GaleShapely.hpp"
#include <algorithm>
#include <random>
#include <iostream>

A::A()
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->preferences[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(this->preferences, this->preferences + NUMBER_OF_PREFERENCES, g);

    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->inverse_preferences[this->preferences[i]] = i;
    }
}

B::B()
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->preferences[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(this->preferences, this->preferences + NUMBER_OF_PREFERENCES, g);
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->inverse_preferences[this->preferences[i]] = i;
    }
}

void Stack::push(int index)
{
    this->index_of_unmatched[this->top] = index;
    this->top++;
}

int Stack::pop()
{
    this->top--;
    return this->index_of_unmatched[this->top];
}

int Stack::getSize()
{
    return this->top;
}

GaleShapelyAlgorithm::GaleShapelyAlgorithm()
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->setA[i] = new A();
        this->setB[i] = new B();
        this->unmatched.push(i);
        this->matchingsAtoB[i] = -1;
        this->matchingsBtoA[i] = -1;
    }
}

GaleShapelyAlgorithm::~GaleShapelyAlgorithm()
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        delete this->setA[i];
        delete this->setB[i];
    }
}

void GaleShapelyAlgorithm::match()
{
    int iterations = 0;
    while (this->unmatched.getSize() != 0)
    {
        iterations++;
        int a = this->unmatched.pop();
        int b = this->setA[a]->preferences[this->setA[a]->last_chosen++];
        if (this->matchingsBtoA[b] == -1)
        {
            this->matchingsAtoB[a] = b;
            this->matchingsBtoA[b] = a;
        }
        else // some other pair exists
        {
            // if b prefers a to its current match
            if (this->setB[b]->inverse_preferences[a] > this->setB[b]->inverse_preferences[this->matchingsBtoA[b]])
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
    std::cout << "iterations: " << iterations << std::endl;
}

void GaleShapelyAlgorithm::print_matchings()
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        std::cout << i << " " << this->matchingsAtoB[i] << std::endl;
    }
}

bool GaleShapelyAlgorithm::all_matchings_stable()
{
    for (int b = 0; b < NUMBER_OF_PREFERENCES; ++b)
    {
        int a = this->matchingsBtoA[b];
        if (a != -1)
        {
            
            for (int i = 0; i < NUMBER_OF_PREFERENCES; ++i)
            {
                int a_prime = this->matchingsBtoA[b];
                int b_prime = this->matchingsAtoB[a_prime];

                if (this->setA[a_prime]->inverse_preferences[b] > this->setA[a_prime]->inverse_preferences[b_prime] &&
                    this->setB[b]->inverse_preferences[a] > this->setB[b]->inverse_preferences[a_prime])
                {
                    return false;
                }
            }
        }
    }
    return true;
}


A *GaleShapelyAlgorithm::getA(int index)
{
    return this->setA[index];
}

B *GaleShapelyAlgorithm::getB(int index)
{
    return this->setB[index];
}
