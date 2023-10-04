#include "binary_search_tree.h"

using namespace rsm;

binary_search_tree::binary_search_tree()
{
    m_root = nullptr;
}

void binary_search_tree::insert(int value)
{
    Node* newNode = new Node(value);
    if(nullptr == m_root)
    {
        m_root = newNode;
        return;
    }

    Node* temp = m_root;
    while(true)
    {
        if(temp->value == newNode->value)
        {
            return;
        }
        if(newNode->value < temp->value)
        {
            if(temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else if(newNode->value > temp->value)
        {
            if(temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

bool binary_search_tree::contains(int value)
{
    if(nullptr == m_root)
    {
        return false;
    }

    Node* temp = m_root;
    while(temp)
    {
        if(value == temp->value)
        {
            return true;
        }

        if(value < temp->value)
        {
            temp = temp->left;
        }
        else if(value > temp->value)
        {
            temp = temp->right;
        }
    }

    return false;
}

auto binary_search_tree::get_root() -> Node*
{
    return m_root;
}

