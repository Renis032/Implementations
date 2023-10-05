#include"graph.h"
#include <iostream>

using namespace rsm;

void graph::printGraph()
{
    for(auto [vertex, edges] : m_adjList)
    {
        std::cout << vertex << ": [";
        for(auto edge : edges)
        {
            std::cout << edge << " ";
        }
        std::cout << "]" << std::endl;
    }
}

void graph::addVertex(std::string vertex)
{
    if(m_adjList.count(vertex) == 0)
    {
        m_adjList[vertex];
    }
}

void graph::addEdge(std::string vertex1, std::string vertex2)
{
    if(m_adjList.count(vertex1) == 0 || m_adjList.count(vertex2) == 0)
    {
        return;
    }

    m_adjList.at(vertex1).insert(vertex2);
    m_adjList.at(vertex2).insert(vertex1);
}
