#include <iostream>
#include "libraries/DataStructures/priority_queue/priority_queue.h"

int main()
{
    rsm::priority_queue<int> queue(5, 7);
    queue.push(1, 11);
    queue.push(11, 11);
    queue.push(19, 11);
    queue.print_queue();


    return 0;
}
