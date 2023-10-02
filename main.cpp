#include "libraries/vector/vector.h"
#include "libraries/linked_list/linked_list.h"
#include <iostream>

void printListInfo(rsm::linked_list& linkedList)
{
    auto head = linkedList.get_head();
    if(head != nullptr)
    {
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

}

int main()
{
    rsm::linked_list linkedList1(1);
    linkedList1.append(11);
    linkedList1.append(111);

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "First List: " << std::endl;
    linkedList1.delete_first();
    linkedList1.reverse();
    printListInfo(linkedList1);

    return 0;
}
