#include <iostream>
#include "libraries/DataStructures/priority_queue/priority_queue.h"

int main()
{
    rsm::priority_queue<int> queue(5, 7);
    queue.push(1, 13);
    queue.push(11, 1);
    queue.push(19, 9);
    queue.print_queue();

    std::cout << "--------" << std::endl;

    queue.dequeue();
    queue.print_queue();


    return 0;
}
