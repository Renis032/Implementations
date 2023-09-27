#include "linked_list.h"

using namespace rsm;

linked_list::linked_list(int value)
{
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    m_length = 1;
}

linked_list::~linked_list()
{
    Node* temp = head;
    while(head)
    {
        head = temp->nextNode;
        delete temp;
        temp = head;
    }
}

void linked_list::append(int value)
{
    Node* newNode = new Node(value);

    if(m_length == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextNode = newNode;
        tail = newNode;
    }

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
