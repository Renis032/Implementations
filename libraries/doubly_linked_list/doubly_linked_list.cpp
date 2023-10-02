#include "doubly_linked_list.h"
#include <stdexcept>

using namespace rsm;

doubly_linked_list::doubly_linked_list(int value)
{
    Node* node = new Node(value);
    m_head = node;
    m_tail = node;
    m_length = 1;
}

void doubly_linked_list::append(int value)
{
    Node* newNode = new Node(value);

    if(m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        m_tail->nextNode = newNode;
        newNode->prevNode = m_tail;
        m_tail = newNode;
    }

    m_length++;
}

void doubly_linked_list::prepend(int value)
{
    Node* newNode = new Node(value);

    if(m_length == 0)
    {
        m_head = newNode;
        m_tail = newNode;
    }
    else
    {
        newNode->nextNode = m_head;
        m_head->prevNode = newNode;
        m_head = newNode;
    }

    m_length++;
}

void doubly_linked_list::delete_first()
{
    if(m_length == 0)
    {
        return;
    }
    if(m_length == 1)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        Node* temp = m_head;
        m_head = m_head->nextNode;
        m_head->prevNode = nullptr;

        delete temp;
    }
}

void doubly_linked_list::delete_last()
{
    if(m_length == 0)
    {
        return;
    }
    if(m_length == 1)
    {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else
    {
        Node* temp = m_tail;
        m_tail = m_tail->prevNode;
        m_tail->nextNode = nullptr;

        delete temp;
    }

    m_length--;
}

auto doubly_linked_list::get(int index) -> Node*
{
    if(index < 0 || index >= m_length)
    {
        throw std::invalid_argument("Index out of bounds");
        return nullptr;
    }

    Node* temp = m_head;

    if(index / m_length / 2)
    {
        for(int i = 0; i < index; i++)
        {
            temp = temp->nextNode;
        }
    }
    else
    {
        temp = m_tail;
        for(int i = m_length - 1; i > index; i--)
        {
            temp = temp->prevNode;
        }
    }

    return temp;
}

auto doubly_linked_list::length() -> const int
{
    return m_length;
}

auto doubly_linked_list::get_head() -> const Node*
{
    return m_head;
}

auto doubly_linked_list::get_tail() -> const Node*
{
    return m_tail;
}
