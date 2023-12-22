#include "HamiltonPath.hpp"

void HamiltonPathStableMarriage::match()
{

    int previously_visited_nodes_A[NUMBER_OF_PREFERENCES];
    int previously_visited_nodes_B[NUMBER_OF_PREFERENCES];

    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        previously_visited_nodes_A[i] = 0;
        previously_visited_nodes_B[i] = 0;
    }
    while (this->number_of_matchings < NUMBER_OF_PREFERENCES)
    {
        
    }
}









HamiltonPathStableMarriage::HamiltonPathStableMarriage()
{

    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        this->setA[i] = new A();
        this->setB[i] = new B();

        this->matchingsAtoB[i] = -1;
        this->matchingsBtoA[i] = -1;
    }
}

HamiltonPathStableMarriage::~HamiltonPathStableMarriage()
{

    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        delete this->setA[i];
        delete this->setB[i];
    }
}
