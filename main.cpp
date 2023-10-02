#include "libraries/stack/stack.h"
#include <iostream>

int main()
{
    rsm::stack stack(4);

    std::cout << stack.get_top()->value << std::endl;
    std::cout << stack.height() << std::endl;

    return 0;
}
