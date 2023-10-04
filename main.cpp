#include "libraries/hash_table/hash_table.h"
#include <iostream>

using namespace rsm;

int main()
{
    hash_table* hashTable = new hash_table();

    std::cout << hashTable->hash("pentagon") << std::endl;

    return 0;
}
