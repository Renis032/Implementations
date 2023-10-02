#include "stack.h"
#include <stdexcept>

using namespace rsm;

stack::stack(int value)
{
    Node* newNode = new Node(value);
    m_top = newNode;
    m_height = 1;
}

void stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->nextNode = m_top;
    m_top = newNode;

    m_height++;
}

void stack::pop()
{
    if(m_height == 0)
    {
        throw std::invalid_argument("No elements to pop");
    }

    Node* temp = m_top;
    m_top = temp->nextNode;
    delete temp;

    m_height--;
}

auto stack::get_top() -> Node*
{
    return m_top;
}

auto stack::height() -> const int
{
    return m_height;
}
