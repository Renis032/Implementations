#include "libraries/stack/stack.h"
#include <iostream>

void printStack(rsm::stack& stack)
{
    auto top = stack.get_top();
    while(top)
    {
        std::cout << top->value << std::endl;
        top = top->nextNode;
    }
}

int main()
{
    rsm::stack stack(4);
    stack.push(10);

    printStack(stack);

    return 0;
}
