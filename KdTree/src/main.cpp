#include "GaleShapely.hpp"
#include <iostream>



void print_preferences(GaleShapelyAlgorithm &testing)
{
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        std::cout << "A" << i << ": ";
        for (int j = 0; j < NUMBER_OF_PREFERENCES; j++)
        {
            std::cout << testing.getA(i)->preferences[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < NUMBER_OF_PREFERENCES; i++)
    {
        std::cout << "B" << i << ": ";
        for (int j = 0; j < NUMBER_OF_PREFERENCES; j++)
        {
            std::cout << testing.getB(i)->preferences[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int main()
{

    GaleShapelyAlgorithm testing;
    testing.match();

    print_preferences(testing);
    std::cout << "All matchings stable: " << (testing.all_matchings_stable()? "true":"false" )<< std::endl;
    testing.print_matchings();

    return 0;
}
