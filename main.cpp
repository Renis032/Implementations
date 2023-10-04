#include "libraries/hash_table/hash_table.h"
#include <iostream>

using namespace rsm;

int main()
{
    hash_table* hashTable = new hash_table();

    hashTable->set("nails", 100);
    hashTable->set("tile", 50);
    hashTable->set("lumber", 80);

    std::cout << "Lumber: " << hashTable->value("lumber") << std::endl;
    std::cout << "Something: " << hashTable->value("something") << std::endl;

    return 0;
}
