#include "queue.h"
#include <stdexcept>

using namespace rsm;

queue::queue(int value)
{
    Node* newNode = new Node(value);
    m_first = newNode;
    m_last = newNode;
    m_length = 1;
}

void queue::enqueue(int value)
{
    Node* newNode = new Node(value);
    if(m_length == 0)
    {
        m_first = newNode;
        m_last = newNode;
    }
    else
    {
        m_last->nextNode = newNode;
        m_last = newNode;
    }

    m_length++;
}

void queue::dequeue()
{
    if(m_length == 0)
    {
        throw std::invalid_argument("No elements to dequeue");
    }
    if(m_length == 1)
    {
        m_first = nullptr;
        m_last = nullptr;
        return;
    }

    Node* firstNode = get_first();
    m_first = firstNode->nextNode;
    delete firstNode;

    m_length--;
}

auto queue::get_first() -> Node*
{
    return m_first;
}

auto queue::get_last() -> Node*
{
    return m_last;
}

auto queue::get_length() -> const int
{
    return m_length;
}
