#include <iostream>
#include "libraries/DataStructures/binary_tree/binary_tree.h"

int main()
{
    rsm::binary_tree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(17);
    tree.insert(10);
    tree.insert(8);

    tree.printDFS(tree.get_root());
    std::cout << std::endl;
    tree.printBFS(tree.get_root());

    return 0;
}
