#include "HamiltonPath.hpp"



void HamiltonPathStableMarriage::match(){
    
}


HamiltonPathStableMarriage::HamiltonPathStableMarriage(){

    for(int i = 0 ; i < NUMBER_OF_PREFERENCES; i++){
        this->setA[i]= new A();
        this->setB[i]= new B();

        this->matchingsAtoB[i]= -1;
        this->matchingsBtoA[i]= -1;
    }

}

HamiltonPathStableMarriage::~HamiltonPathStableMarriage(){
    

    for( int i =0 ; i < NUMBER_OF_PREFERENCES; i++){
        delete this->setA[i];
        delete this->setB[i];
    }

}



