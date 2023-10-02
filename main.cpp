#include "libraries/doubly_linked_list/doubly_linked_list.h"
#include <iostream>

void printListInfo(rsm::doubly_linked_list& linkedList)
{
    auto head = linkedList.get_head();
    if(nullptr == head)
    {
        std::cout << "NO HEAD FOUND!" << std::endl;
    }

    std::cout << "HEAD'S VALUE: " << head->value << std::endl;

    auto tail = linkedList.get_tail();
    std::cout << "TAIL'S VALUE: " << tail->value << std::endl;

    std::cout << "LENGTH: " << linkedList.length() << std::endl;

    std::cout << "All linked list's values: "<< std::endl;
    auto tempNode = head;
    while(tempNode != nullptr)
    {
        std::cout << tempNode->value << std::endl;
        tempNode = tempNode->nextNode;
    }
}

int main()
{
    rsm::doubly_linked_list list(1);
    list.append(2);
    list.append(3);
    list.prepend(10);

    list.delete_node(0);
    list.delete_node(0);
    list.delete_node(0);

    printListInfo(list);

//    std::cout << list.get(4)->prevNode->value << std::endl;
    return 0;
}
