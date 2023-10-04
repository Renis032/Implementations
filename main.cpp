#include "libraries/vector/vector.h"
#include <iostream>

using namespace rsm;

int main()
{
    vector<std::string> vec1;
    vec1.push_back("1");

    vector<std::string> vec2;
    vec2.push_back("2");

    std::cout << (vec1 == vec2) << std::endl;

    return 0;
}
