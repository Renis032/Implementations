#include <iostream>
#include "../queue/queue.h"

namespace rsm
{

template <typename T>
class binary_tree
{
private:
struct Node
{
private:
    Node(T value) : value(value){}

    Node* left = nullptr;
    Node* right = nullptr;
    T value;
};

public:
void insert(T value)
{
    Node* newNode = new Node(value);
    if(nullptr == get_root())
    {
        m_root = newNode;
        return;
    }

    Node* temp = get_root();
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
bool containsDFS(const T& value)
{
    if(nullptr == get_root())
    {
        return false;
    }

    Node* temp = get_root();
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

bool containsBFS(const T& value)
{
    if(nullptr == get_root())
    {
        return false;
    }

    rsm::queue<Node*> queue;
    queue.enqueue(m_root);

    while(!queue.empty())
    {
        Node* currentNode = queue.get_first()->value;
        queue.dequeue();

        if(currentNode->value == value)
        {
            return true;
        }

        if(nullptr != currentNode->left)
        {
            queue.enqueue(currentNode->left);
        }

        if(nullptr != currentNode->right)
        {
            queue.enqueue(currentNode->right);
        }
    }

    return false;
}

void invertTree(Node* node)
{
    if(nullptr == node)
    {
        return;
    }

    auto temp = node->left;
    node->left = node->right;
    node->right = temp;

    invertTree(node->left);
    invertTree(node->right);
}

void printDFS(Node* node) 
{
    if(nullptr == node)
    {
        return;
    }

    std::cout << node->value << std::endl;
    printDFS(node->left);
    printDFS(node->right);
}

void printBFS(Node* node) 
{
    if(nullptr == node)
    {
        return;
    }

    rsm::queue<Node*> queue;
    queue.enqueue(node);

    while(!queue.empty())
    {
        Node* currentNode = queue.get_first()->value;
        queue.dequeue();

        std::cout << currentNode->value << " ";

        if(currentNode->left)
        {
            queue.enqueue(currentNode->left);
        }

        if(currentNode->right)
        {
            queue.enqueue(currentNode->right);
        }
    }

    std::cout << std::endl; 
}

auto get_root() -> Node*
{
    return m_root;
}

private:
    Node* m_root = nullptr;
};

} // end of namespace rsm
