#include "linked_list.h"

using namespace rms;

linked_list::linked_list(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    m_length = 1;
}

void linked_list::append(int value)
{
    Node* node = head;
    while(node->nextNode != nullptr)
    {
        node = node->nextNode;
    }

    node->nextNode = new Node(value);
    tail = node->nextNode;
    m_length++;
}

void linked_list::prepend(int value)
{

}

void linked_list::insert(int index, int value)
{

}

const int linked_list::length()
{
    return m_length;
}

auto linked_list::get_head() -> const Node*
{
    return head;
}

auto linked_list::get_tail() -> const Node*
{
    return tail;
}
