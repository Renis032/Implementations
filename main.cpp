#include "libraries/vector/vector.h"
#include <iostream>

int main()
{
    rsm::vector vec;

    vec.reserve(80);

    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Size: " << vec.size() << std::endl;


    return 0;
}
