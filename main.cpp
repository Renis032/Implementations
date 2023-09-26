#include "libraries/vector.h"
#include <iostream>

int main()
{
    rsm::vector vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(500);
    vec.push_back(1000);
    vec.push_back(2000);
    vec.push_back(3000);
    vec.push_back(4000);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << std::endl;
    }

    return 0;
}
