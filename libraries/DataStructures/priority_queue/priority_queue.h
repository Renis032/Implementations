#pragma once

#include "../linked_list/linked_list.h"
#include <iostream>

namespace rsm
{

template <typename T>
class priority_queue
{
private:
struct Node
{
    Node(T value, int priority) : value(value), 
                                  priority(priority){}

    T value;
    int priority;
    Node* nextNode = nullptr;
};

public:
    priority_queue() : m_head(nullptr), m_tail(nullptr), m_length(0) {}
    priority_queue(T value, int priority)
    {
        Node* node = new Node(value, priority);
        node->priority = priority;
        m_head = node;
        m_tail = node;
        m_length = 1;
    }

    void push(T value, int priority)
    {
        Node* newNode = new Node(value, priority);
        newNode->priority = priority;
        if(m_head == nullptr)
        {
            m_head = newNode;
            m_tail = newNode;
        }
        else if(m_head->priority < priority)
        {
            newNode->nextNode = m_head;
            m_head = newNode;
        }
        else
        {
            Node* temp = m_head;
            while(temp->nextNode != nullptr &&
                  temp->nextNode->priority >= newNode->priority)
            {
                temp = temp->nextNode;
            }

            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
        }

        m_length++;
    }

    void dequeue()
    {
        if(get_length() == 0)
        {
            return;
        }

        if(get_length() == 1)
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_length--;
            return;
        }

        Node* firstNode = get_head();
        m_head = firstNode->nextNode;
        delete firstNode;

        m_length--;
    }

    void print_queue()
    {
        Node* temp = m_head;
        while(temp)
        {
            std::cout << "Value: " << temp->value << " Priority: " << temp->priority << std::endl;
            temp = temp->nextNode;
        }
    }

    
    bool empty()
    {
        return m_length == 0;
    }

    auto get_head() -> Node*
    {
        return m_head;
    }

    auto get_tail() -> Node*
    {
        return m_tail;
    }

    auto get_length() -> const int
    {
        return m_length;
    }

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_length = 0;
};

} // end of namespace rsm

