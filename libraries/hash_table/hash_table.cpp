#include "hash_table.h"
#include <iostream>

using namespace rsm;

void hash_table::print_map()
{
    for(int i = 0; i < size(); i++)
    {
        std::cout << i << ":" << std::endl;
        if(m_dataMap[i])
        {
            Node* temp = m_dataMap[i];
            while(temp)
            {
                std::cout << "  {" << temp->key << ", " << temp->value << "}" << std::endl;
                temp = temp->nextNode;
            }
        }
    }
}

auto hash_table::get_data_map() -> Node*
{
    return *m_dataMap;
}

auto hash_table::size() -> const int
{
    return m_size;
}
