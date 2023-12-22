#pragma once
#include "GaleShapely.hpp"



class HamiltonPathStableMarriage{

    HamiltonPathStableMarriage();
    ~HamiltonPathStableMarriage();




    private:

        A *setA[NUMBER_OF_PREFERENCES];
        B *setB[NUMBER_OF_PREFERENCES];

        //The i'th index of A would correspond i'th element of setA and the 
        //integer stored their would be who they are 'matched' with
        int matchingsAtoB[NUMBER_OF_PREFERENCES];
        int matchingsBtoA[NUMBER_OF_PREFERENCES];


};
