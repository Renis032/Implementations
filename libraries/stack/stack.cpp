#include "stack.h"

using namespace rsm;

stack::stack(int value)
{
    Node* newNode = new Node(value);
    m_top = newNode;
    m_height = 1;
}

auto stack::get_top() -> Node*
{
    return m_top;
}

auto stack::height() -> const int
{
    return m_height;
}
