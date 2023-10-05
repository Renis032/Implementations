#include "libraries/graph/graph.h"

#include <iostream>

using namespace rsm;

int main()
{
    graph* graph = new class graph();

    graph->addVertex("A");
    graph->addVertex("B");

    graph->addEdge("A", "B");

    graph->printGraph();
    return 0;
}
