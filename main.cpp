#include "libraries/vector/vector.h"
#include "libraries/linked_list/linked_list.h"
#include <iostream>

void printListInfo(rsm::linked_list& linkedList)
{
    auto head = linkedList.get_head();
    if(head != nullptr)
    {
        std::cout << "HEAD'S VALUE: " << head->value << std::endl;
        auto tempNode = head->nextNode;
        while(tempNode != nullptr)
        {
            if(tempNode->nextNode == nullptr)
            {
                std::cout << "TAIL'S VALUE: ";
            }
            std::cout << tempNode->value << std::endl;
            tempNode = tempNode->nextNode;
        }
    }

    std::cout << "LENGTH: " << linkedList.length() << std::endl;
}

int main()
{
    rsm::linked_list* linkedList = new rsm::linked_list(4);

    linkedList->append(1);
    linkedList->append(2);
    linkedList->append(3);
    linkedList->append(4);
    linkedList->append(5);

    printListInfo(*linkedList);

    delete linkedList;

    return 0;
}
