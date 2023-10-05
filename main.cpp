#include "libraries/graph/graph.h"

#include <iostream>

using namespace rsm;

int main()
{
    graph* graph = new class graph();

    graph->addVertex("A");
    graph->addVertex("B");
    graph->addVertex("C");

    graph->addEdge("A", "B");
    graph->addEdge("A", "C");
    graph->addEdge("B", "C");

    graph->removeVertex("A");

    graph->printGraph();
    return 0;
}
