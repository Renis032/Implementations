#include"graph.h"
#include <iostream>

namespace rsm 
{

void graph::printGraph()
{
    for(auto [vertex, edges] : m_adjList)
    {
        std::cout << vertex << ": [ ";
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

void graph::removeVertex(std::string vertex)
{
    if(m_adjList.count(vertex) == 0)
    {
        return;
    }
    for(auto otherVertex : m_adjList[vertex])
    {
        m_adjList.at(otherVertex).erase(vertex);
    }

    m_adjList.erase(vertex);
}

void graph::removeEdge(std::string vertex1, std::string vertex2)
{
    if(m_adjList.count(vertex1) == 0 || m_adjList.count(vertex2) == 0)
    {
        return;
    }

    m_adjList.at(vertex1).erase(vertex2);
    m_adjList.at(vertex2).erase(vertex1);
}

} // end of namespace rsm