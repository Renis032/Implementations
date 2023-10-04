#include "libraries/binary_search_tree/binary_search_tree.h"
#include <iostream>

int main()
{
    rsm::binary_search_tree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(1);
    tree.insert(7);
    tree.insert(10);
    tree.insert(11);

    std::cout << tree.contains(2) << std::endl;

    return 0;
}
