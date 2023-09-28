#include "libraries/vector/vector.h"
#include "libraries/linked_list/linked_list.h"
#include <iostream>

//void printListInfo(rsm::linked_list& linkedList)
//{
//    auto head = linkedList.get_head();
//    if(head != nullptr)
//    {
//        std::cout << "HEAD'S VALUE: " << head->value << std::endl;
//        auto tempNode = head->nextNode;
//        while(tempNode != nullptr)
//        {
//            if(tempNode->nextNode == nullptr)
//            {
//                std::cout << "TAIL'S VALUE: ";
//            }
//            std::cout << tempNode->value << std::endl;
//            tempNode = tempNode->nextNode;
//        }
//    }

//    std::cout << "LENGTH: " << linkedList.length() << std::endl;
//}

int main()
{
    rsm::vector vec1;

    vec1.push_back(1);
    vec1.push_back(1);
    vec1.push_back(1);
    vec1.push_back(1);
    vec1.push_back(1);


    rsm::vector vec2;

    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);

    vec1 = vec2;


    for(int i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << std::endl;
    }

    return 0;
}
